//
// Created by keda on 20-8-20.
//

#include <pthread.h>
#include "com_example_ffmpeg_VideoSurface.h"

#include <android/native_window_jni.h>
#include <android/native_window.h>
#include <android/log.h>


static ANativeWindow *mANativeWindow;
static ANativeWindow_Buffer mWBuffer;

static jclass globalVideoSurfaceClass = NULL;
static jobject globalVideoSurfaceObject = NULL;

extern "C" {


/*
 * Class:     com_example_ffmpeg_VideoSurface
 * Method:    setSurface
 * Signature: (Landroid/view/Surface;)I
 */
JNIEXPORT jint JNICALL
Java_com_example_ffmpeg_VideoSurface_setSurface(JNIEnv *env, jobject obj, jobject surface) {
    pthread_t thread_1;

    jclass localVideoSurfaceClass = env->FindClass("com/example/ffmpeg/VideoSurface");
    if (NULL == localVideoSurfaceClass) {
        //__android_log_vprint("")
        return -1;
    }

    globalVideoSurfaceClass = (jclass) env->NewGlobalRef(localVideoSurfaceClass);

    if (NULL == globalVideoSurfaceClass) {

    }

    globalVideoSurfaceObject = (jclass) env->NewGlobalRef(obj);
    if (NULL == globalVideoSurfaceObject) {

    }

    if (NULL == surface) {
        mANativeWindow = NULL;
        return 0;
    }

    mANativeWindow = ANativeWindow_fromSurface(env, surface);

    pthread_create(&thread_1, NULL, open_media, NULL);

    return 0;
}

/*
 * Class:     com_example_ffmpeg_VideoSurface
 * Method:    nativePausePlayer
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_ffmpeg_VideoSurface_nativePausePlayer(JNIEnv *env, jobject)
{
    global_context.pause = 1;
    return 1;
}

/*
 * Class:     com_example_ffmpeg_VideoSurface
 * Method:    nativeResumePlayer
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_ffmpeg_VideoSurface_nativeResumePlayer(JNIEnv *env, jobject)
{
    global_context.pause = 0;
    return 1;
}

/*
 * Class:     com_example_ffmpeg_VideoSurface
 * Method:    nativeStopPlayer
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_ffmpeg_VideoSurface_nativeStopPlayer(JNIEnv *env, jobject)
{
    global_context.quit = 1;
    return 1;
}

}