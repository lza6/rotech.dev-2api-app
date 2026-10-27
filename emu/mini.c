#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct { int tag; int len; void* p; } jobj;
static const char* SIGN_HEX = "3082058930820371a003020102021500d35a488404281bb910ad93994ce87595545fb3c6300d06092a864886f70d01010b05003074310b3009060355040613025553311330110603550408130a43616c69666f726e6961311630140603550407130d4d6f756e7461696e205669657731143012060355040a130b476f6f676c6520496e632e3110300e060355040b1307416e64726f69643110300e06035504031307416e64726f69643020170d3233303333313034333631355a180f32303533303333313034333631355a3074310b3009060355040613025553311330110603550408130a43616c69666f726e6961311630140603550407130d4d6f756e7461696e205669657731143012060355040a130b476f6f676c6520496e632e3110300e060355040b1307416e64726f69643110300e06035504031307416e64726f696430820222300d06092a864886f70d01010105000382020f003082020a0282020100b8c1a88119517b04bfccb1c0a0549e06245ccbf2eed130d6a3d2682aa5bb3270bf5b5d491e5f8591036516a2ef2ef74b32bc7db51637e9321f827f54a9457eaf865fbd702577f3d049564e10feddd2c5f24c2e0812f9f43fe07f2938d1dcd90667317daad89c99e989ba1668967129c91fea83f908975d763263ff8aad0bb1f4da42cacecb1e46f99b1c352c0b770b2df18bf5d79ecc14e81c249043e5c081040c1a8dc3f7f2b045712d194108435a010ebd4ca790d3ff38f507426b6f41f1f2b04be81f01187c7aab3425f91a972b2ba750c9fb3c7d624aab085f9c08b31c0da6c30f7ff0a65df875e70e5a1f420bdbaee257610850701b44ba7cbe3849ac118e4d4049f7d831cbb867a334d5f506ec56cdd13c7003186327ee0fcfda13973f682609cce29e7efcdc448c9b49ffb6bc96cd6cbfff4d145d2258a0883da66e048e65039f06469692e6c765558bbdc6f27e1ac2ca8244fe279269457be100c58196df8e67cc3f5f0bf49cb206441e5d1ca5e44d8be9e94e274d4ac59149e711b3c51604f3bb5138021c0cc83db1ab51765830f8bc17df16a411a792a6701bfbc947d6aa58ff7e590cd1b917ea534075fce22feebefb8de35a07b512eb059ea2693e5cdf0ecf3bb7b98cf45c89769c3ea35e0101efcff6650b68cccc823b34c079e3c4a63479537895dea194407e6d411131ccba4b2bd25ff40133aa60221e092d0203010001a310300e300c0603551d13040530030101ff300d06092a864886f70d01010b050003820201000de6632386dc399abf5c1e29b036e7748096b67ba32a910baa6f1eb6773bc96e2b009aa9768a2bbf63359a57263af28c12549a5037e958cf84d2f45935dc8d18edc4e6a44f3804f5476859b524ee3613ab0e3c840372eef8d26af4038adad892c08ae37c3938baec6a734f7ce61957f187ae1b26fe12e4ae6f033aa3dbad6c1af8f6f98eb3856dc29d3af666f48ed3fdf6b96101b3d2573f2bf72f332e82c3bb9758b0bd8486250892f42129599fc795fdf5f0b17eaa57abe405a323b2509b9a960e6e02fb63245a8152e0f770862c6ec757d4e6c167ebc4ebb95c3c4282ec17111b18a0250aeb522dcf3ec5cc49518f71a92e67562601824017be6d528dcb26e85456c5e0bb1852793dc734a0f42252d9770a034f6f28cae49dd8ce50e1ebc8bb2b4493267ee25d686ea3cdc93f0630875cc283aa847e2d974c407cd0ffb16b21d8f82b7e54607620fa38518868b3a0e509e337904a4cdf3cc937be05cdfc52fe5a3005018e04b9bd6f15471c444a5b010c9d4a1280a4f758f26f8a68e78039973f0ebdda1f152e4bcc3e75ee60fe7492fd74de17cdb2642f1fc19c3d34b0e5b2fc23e5fd5e36b9ca22caee91660b25c40665e0a9ef911bbcba0ad8afb435dcf9d172c531df2f5c662f894e4e61828aebbe6e76c742092048dfb348409c85951391528a9dee6580bd2f982d2bec583932824f0aa830b4666cd0edfbc372aa71";
static void* ENV[512];
static jobj* new_str(const char* s){ jobj* o=calloc(1,sizeof(jobj)); o->tag=1; o->p=strdup(s); o->len=strlen(s); return o; }

