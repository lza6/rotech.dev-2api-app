#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <setjmp.h>

#define FWD(ret, name, args...) \
  ret name(args) { \
    static ret (*real)(args) = 0; \
    if (!real) real = dlsym(RTLD_NEXT, #name); \
    return real(args); \
  }
// FWD 宏对多参数签名不通用，手写每个：
size_t __strlen_chk(const char* s, size_t n) { return strlen(s); }
char* __strncat_chk(char* d, const char* s, size_t n, size_t dn) { return strncat(d, s, n); }
int __vsprintf_chk(char* d, int f, size_t dn, const char* fmt, va_list ap) { return vsprintf(d, fmt, ap); }
void __stack_chk_fail(void) { abort(); }
int __register_atfork(void (*a)(void), void(*b)(void), void(*c)(void), void* d) { return 0; }
int __cxa_atexit(void (*f)(void*), void* a, void* d) { return 0; }
void __cxa_finalize(void* d) {}

void* malloc(size_t n) { static void*(*r)(size_t)=0; if(!r) r=dlsym(RTLD_NEXT,"malloc"); return r(n); }
void free(void* p) { static void(*r)(void*)=0; if(!r) r=dlsym(RTLD_NEXT,"free"); r(p); }
void* realloc(void* p, size_t n) { static void*(*r)(void*,size_t)=0; if(!r) r=dlsym(RTLD_NEXT,"realloc"); return r(p,n); }
void* calloc(size_t a, size_t b) { static void*(*r)(size_t,size_t)=0; if(!r) r=dlsym(RTLD_NEXT,"calloc"); return r(a,b); }
void* memcpy(void* d, const void* s, size_t n) { unsigned char* dd=d; const unsigned char* ss=s; while(n--) *dd++=*ss++; return d; }
void* memset(void* d, int c, size_t n) { unsigned char* dd=d; while(n--) *dd++=(unsigned char)c; return d; }
size_t strlen(const char* s) { const char* p=s; while(*p) p++; return p-s; }
int strcmp(const char* a, const char* b) { while(*a && *a==*b) a++,b++; return (unsigned char)*a-(unsigned char)*b; }
char* strncpy(char* d, const char* s, size_t n) { char* r=d; while(n-- && (*d++=*s++)); return r; }
char* strcat(char* d, const char* s) { char* p=d; while(*p) p++; while((*p++=*s++)); return d; }
char* strchr(const char* s, int c) { for(; *s; s++) if(*s==(char)c) return (char*)s; return (c==0)?(char*)s:0; }
char* strstr(const char* h, const char* n) { for(; *h; h++) { const char* a=h,*b=n; while(*a && *b && *a==*b) a++,b++; if(!*b) return (char*)h; } return 0; }
int ferror(FILE* f) { static int(*r)(FILE*)=0; if(!r) r=dlsym(RTLD_NEXT,"ferror"); return r(f); }
size_t fread(void* p, size_t s, size_t n, FILE* f) { static size_t(*r)(void*,size_t,size_t,FILE*)=0; if(!r) r=dlsym(RTLD_NEXT,"fread"); return r(p,s,n,f); }
int fclose(FILE* f) { static int(*r)(FILE*)=0; if(!r) r=dlsym(RTLD_NEXT,"fclose"); return r(f); }
FILE* fopen(const char* p, const char* m) { static FILE*(*r)(const char*,const char*)=0; if(!r) r=dlsym(RTLD_NEXT,"fopen"); return r(p,m); }
char* fgets(char* s, int n, FILE* f) { static char*(*r)(char*,int,FILE*)=0; if(!r) r=dlsym(RTLD_NEXT,"fgets"); return r(s,n,f); }
int getpid(void) { static int(*r)(void)=0; if(!r) r=dlsym(RTLD_NEXT,"getpid"); return r(); }
extern int __sigsetjmp(jmp_buf b, int savemask);

