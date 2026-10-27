// Minimal libandroid.so stub: only what librocore.so needs (AAsset* API)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AAsset { FILE* fp; long len; };
struct AAssetManager { const char* base; };

int AAsset_openFileDescriptor64(void* a, void* s, void* o) { return -1; }
struct AAsset* AAssetManager_open(struct AAssetManager* mgr, const char* name, int mode) {
    // assets 从当前目录 assets/ 读取
    char path[1024];
    snprintf(path, sizeof(path), "assets/%s", name);
    FILE* fp = fopen(path, "rb");
    if (!fp) return NULL;
    struct AAsset* a = malloc(sizeof(*a));
    a->fp = fp;
    fseek(fp, 0, SEEK_END); a->len = ftell(fp); fseek(fp, 0, SEEK_SET);
    fprintf(stderr, "[stub] AAssetManager_open: %s (%ld bytes)\n", name, a->len);
    return a;
}
long AAsset_getLength(struct AAsset* a) { return a->len; }
long AAsset_getLength64(struct AAsset* a) { return a->len; }
int AAsset_read(struct AAsset* a, void* buf, size_t size) {
    return (int)fread(buf, 1, size, a->fp);
}
void AAsset_close(struct AAsset* a) { fclose(a->fp); free(a); }
struct AAssetManager* AAssetManager_fromJava(void* env, void* mgr) {
    static struct AAssetManager m = { "." };
    return &m;
}
