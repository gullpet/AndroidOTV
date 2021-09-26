# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("androidotv")

set(CMAKE_VERBOSE_MAKEFILE on)
# Previously: -std=gnu++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(${CMAKE_SOURCE_DIR}/../jniIncludes)
include_directories(${CMAKE_SOURCE_DIR}/otv/include)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for ekkyou.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp
             otv/src/filter.cpp
             otv/src/main.cpp
             otv/src/ops.cpp
             otv/src/reader.cpp
             otv/src/utils.cpp
             otv/src/writer.cpp )

add_library( libopencv_core SHARED IMPORTED )
set_target_properties( libopencv_core PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_core.so)

add_library( libopencv_highgui SHARED IMPORTED )
set_target_properties( libopencv_highgui PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_highgui.so)

add_library( libopencv_imgproc SHARED IMPORTED )
set_target_properties( libopencv_imgproc PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_imgproc.so)

add_library( libopencv_videoio SHARED IMPORTED )
set_target_properties( libopencv_videoio PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_videoio.so)

add_library( libopencv_imgcodecs SHARED IMPORTED )
set_target_properties( libopencv_imgcodecs PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_imgcodecs.so)

add_library( libopencv_features2d SHARED IMPORTED )
set_target_properties( libopencv_features2d PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_features2d.so)

add_library( libopencv_video SHARED IMPORTED )
set_target_properties( libopencv_video PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_video.so)

add_library( libopencv_flann SHARED IMPORTED )
set_target_properties( libopencv_flann PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_flann.so)

add_library( libopencv_dnn SHARED IMPORTED )
set_target_properties( libopencv_dnn PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_dnn.so)

add_library( libopencv_calib3d SHARED IMPORTED )
set_target_properties( libopencv_calib3d PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libopencv_calib3d.so)

#add_library( libomp SHARED IMPORTED )
#set_target_properties( libomp PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libomp.so)

add_library( libtbb SHARED IMPORTED )
set_target_properties( libtbb PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../cmakeLibs/${ANDROID_ABI}/libtbb.so)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}

                       libopencv_core
                       libopencv_highgui
                       libopencv_imgproc
                       libopencv_videoio
                       libopencv_imgcodecs
                       libopencv_features2d
                       libopencv_video
                       libopencv_flann
                       libopencv_dnn
                       libopencv_calib3d
                       #libomp )
                       libtbb )