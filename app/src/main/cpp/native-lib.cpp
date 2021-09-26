#include <jni.h>
#include <string>
#include <fstream>

#include "otv.h"
#include "logdef.h"

//#define PATH_VIDEO "/data/data/gullp.androidotv/video.mjpeg.avi"

#define PATH_INFO_VIDEO "/data/data/gullp.androidotv/info_video.txt"
#define PATH_FILE_PARAMS "/data/data/gullp.androidotv/params.txt"
#define PATH_LK_FILE "/data/data/gullp.androidotv/lk.txt"
#define PATH_OUTPUT "/data/data/gullp.androidotv/output"
#define PATH_MASK "/data/data/gullp.androidotv/mask.png"

extern "C" JNIEXPORT jstring JNICALL Java_gullp_androidotv_OTVThread_runOTV( JNIEnv* env, jobject) {

    char* argv[6];
    argv[0] = "OTV_AndroidInstance";
    argv[1] = PATH_INFO_VIDEO;
    argv[2] = PATH_FILE_PARAMS;
    argv[3] = PATH_LK_FILE;
    argv[4] = PATH_OUTPUT;
    argv[5] = PATH_MASK;

    LOGD("Running OTV...");

    return env->NewStringUTF(run(6, argv).c_str());
}
