//
// Created by gullp on 04/05/2021.
//

#ifndef ANDROID_OTV_LOGDEF_H
#define ANDROID_OTV_LOGDEF_H

#include <android/log.h>

#define  LOG_TAG    "ANDROID_OTV"

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#endif //ANDROID_OTV_LOGDEF_H
