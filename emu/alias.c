#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

extern void* malloc; void* __alias_malloc __attribute__((alias("malloc")));
extern void* free; void* __alias_free __attribute__((alias("free")));
extern void* realloc; void* __alias_realloc __attribute__((alias("realloc")));
extern void* calloc; void* __alias_calloc __attribute__((alias("calloc")));
extern void* memcpy; void* __alias_memcpy __attribute__((alias("memcpy")));
extern void* memset; void* __alias_memset __attribute__((alias("memset")));
extern void* strlen; void* __alias_strlen __attribute__((alias("strlen")));
extern void* strcmp; void* __alias_strcmp __attribute__((alias("strcmp")));
extern void* strncpy; void* __alias_strncpy __attribute__((alias("strncpy")));
extern void* strcat; void* __alias_strcat __attribute__((alias("strcat")));
extern void* strchr; void* __alias_strchr __attribute__((alias("strchr")));
extern void* strstr; void* __alias_strstr __attribute__((alias("strstr")));
extern void* ferror; void* __alias_ferror __attribute__((alias("ferror")));
extern void* fread; void* __alias_fread __attribute__((alias("fread")));
extern void* fclose; void* __alias_fclose __attribute__((alias("fclose")));
extern void* fopen; void* __alias_fopen __attribute__((alias("fopen")));
extern void* fgets; void* __alias_fgets __attribute__((alias("fgets")));
extern void* getpid; void* __alias_getpid __attribute__((alias("getpid")));