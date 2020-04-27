#include <jni.h>
#include <string>

#define LOG_TAG "PlayerControllerNative"

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "video_player_controller.h"

VideoPlayerController* videoPlayerController;

static ANativeWindow* window = nullptr;

/**
 * 初始化
 *
 * @param srcFilenameParam
 *            文件路径或者直播地址
 * @return 是否正确初始化
 */
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_ryan_videoplayer_player_PlayerController_prepare(JNIEnv *env, jobject obj,
                                                          jstring src_filename_param,
                                                          jintArray max_analyze_durations,
                                                          jint size, jint probesize,
                                                          jboolean fps_probesize_configured,
                                                          jfloat min_buffered_duration,
                                                          jfloat max_buffered_duration, jint width,
                                                          jint height, jobject surface) {
    LOGI("Enter Java_com_changba_songstudio_video_player_ChangbaPlayer_prepare...\n");

    // 得到虚拟机实例g_jvm
    JavaVM *g_jvm = NULL;
    env->GetJavaVM(&g_jvm);

    // 得到Java层PlayerController对象实例，为后续native回调java做准备
    jobject g_obj = env->NewGlobalRef(obj);

    // 播放的视频源路径
    char* videoFilePath = (char*) env->GetStringUTFChars(src_filename_param, nullptr);

    if (videoPlayerController == nullptr) {
        videoPlayerController = new VideoPlayerController();
    }

    // 创建一个native的window
    window = ANativeWindow_fromSurface(env, surface);

    jint* max_analyze_duration_params = env->GetIntArrayElements(max_analyze_durations, 0);

    jboolean initCode = videoPlayerController->init(videoFilePath, g_jvm, g_obj, max_analyze_duration_params,
                                                    size, probesize, fps_probesize_configured, min_buffered_duration, max_buffered_duration);

    videoPlayerController->onSurfaceCreated(window, width, height);

    // 释放创建的local对象
    env->ReleaseIntArrayElements(max_analyze_durations, max_analyze_duration_params, 0);
    env->ReleaseStringUTFChars(src_filename_param, videoFilePath);

    return initCode;
}



extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_onSurfaceCreated(JNIEnv *env, jobject thiz,
                                                                   jobject surface) {
    // TODO: implement onSurfaceCreated()
    LOGI("onSurfaceCreated\n");

}

extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_onSurfaceDestroyed(JNIEnv *env, jobject thiz,
                                                                     jobject surface) {
    // TODO: implement onSurfaceDestroyed()
    LOGI("onSurfaceDestroyed\n");
}


/**
 * 暂停播放
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_pause(JNIEnv *env, jobject thiz) {
    // TODO: implement pause()
    LOGI("pause\n");
}

/**
 * 继续播放
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_play(JNIEnv *env, jobject thiz) {
    // TODO: implement play()
    LOGI("play\n");
}

/**
 * 停止播放
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_stop(JNIEnv *env, jobject thiz) {
    // TODO: implement stop()
}

/**
 * 获得缓冲进度 返回秒数（单位秒 但是小数点后有3位 精确到毫秒）
 */
extern "C"
JNIEXPORT jfloat JNICALL
Java_com_ryan_videoplayer_player_PlayerController_getBufferedProgress(JNIEnv *env, jobject thiz) {
    // TODO: implement getBufferedProgress()
}

/**
 * 获得播放进度（单位秒 但是小数点后有3位 精确到毫秒）
 */
extern "C"
JNIEXPORT jfloat JNICALL
Java_com_ryan_videoplayer_player_PlayerController_getPlayProgress(JNIEnv *env, jobject thiz) {
    // TODO: implement getPlayProgress()
}

/**
 * 跳转到某一个位置
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_seekToPosition(JNIEnv *env, jobject thiz,
                                                                 jfloat position) {
    // TODO: implement seekToPosition()
}

/**
 * 只做seek操作，seek到指定位置
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_seekCurrent(JNIEnv *env, jobject thiz,
                                                              jfloat position) {
    // TODO: implement seekCurrent()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_beforeSeekCurrent(JNIEnv *env, jobject thiz) {
    // TODO: implement beforeSeekCurrent()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_afterSeekCurrent(JNIEnv *env, jobject thiz) {
    // TODO: implement afterSeekCurrent()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ryan_videoplayer_player_PlayerController_resetRenderSize(JNIEnv *env, jobject thiz,
                                                                  jint left, jint top, jint width,
                                                                  jint height) {
    // TODO: implement resetRenderSize()
}