#!/bin/bash

# Author: Guglielmo Palaferri

#Usage: ./opencv-android-builder.sh [{arm64-v8a, armeabi-v7a, ...}]

# This script builds OpenCV from source for any of the ABIs provided via args.
# Has to be run from inside the root directory of the source code 
# Example:  $ git clone [opencv-git-url] opencv
#           $ cd opencv
#           $ ./opencv-android-builder.sh [list-of-ABIs])


# Android API level to be used, specify the lowest API level with which your Android application is supposed to work
ANDROID_API_LEVEL=android-29

# Specifies the root directory of the SDK to be used
ANDROID_SDK_ROOT=/mnt/hdd/data/ProgramFiles/Android/Sdk

ANDROID_NDK=$ANDROID_SDK_ROOT/ndk/22.1.7171670

# CMake file configured for the android toolchain, tipically comes bundled with the NDK
ANDROID_TOOLCHAIN_PATH=$ANDROID_NDK/build/cmake/android.toolchain.cmake

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 BUILD_NAME (Example: $0 NEON_TBB)"
    exit 1
fi

BUILD_NAME=$1

for ABI in "armeabi-v7a" "arm64-v8a"; do

    mkdir -p build_$ABI

    cd build_$ABI

    rm CMakeCache.txt

    cmake \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN_PATH \
    -DANDROID_ABI=$ABI \
    -DANDROID_NATIVE_API_LEVEL=$ANDROID_API_LEVEL \
    -DANDROID_STL=c++_shared \
    -GNinja \
    -DCMAKE_BUILD_TYPE:STRING=Release \
    -DBUILD_FAT_JAVA_LIB=OFF \
    -DBUILD_JAVA=OFF \
    -DBUILD_SHARED_LIBS=ON \
    -DWITH_TBB=OFF \
    -DBUILD_TBB=OFF \
    -DWITH_OPENMP=OFF \
    -DWITH_OPENCL=OFF \
    -DENABLE_NEON=OFF \
    -DWITH_CAROTENE=OFF \
    -DWITH_PTHREADS_PF=OFF \
    -DANDROID_SDK_ROOT=$ANDROID_SDK_ROOT \
    -DANDROID_NDK=$ANDROID_NDK \
    -DOPENCV_ENABLE_NONFREE=ON \
    -DBUILD_TESTS=FALSE -DBUILD_PERF_TESTS=FALSE \
    -DBUILD_ANDROID_EXAMPLES=FALSE \
    -DBUILD_DOCS:BOOL=OFF -DWITH_IPP=OFF -DWITH_MSMF=OFF \
    ..


    ninja
    ninja install
    cd ..
done

# Sistemo il risultato della compilazione
mv ./build_armeabi-v7a/install/sdk/native/libs/armeabi-v7a ./build_arm64-v8a/install/sdk/native/libs
rm -r ./build_armeabi-v7a
mv ./build_arm64-v8a ./builds/build_$BUILD_NAME
