cmake_minimum_required(VERSION 3.4.1)

set(PATH_TO_MEDIACORE CACHE STRING "")

set(PATH_TO_NATIVE ${PATH_TO_MEDIACORE}/src/main/cpp)
set(PATH_TO_THIRDPARTY ${PATH_TO_NATIVE}/thirdparty)
set(PATH_TO_PRE_BUILT ${PATH_TO_THIRDPARTY}/prebuilt/${ANDROID_ABI})

add_definitions("
-DGL_GLEXT_PROTOTYPES
-DEGL_EGLEXT_PROTOTYPES
")

add_subdirectory(src/main/cpp)

include_directories(BEFORE ${PATH_TO_THIRDPARTY}/ffmpeg/include/)
include_directories(${PATH_TO_NATIVE}/)
include_directories(${PATH_TO_NATIVE}/common/)
include_directories(${PATH_TO_NATIVE}/video_player/)

#编译jni native入口文件
file(GLOB FILES_JNI_NATIVE "${PATH_TO_NATIVE}/*.cpp")

add_library(
        native-lib
        SHARED
        ${FILES_JNI_NATIVE})

target_link_libraries(
        native-lib
        # 引入系统的动态库
        log
        android
        GLESv2
        EGL
        z
        OpenSLES
        # 这个是main/cpp下编译出的av-engine
        av-engine
        # 引入ffmpeg相关静态库
        ${PATH_TO_PRE_BUILT}/libavfilter.a
        ${PATH_TO_PRE_BUILT}/libavformat.a
        ${PATH_TO_PRE_BUILT}/libavcodec.a
        ${PATH_TO_PRE_BUILT}/libpostproc.a
        ${PATH_TO_PRE_BUILT}/libswresample.a
        ${PATH_TO_PRE_BUILT}/libswscale.a
        ${PATH_TO_PRE_BUILT}/libavutil.a
        ${PATH_TO_PRE_BUILT}/libpostproc.a
        ${PATH_TO_PRE_BUILT}/libfdk-aac.a
        ${PATH_TO_PRE_BUILT}/libvo-aacenc.a
        ${PATH_TO_PRE_BUILT}/libx264.a
)