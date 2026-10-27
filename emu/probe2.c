// 最终版：完整 mini-JNIEnv，运行时打印所有被调用的 JNI 槽位
// ENV[0..3] reserved; 其余全部填 "打印槽号+abort" 的 trampoline —— 用宏生成有槽号信息的函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

static void** env_table;

// 槽位记录器: 每个槽一个函数，打印槽号后退出
#define SLOT_FN(n) \
  static void* fn_slot_##n(void) { fprintf(stderr, "[jni] slot %d (0x%x) called -> offset 0x%x\n", n, n*8, n*8); exit(3); }
SLOT_FN(6) SLOT_FN(167) SLOT_FN(169) SLOT_FN(170) SLOT_FN(171) SLOT_FN(176)
// 通用 fallback 不行（不知道槽号），所以预生成一段:
#define FN(n) fn_slot_##n
static void* ENV[512] = {
  [6] = (void*)FN(6), [167]=(void*)FN(167), [169]=(void*)FN(169), [170]=(void*)FN(170),
  [171]=(void*)FN(171), [176]=(void*)FN(176),
};
int main(int argc, char** argv) {
    void* h = dlopen(argv[1], RTLD_NOW);
    if (!h) { printf("dlopen: %s\n", dlerror()); return 1; }
    env_table = ENV;
    void** env = ENV;
    void* (*getAll)(void*, void*, void*, void*) = dlsym(h, "getAllJsonNative");
    // 传入真实参数: assetManager = NULL (stub 会处理), path = jstr 结构
    // 但 GetStringUTFChars(169) 会先被调 —— 它在表里是我们的探针 → 第一个被调的槽会打印出来
    void* r = getAll(env, NULL, NULL, (void*)0x1234);
    printf("returned %p\n", r);
    return 0;
}
