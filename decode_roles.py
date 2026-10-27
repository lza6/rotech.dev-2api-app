# OpenChat_Premium role asset decoder (reverse-engineered)
# algo: per-byte chars; even-index chars XOR key[(i//2)%6] where key="9a8d7F"
#       (first 6 bytes of "9a8d7FvZUCRUpQpe"); XOR result 0 -> keep cipher byte (asm cbz);
#       trailing padding chars after JSON end.
import json, sys, glob, os
KEY = b'9a8d7F'
def decrypt(data: bytes) -> str:
    out = []
    for i in range(0, len(data), 2):
        r = i // 2
        x = data[i] ^ KEY[r % 6]
        out.append(x if x != 0 else data[i])
        if i + 1 < len(data):
            out.append(data[i+1])
    s = ''.join(chr(c) for c in out)
    dec = json.JSONDecoder()
    last = None
    for strip in range(4):
        body = s[:len(s)-strip] if strip else s
        for suffix in ['', '}', ']}', '}]', '}]}', ']}}']:
            try:
                obj, end = dec.raw_decode(body + suffix)
                if (isinstance(obj, list) and len(obj) >= 5) or (isinstance(obj, dict) and len(obj) >= 3):
                    return json.dumps(obj, ensure_ascii=False, indent=1)
            except Exception as e:
                last = e
    raise ValueError(f'not a role json: {last}')
if __name__ == '__main__':
    for f in (sys.argv[1:] or glob.glob(sys.argv[0].replace('decode_roles.py','') + '*')):
        data = open(f, 'rb').read()
        print(f, '->', decrypt(data)[:200])
