#include <jni.h>
#include <string>
#include "android/log.h"
#include "dobby.h"

void *(*old_srtsrt)(char*, char*) = nullptr;

void *new_strstr(char *a1, char *a2) {
    __android_log_print(6, "Ainkom->", "hook strstr");
    void *result = old_srtsrt(a1, a2);
    return result;
}


jint JNI_OnLoad(JavaVM *vm, void *unused){
    __android_log_print(6, "Ainkom->", "插件 so 文件注入成功");
    void *strstrAddr = DobbySymbolResolver("/system/lib64/libc.so", "strstr", nullptr);
    DobbyHook(strstrAddr, (void *) new_strstr, (void **) &old_srtsrt);
    __android_log_print(6, "Ainkom->", "strstr 注入成功");
    return JNI_VERSION_1_6;
}