// OpenChat_Premium 协议 Mock 服务器（本地压测用，不访问任何真实第三方服务）
// 协议还原自 APK 静态分析：
//   POST /api/v5/chat/common_question
//   POST /api/v5/chat/role_question
//   body: form-urlencoded, 字段 data = Base64( AES-256-CBC( JSON, key=md5hex(sig)[0:16], iv=md5hex(sig)[16:32] ) )
//   其他字段: pkg / modetype / version
const http = require('http');
const crypto = require('crypto');
const { URL } = require('url');

const PORT = parseInt(process.env.MOCK_PORT || '8787', 10);

// 与 APK 相同的密钥派生逻辑（示例签名串，客户端 demo 页用同一算法即可互通）
const SIGNATURE = 'demo-signature-for-local-load-testing';
function deriveKeys() {
  const md5hex = crypto.createHash('md5').update(SIGNATURE, 'utf8').digest('hex');
  return { key: md5hex.slice(0, 16), iv: md5hex.slice(16, 32) };
}
const { key, iv } = deriveKeys();

function decryptData(b64) {
  try {
    const decipher = crypto.createDecipheriv('aes-128-cbc', Buffer.from(key, 'utf8'), Buffer.from(iv, 'utf8'));
    const dec = Buffer.concat([decipher.update(Buffer.from(b64, 'base64')), decipher.final()]);
    return JSON.parse(dec.toString('utf8'));
  } catch (e) {
    return { __decryptError: e.message };
  }
}

function encryptData(obj) {
  const cipher = crypto.createCipheriv('aes-128-cbc', Buffer.from(key, 'utf8'), Buffer.from(iv, 'utf8'));
  return Buffer.concat([cipher.update(Buffer.from(JSON.stringify(obj), 'utf8')), cipher.final()]).toString('base64');
}

// 简单玩具回复（模拟流式聚合后的完整响应，与原 app 的 answer 字段对应）
function fakeAnswer(q) {
  return `[mock] 你问的是: ${String(q).slice(0, 120)}。这是本地压测 mock 的回答。`;
}

// ---------- 统计（压测数据源） ----------
const stats = {
  startedAt: Date.now(),
  endpoints: {},   // path -> {count, errors, sumMs, maxMs, codes:{}}
};
function record(path, ms, code, err) {
  const s = (stats.endpoints[path] ||= { count: 0, errors: 0, sumMs: 0, maxMs: 0, codes: {} });
  s.count++; s.sumMs += ms; s.maxMs = Math.max(s.maxMs, ms);
  s.codes[code] = (s.codes[code] || 0) + 1;
  if (err) s.errors++;
}

const server = http.createServer((req, res) => {
  const t0 = Date.now();
  const u = new URL(req.url, 'http://localhost');
  const path = u.pathname;
  let body = '';
  req.on('data', (c) => { body += c; if (body.length > 5 * 1024 * 1024) req.destroy(); });
  req.on('end', () => {
    const params = new URLSearchParams(body);
    const dataField = params.get('data') || u.searchParams.get('data') || '';
    const payload = dataField ? decryptData(dataField) : {};

    const done = (code, obj, encrypt = true) => {
      const out = encrypt ? { code: 200, data: encryptData(obj) } : { code, ...obj };
      res.writeHead(200, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify(out));
      record(path, Date.now() - t0, code, payload.__decryptError);
    };

    if (path === '/api/v5/chat/common_question' || path === '/api/v5/chat/role_question') {
      if (payload.__decryptError) return done(400, { msg: 'decrypt failed: ' + payload.__decryptError }, false);
      const answer = fakeAnswer(payload.question);
      return done(200, { answer, question_id: crypto.randomUUID(), model: payload.model || 'gpt-4o-mini' });
    }
    if (path === '/api/v5/text2img/gen_image') {
      return done(200, { task_id: crypto.randomUUID(), status: 'processing' });
    }
    if (path === '/api/v5/text2img/get_task_by_id') {
      return done(200, { status: 'success', url: 'http://localhost:8787/mock.png' });
    }
    if (path === '/stats') {
      res.writeHead(200, { 'Content-Type': 'application/json' });
      return res.end(JSON.stringify({ ...stats, keyPreview: key + ':' + iv, uptimeMs: Date.now() - stats.startedAt }));
    }
    if (path === '/reset') {
      stats.endpoints = {};
      res.writeHead(200, { 'Content-Type': 'application/json' });
      return res.end('{"ok":true}');
    }
    res.writeHead(404); res.end('not found');
  });
});

server.listen(PORT, () => {
  console.log(`[mock] listening on http://127.0.0.1:${PORT}`);
  console.log(`[mock] AES key=${key} iv=${iv} (derived from md5 of demo signature)`);
});
