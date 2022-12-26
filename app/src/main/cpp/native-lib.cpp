#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "ActionBar"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_work_encasa_pendejo_kreijstaltest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject thiz) {
    jclass clazz = env->GetObjectClass(thiz);
    // Get the ID of the getSupportActionBar method
    jmethodID getSupportActionBarMethodId = env->GetMethodID(clazz, "getSupportActionBar", "()Landroidx/appcompat/app/ActionBar;");
    if (getSupportActionBarMethodId == 0) {
        LOGI("Failed to get getSupportActionBar method ID");
    }

    // Call the getSupportActionBar method to get a reference to the action bar
    jobject actionBar = env->CallObjectMethod(thiz, getSupportActionBarMethodId);
    if (actionBar == 0) {
        LOGI("Failed to get action bar");
    }

    // Get the ID of the hide method
    jclass actionBarClass = env->FindClass("androidx/appcompat/app/ActionBar");
    jmethodID hideMethodId = env->GetMethodID(actionBarClass, "hide", "()V");
    if (hideMethodId == 0) {
        LOGI("Failed to get hide method ID");
    }

    // Call the hide method to hide the action bar
    env->CallVoidMethod(actionBar, hideMethodId);
    std::string hello = "Hola Mundo";
    return env->NewStringUTF(hello.c_str());
}