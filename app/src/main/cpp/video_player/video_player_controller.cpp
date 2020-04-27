//
// Created by hengfeng zhuo on 2020/4/26.
//

#include "video_player_controller.h"

VideoPlayerController::VideoPlayerController() {

}

VideoPlayerController::~VideoPlayerController() {

}

bool VideoPlayerController::init(char *srcFilenameParam, JavaVM *g_jvm, jobject obj,
                                 int *max_analyze_duration, int analyzeCnt, int probesize,
                                 bool fpsProbeSizeConfigured, float minBufferedDuration,
                                 float maxBufferedDuration) {
    return false;
}

void VideoPlayerController::play() {

}

void VideoPlayerController::pause() {

}

void VideoPlayerController::destroy() {

}

void VideoPlayerController::seekToPosition(float position) {

}

void VideoPlayerController::onSurfaceCreated(ANativeWindow *window, int widht, int height) {

}

void VideoPlayerController::onSurfaceDestroyed() {

}

float VideoPlayerController::getDuration() {
    return 0;
}

int VideoPlayerController::getVideoFrameWidth() {
    return 0;
}

int VideoPlayerController::getVideoFrameHeight() {
    return 0;
}

float VideoPlayerController::getBufferedProgress() {
    return 0;
}

float VideoPlayerController::getPlayProgress() {
    return 0;
}

void VideoPlayerController::resetRenderSize(int left, int top, int width, int height) {

}

