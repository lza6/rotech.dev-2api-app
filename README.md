# rotech.dev-2api-app — OpenChat (gptapi.rotech.dev) 协议逆向研究

OpenChat_Premium.apk（gptapi.rotech.dev）安卓应用协议逆向研究：API 端点还原、AES 加密层分析、librocore.so 资产解密算法还原、本地网页 Demo 与压测。仅供安全研究与学习。

## 核心成果

### 1. 请求协议（AES-128-CBC）

```
POST https://gptapi.rotech.dev/api/v5/chat/common_question
Content-Type: application/x-www-form-urlencoded
pkg=open.chat.gpt.aichat.bot.free.app&modetype=1&version=1.3.4&data=<Base64(AES(json))>

json = {uuid, gp_token:'', conversation_sign:'{uuid}_{ms}', timestamp, question, lang, model:'auto', length:'auto', style:'auto'}
响应: {code:200, data:<Base64(AES({code:0, content, id}))>}
```

密钥派生：`md5hex(签名证书DER hex)` → Key=前16字节 / IV=后16字节。
真实（release）签名派生值：**Key=`8a678654d5872049` IV=`60f88b97a8896ec5`**。

### 2. librocore.so 角色库解密算法（本仓库新还原）

`assets/ec/role/<lang>`（14 个角色的 prompt/推荐问题库，23 种语言）：

```
偶数索引 char XOR key[(i/2) mod 6]，key = "9a8d7F"（"9a8d7FvZUCRUpQpe" 前 6 字节）
XOR 结果为 0 时保留密文原字节（汇编 cbz 跳过 store）
JSON 结束后带少量 padding 字符
```

解密产物见 [`roles_decrypted/`](roles_decrypted/) — 23 语言 × 14 角色（AI女友/AI男友/厨师/健身教练/占卜师/心理咨询师/家庭医生等）。

### 3. APK 为二次打包破解版

内置 `ApkSignatureKillerEx`（origin.apk + Lsposed HiddenApiBypass），"Premium" 为签名绕过壳。

## 文件结构

| 路径 | 说明 |
|---|---|
| `报告.md` | 完整逆向报告（两轮：协议 + librocore.so） |
| `decode_roles.py` | 角色库通用解码器 |
| `roles_decrypted/` | 23 语言解密后的角色 JSON |
| `demo.html` + `mock-server.cjs` | 本地 mock + 网页 demo（压测 200req p50=4.6ms） |
| `emu/` | qemu-aarch64 + mini-JNIEnv 动态执行环境 |
| `角色解密验证.txt` | zh_CN 角色清单验证 |

## 方法论

- qemu-aarch64 用户态模拟 + stub libandroid/liblog/libc（RTLD_NEXT 转发）直接执行 native 解密函数
- capstone 静态反汇编交叉确认 XOR 循环语义（umulh magic 除法 = mod 6）
- ELF PLT/GOT 重定位解析定位 PLT 桩对应的真实函数

仅供安全研究与学习，请勿用于任何违法用途。
