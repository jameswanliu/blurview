#include <jni.h>
#include <string>
#include <cmath>
#include <android/bitmap.h>
#include <android/log.h>
#include "blur.h"

#define TAG "Native_Blur_Jni"
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_james_blurview_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT void JNICALL
Java_com_james_blurviewlib_BlurUtil_blurBitmap(JNIEnv *env, jclass jcls, jobject bitmap, jint r) {

    AndroidBitmapInfo androidBitmapInfo;

    void *pixles;

    if (AndroidBitmap_getInfo(env, bitmap, &androidBitmapInfo) !=
        ANDROID_BITMAP_RESULT_SUCCESS) {//获取bitmapinfo
        LOG_D("get bitmap info fail");
        return;
    }

    int32_t format = androidBitmapInfo.format;

    if (format != ANDROID_BITMAP_FORMAT_RGBA_8888 && format != ANDROID_BITMAP_FORMAT_RGB_565) {
        LOG_D("android format error");
        return;
    }

    if (AndroidBitmap_lockPixels(env, bitmap, &pixles) != ANDROID_BITMAP_RESULT_SUCCESS) {
        LOG_D("android bitmap lock fail");
        return;
    }


    int width = androidBitmapInfo.width;
    int height = androidBitmapInfo.height;


    if (format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        pixles = blur_ARGB_8888((int *) pixles, width, height, r);
    } else if (format == ANDROID_BITMAP_FORMAT_RGB_565) {
        pixles = blur_ARGB_565((short *) pixles, width, height, r);
    }
    AndroidBitmap_unlockPixels(env, bitmap);
}

