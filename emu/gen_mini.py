NL = chr(92) + 'n'  # literal backslash-n for C strings
c = '''#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct { int tag; int len; void* p; } jobj;
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
static unsigned char my_ExceptionCheck(void* env){ return 0; }
static void* my_ExceptionOccurred(void* env){ return 0; }
static void* my_FindClass(void* env, const char* name){ return new_str(name); }
static void* my_GetStaticMethodID(void* env, void* c, const char* name, const char* sig){ return (void*)0x99; }
static void* my_CallStaticObjectMethod(void* env, void* c, void* m){ return new_str("open.chat.gpt.aichat.bot.free.app"); }
static void* my_GetObjectClass(void* env, void* o){ return new_str("cls"); }
static void* my_GetMethodID(void* env, void* c, const char* n, const char* s){ return (void*)0x98; }
static void* my_CallObjectMethod(void* env, void* o, void* m){ return new_str("pkg"); }
static int my_PushLocalFrame(void* env, int n){ return 0; }
static void* my_PopLocalFrame(void* env, void* r){ return r; }
static void* my_NewGlobalRef(void* env, void* o){ return o; }
static void my_DeleteGlobalRef(void* env, void* o){}
static void my_DeleteLocalRef(void* env, void* o){}
static void* my_GetStaticFieldID(void* env, void* c, const char* n, const char* s){ return (void*)0x96; }
static void* my_GetStaticObjectField(void* env, void* c, void* f){ return new_str("cert"); }
static void* my_GetObjectArrayElement(void* env, void* a, int i){ return new_str("elem"); }
static void my_SetObjectArrayElement(void* env, void* a, int i, void* v){}

int main(int argc, char** argv) {
    void* h = dlopen(argv[1], RTLD_NOW); if (!h) return 1;
    ENV[6]=(void*)my_FindClass;
    ENV[19]=(void*)my_ExceptionOccurred;
    ENV[23]=(void*)my_PushLocalFrame;
    ENV[24]=(void*)my_PopLocalFrame;
    ENV[25]=(void*)my_NewGlobalRef;
    ENV[26]=(void*)my_DeleteGlobalRef;
    ENV[27]=(void*)my_DeleteLocalRef;
    ENV[32]=(void*)my_GetMethodID;
    ENV[33]=(void*)my_CallObjectMethod;
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
    ENV[200]=(void*)my_GetByteArrayRegion;
    ENV[201]=(void*)my_SetByteArrayRegion;
    ENV[207]=(void*)my_GetStringRegion;
    ENV[163]=(void*)my_GetStringRegion;
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
            printf("RESULT_SAVED %d''' + NL + '''", o->len);
        } else {
            puts("r-not-str");
        }
    } else {
        puts("r=NULL");
    }
    return 0;
}
'''
open('C:/Users/Administrator.DESKTOP-EGNE9ND/Desktop/openchat-lab/emu/mini.c','w',encoding='utf-8').write(c)
print('rewritten clean')
