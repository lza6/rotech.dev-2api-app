// mini JNIEnv: 只实现 decryptDataAndConvertToString 用到的少量 JNI 函数
// 调用链: readFile(env, ?, jstring path) 里 AAsset 已由 libandroid_stub 处理
// 我们直接调 decryptDataAndConvertToString(env, jbyteArray?, jstring?, key)
// —— 但它的参数经过 NewStringUTF 等转换。更稳妥: 自己走完整链:
//   getAllJsonNative(env, cls, assetManager_jobj, path_jstr)
// 需要的 JNI 函数: GetStringUTFChars(idx169=0x548), ReleaseStringUTFChars(0x550),
//   GetArrayLength(0x580), GetByteArrayRegion? (0x640=200 = GetByteArrayRegion? 0x680=208)
// 精确: 0x548/8=169 GetStringUTFChars? JNI 表: 167 NewStringUTF, 168 GetStringUTFLength,
//   169 GetStringUTFChars, 170 ReleaseStringUTFChars ✔ (0x548=169*8 ✔ 0x550=170*8 ✔)
//   0x580=176 GetArrayLength ✔ 0x640=200 GetObjectArrayElement? 实际 GetByteArrayRegion=199*8=0x638..
//   JNI 真实序号: GetBooleanArrayRegion=199..GetByteArrayRegion=201(0x648), 200=GetCharArrayRegion(0x640)!!
//   0x680=208 GetStringRegion ✔ (GetStringRegion=207? 207*8=0x638, 208=GetStringUTFRegion 0x680)
// decryptDataAndConvertToString 里 0x538=167 NewStringUTF, 0x528=165 NewObject? (164=NewObject 0x520, 165=NewObjectV 0x528, 166=NewObjectA)
//   3434: env+0x528=NewObjectV? 用 (env, x21, x2=0)... x21 是 jclass? 这函数逻辑:
//   3334 FindClass("java/lang/String") -> x22
//   3358 GetMethodID(env, x22, name=0x??(0xea0区), sig=0xe7c) -> x23   (找 String.<init>?)
//   3378 NewStringUTF(env, "") -> x24
//   3394 GetArrayLength(env, x21) -> x25   [x21 是 jbyteArray]
//   33b8 GetByteArrayRegion? 0x680=GetStringUTFRegion.. 但 x21 是 byte array → 应为 0x648 GetByteArrayRegion
//   capstone 33d4: ldr x8,[x8,#0x680]?? 之前读的: 33b8 ldr x26,[x8,#0x680]; 33d4 blr x26
//   0x680/8=208 → 207=GetStringRegion, 208=GetStringUTFRegion?? 官方: 165 NewObjectV.. 让我用标准表:
//   171 NewBooleanArray ... 175 NewByteArray=176? 不,NewByteArray=176?
//   标准 JNI: NewBooleanArray 171, NewByteArray 172, NewCharArray 173, NewShortArray 174, NewIntArray 175,
//   NewLongArray 176, NewFloatArray 177, NewDoubleArray 178, GetBooleanArrayElements 179...
//   Hmm 0x580=176=NewLongArray?? 不对。另一张表: GetArrayLength=171。
//   我数错了。不猜了——直接实验: mini env 每个槽都填上,按被调用的偏移打印,再针对性实现。见 host2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

static void* ENV[512]; // JNIEnv 函数表 (指针数组)
static void** env = ENV;

// 简单对象模型: byte array = {len, data*}
typedef struct { int len; unsigned char* d; } jarr;
typedef struct { char* s; } jstr;

static void* jni_stub(void) { fprintf(stderr, "[jni] UNIMPLEMENTED CALLED\n"); abort(); }

// 已知槽位记录
static int slot_log[512];

int main(int argc, char** argv) {
    void* h = dlopen(argv[1], RTLD_NOW);
    if (!h) { printf("dlopen: %s\n", dlerror()); return 1; }
    // 先探测它调哪些 JNI 槽：把 ENV 全填 jni_stub，运行时打印被调偏移？需要 wrapper per slot。
    // 简化：直接填 0，signal handler 抓 SIGSEGV 地址算偏移。
    // 更简单：先把 getAllJsonNative 的参数准备好，然后 hook signal。
    void* fn = dlsym(h, "getAllJsonNative");
    printf("getAllJsonNative=%p\n", fn);
    return 0;
}