static const char* my_GetStringUTFChars(void* env, jobj* o, unsigned char* isCopy){ if(isCopy)*isCopy=0; return o&&o->tag==1?(char*)o->p:""; }
static void my_ReleaseStringUTFChars(void* env, jobj* o, const char* c){ }
static jobj* my_NewStringUTF(void* env, const char* s){ return new_str(s); }
static int my_GetArrayLength(void* env, jobj* o){ return o?o->len:0; }
static jobj* my_NewByteArray(void* env, int len){ jobj* o=calloc(1,sizeof(jobj)); o->tag=2; o->len=len; o->p=calloc(len?len:1,1); return o; }
static void my_GetByteArrayRegion(void* env, jobj* o, int start, int len, void* buf){ if(o&&o->tag==2) memcpy(buf,(char*)o->p+start,len); }
static void my_SetByteArrayRegion(void* env, jobj* o, int start, int len, void* buf){ if(o&&o->tag==2) memcpy((char*)o->p+start,buf,len); }
static void my_GetStringRegion(void* env, jobj* o, int s, int l, unsigned short* buf){ if(o&&o->tag==1){ const unsigned char* p=o->p; for(int i=0;i<l&&s+i<o->len;i++) buf[i]=p[s+i]; } }
static void* my_GetStringChars(void* env, const unsigned short* chars, int len, void* a3){
    // NewString(env, jchar* chars, jsize len)
    if(!chars || len<=0) return new_str("");
    jobj* o = calloc(1,sizeof(jobj));
    o->tag=1; o->len=len;
    o->p = malloc(len+1);
    for(int i=0;i<len;i++) ((char*)o->p)[i] = (char)(chars[i] & 0xff);
    ((char*)o->p)[len]=0;
    return o;
}
static const unsigned short* my_GetStringChars_old_unused(void* env, void* o_, unsigned char* isCopy){
    jobj* o=(jobj*)o_;
    if(isCopy)*isCopy=0;
    if(!o) return (const unsigned short*)"";
    // tag/len 读前先试探：jobj 的 tag 必须是 1 或 2，len 合理
    if(o->tag!=1 && o->tag!=2) return (const unsigned short*)"";
    if(o->len<0 || o->len>1000000) return (const unsigned short*)"";
    static unsigned short tmp[100001];
    unsigned char* p=o->p;
    if(o->tag==1){ for(int i=0;i<o->len;i++) tmp[i]=p[i]; tmp[o->len]=0; }
    else { for(int i=0;i<o->len;i++) tmp[i]=((unsigned char*)o->p)[i]; tmp[o->len]=0; }
    return tmp;
}
static void my_ReleaseStringChars(void* env, jobj* o, const unsigned short* c){ }
static unsigned char my_ExceptionCheck(void* env){ return 0; }
static void* my_ExceptionOccurred(void* env){ return 0; }
static void* my_FindClass(void* env, const char* name){ return new_str(name); }
static void* my_GetObjectClass2(void* env, void* o){ return new_str("cls2"); }
static void* my_GetFieldID(void* env, void* c, const char* n, const char* s){ return (void*)0x92; }
static void* my_GetObjectField(void* env, void* o, void* f){ return new_str("fld"); }
static void* my_GetStaticMethodID(void* env, void* c, const char* name, const char* sig){ return (void*)0x99; }
static void* my_CallStaticObjectMethod(void* env, void* c, void* m){ fprintf(stderr,"[C] CSOM mid=%p\n", m); return new_str("sig"); }
static void* my_GetObjectClass(void* env, void* o){ return new_str("cls"); }
static void* my_GetMethodID(void* env, void* c, const char* n, const char* s){ return (void*)0x98; }
static void* my_GetMethodID2(void* env, void* c, const char* n, const char* s){ return (void*)0x98; }
static void* my_CallObjectMethodLog(void* env, void* o, void* m){ return new_str("called"); }
static void* my_NewObject(void* env, void* cls, void* mid, ...){
    // so 把返回对象的内部存储当 char 缓冲直接写（JNI String 内部结构）
    // 分配大缓冲：布局模拟 [tag][cap][data...]
    jobj* o = calloc(1, sizeof(jobj) + 100000);
    o->tag = 1; o->len = 0; o->p = (char*)o + sizeof(jobj);   // data 内嵌
    return o;
}
static void* my_NewStringFromChars(void* env, const unsigned short* chars, int len){ char* b=malloc(len+1); for(int i=0;i<len;i++) b[i]=(char)chars[i]; b[len]=0; jobj* o=new_str(b); free(b); return o; }
static int g_com_count = 0;
static void* my_CallObjectMethod(void* env, void* o, void* m){ g_com_count++; if (g_com_count >= 4) return new_str(SIGN_HEX); return new_str("open.chat.gpt.aichat.bot.free.app"); }
static int my_PushLocalFrame(void* env, int n){ return 0; }
static void* my_PopLocalFrame(void* env, void* r){ return r; }
static void* my_NewGlobalRef(void* env, void* o){ return o; }
static void my_DeleteGlobalRef(void* env, void* o){}
static void my_DeleteLocalRef(void* env, void* o){}
static void* my_GetStaticFieldID(void* env, void* c, const char* n, const char* s){ return (void*)0x96; }
static void* my_GetStaticObjectField(void* env, void* c, void* f){ return new_str(SIGN_HEX); }
static void* my_GetObjectArrayElement(void* env, void* a, int i){ return new_str("elem"); }
static void my_SetObjectArrayElement(void* env, void* a, int i, void* v){}

