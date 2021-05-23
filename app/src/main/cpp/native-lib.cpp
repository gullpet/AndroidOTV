#include <jni.h>
#include <string>
#include <fstream>

#include "otv.h"
#include "logdef.h"

#define PATH_VIDEO "/data/data/gullp.androidotv/files/video.mjpeg.avi"
#define PATH_FILE_PARAMS "/data/data/gullp.androidotv/files/params.txt"
#define PATH_LK_FILE "/data/data/gullp.androidotv/files/lk.txt"
#define PATH_OUTPUT "/data/data/gullp.androidotv/files/output"
#define PATH_MASK "/data/data/gullp.androidotv/files/mask.png"

std::string fileTest(){

    std::ifstream file(PATH_LK_FILE);
    std::ofstream outfile("/data/data/gullp.otv_4_5_1/files/copia_lk_trollerino.txt", std::ios::trunc);
    std::string str;
    std::string result_str = "nullo";

    while(std::getline(file, str)){
        if(result_str == "nullo")
            result_str = str;
    }

    outfile << "Linea 1" << std::endl << "Linea 2" << std::endl;
    outfile.close();
    file.close();
    return result_str;
}

extern "C" JNIEXPORT jstring JNICALL
Java_gullp_androidotv_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    return env->NewStringUTF(fileTest().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_gullp_androidotv_MainActivity_runOTV( JNIEnv* env, jobject) {

    char* argv[6];
    argv[0] = "OTV_AndroidInstance";
    argv[1] = PATH_VIDEO;
    argv[2] = PATH_FILE_PARAMS;
    argv[3] = PATH_LK_FILE;
    argv[4] = PATH_OUTPUT;
    argv[5] = PATH_MASK;

    LOGD("Running OTV... ;)");

    return env->NewStringUTF(run(6, argv).c_str());
}