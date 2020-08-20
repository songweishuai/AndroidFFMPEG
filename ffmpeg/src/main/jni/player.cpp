//
// Created by keda on 20-8-20.
//

#include <stdio.h>
#include <signal.h>

#include "player.h"
#include "include/libavutil/log.h"
#include "../../../../../../../IDE/Android/Sdk/ndk/android-ndk-r14b/platforms/android-19/arch-arm/usr/include/stdlib.h"
#include "../../../../../../../IDE/Android/Sdk/ndk/android-ndk-r14b/toolchains/llvm/prebuilt/linux-x86_64/lib64/clang/3.8.275480/include/stdarg.h"
#include "../../../../../../../IDE/Android/Sdk/ndk/android-ndk-r14b/platforms/android-19/arch-arm/usr/include/android/log.h"


GlobalContext global_context;

static void sigterm_handler(int sig) {
    av_log(NULL, AV_LOG_ERROR, "");
    exit(123);
}

static void ffmpeg_log_callback(void *ptr, int level, const char *fmt, va_list vl)
{
    __android_log_vprint(ANDROID_LOG_DEBUG, "FFmpeg", fmt, vl);
}

void *open_media(void *argv) {

    av_log_set_callback();
}