int main(int argc, char** argv) {
    void* h = dlopen(argv[1], RTLD_NOW); if (!h) return 1;
    ENV[6]=(void*)my_FindClass;
    ENV[31]=(void*)my_GetObjectClass2;
    ENV[94]=ENV[94];
    ENV[19]=(void*)my_ExceptionOccurred;
    ENV[23]=(void*)my_PushLocalFrame;
    ENV[24]=(void*)my_PopLocalFrame;
    ENV[25]=(void*)my_NewGlobalRef;
    ENV[26]=(void*)my_DeleteGlobalRef;
    ENV[27]=(void*)my_DeleteLocalRef;
    ENV[32]=(void*)my_GetMethodID;
    ENV[33]=(void*)my_GetMethodID2;
    ENV[34]=(void*)my_CallObjectMethod;
    ENV[94]=(void*)my_GetStaticFieldID;
    ENV[95]=(void*)my_GetStaticObjectField;
    ENV[113]=(void*)my_GetStaticMethodID;
    ENV[114]=(void*)my_CallStaticObjectMethod;
    ENV[115]=(void*)my_GetStaticObjectField;
    ENV[167]=(void*)my_NewStringUTF;
    ENV[169]=(void*)my_GetStringUTFChars;
    ENV[170]=(void*)my_ReleaseStringUTFChars;
    ENV[171]=(void*)my_GetArrayLength;
    ENV[173]=(void*)my_GetObjectArrayElement;
    ENV[174]=(void*)my_SetObjectArrayElement;
    ENV[176]=(void*)my_NewByteArray;
    ENV[208]=(void*)my_GetByteArrayRegion;
    ENV[28]=(void*)my_NewObject;
    ENV[29]=(void*)my_NewObject;
    ENV[30]=(void*)my_NewObject;
    ENV[200]=(void*)my_GetByteArrayRegion;
    ENV[200]=(void*)my_GetByteArrayRegion;
    ENV[201]=(void*)my_SetByteArrayRegion;
    ENV[207]=(void*)my_GetStringRegion;
    ENV[163]=(void*)my_GetStringChars;
    ENV[162]=(void*)my_GetArrayLength;
    ENV[161]=(void*)my_GetArrayLength;
    ENV[161]=(void*)my_GetStringChars;
    ENV[165]=(void*)my_NewStringFromChars;
    ENV[164]=(void*)my_GetArrayLength;
    ENV[166]=(void*)my_GetArrayLength;
    ENV[167]=(void*)my_NewStringUTF;
    ENV[162]=(void*)my_GetArrayLength;
    ENV[228]=(void*)my_ExceptionCheck;
    void** envptr[1] = { (void**)ENV };
    void* (*getAll)(void*, void*, void*, void*) = dlsym(h, "Java_dev_rotech_decode_Decoder_getAllJsonNative");
    jobj* path = new_str("ec/role/zh_CN");
    void* r = getAll(envptr, NULL, NULL, path);
    if (r) {
        jobj* o = (jobj*)r;
        if (o->tag == 1) {
            FILE* f = fopen("result.txt", "wb");
            fwrite(o->p, 1, o->len, f);
            fclose(f);
            printf("RESULT_SAVED %d\n", o->len);
        } else {
            puts("r-not-str");
        }
    } else {
        puts("r=NULL");
    }
    return 0;
}
