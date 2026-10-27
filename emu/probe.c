// 运行时探测: 512 个槽全部指向同一个 trampoline? 不行,要打印槽号。
// 用 code-gen: 生成 512 个函数
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>

static void segv(int sig, siginfo_t* si, void* uc) {
    // ENV 是全局数组, si->si_addr 落在 ENV 内 → 槽号 = (addr - ENV)/8
    extern char ENV_START;
    ucontext_t* u = (ucontext_t*)uc;
    // x8 保存被 load 的表地址+偏移? aarch64 里 ldr x8,[x8,#off] 崩在访存,si_addr = ENV+off
    fprintf(stderr, "[probe] SEGV at %p\n", si->si_addr);
    _exit(2);
}
int main(int argc, char** argv) {
    void* h = dlopen(argv[1], RTLD_NOW);
    if (!h) { printf("dlopen: %s\n", dlerror()); return 1; }
    struct sigaction sa = {0};
    sa.sa_sigaction = segv; sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);
    // ENV 数组全 0
    static void* ENV[512];
    void** env = ENV;
    void* (*getAll)(void*, void*, void*, void*) = dlsym(h, "getAllJsonNative");
    // 调用: (env, jclass, assetManager, pathString) — path 用真实 asset "ec/role/zh_CN"
    // GetStringUTFChars 需要真实现,否则 path 取不出。此探测轮先看崩在哪。
    void* r = getAll(env, NULL, NULL, NULL);
    printf("returned %p\n", r);
    return 0;
}
