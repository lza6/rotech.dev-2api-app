// 调用链完整复刻：AAssetManager_fromJava -> AAssetManager_open(role/zh_CN) -> read bytes
// -> 直接调 so 导出的 lilllilili (custom b64?) 或 decryptDataAndConvertToString（需要 env，跳过）
// 替代策略：readFile JNI 版本不可调；但 so 里 readall(fp, &out, &len) 是纯 C！readFile 内部走 readall。
// 而真正解密 decryptDataAndConvertToString 是 JNI。它的纯算法部分 = UTF16 XOR。
// 但等等——so 还导出 decodeString/decodeBytes 等。先枚举全部导出，把纯 C 的都试一遍。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(int argc, char** argv) {
    void* h = dlopen(argv[1], RTLD_NOW);
    if (!h) { printf("dlopen: %s\n", dlerror()); return 1; }
    // readall: (FILE*, char**, size_t*) -> long
    long (*readall)(FILE*, char**, size_t*) = dlsym(h, "readall");
    printf("readall=%p\n", (void*)readall);
    if (readall) {
        FILE* fp = fopen(argv[2], "rb");
        if (fp) {
            char* out = NULL; size_t len = 0;
            long r = readall(fp, &out, &len);
            printf("readall ret=%ld len=%zu first16=%02x%02x%02x%02x\n", r, len, out ? (unsigned char)out[0] : 0, out ? (unsigned char)out[1] : 0, out ? (unsigned char)out[2] : 0, out ? (unsigned char)out[3] : 0);
            if (out) free(out);
            fclose(fp);
        }
    }
    return 0;
}
