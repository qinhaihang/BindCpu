# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
#set (NDK_TOOLCHAIN android-armv7_16)
#set (TARGET_ARCH ARMV7)
#set (LIB_STATIC android-armv7)

#set (NDK_TOOLCHAIN android-aarch64)
#set (TARGET_ARCH AARCH64)
#set (LIB_STATIC android-aarch64)

#set (NDK_TOOLCHAIN windows-x86_64)

#SET(NDK_STANDALONE_TOOLCHAIN D:/android/Android_Studio_3.1/Sdk/ndk-bundle/toolchains/aarch64-linux-android-4.9/prebuilt/${NDK_TOOLCHAIN})
#32位编译选项
#SET(CMAKE_C_COMPILER ${NDK_STANDALONE_TOOLCHAIN}/bin/arm-linux-androideabi-gcc)
#SET(CMAKE_CXX_COMPILER ${NDK_STANDALONE_TOOLCHAIN}/bin/arm-linux-androideabi-g++)
#64位编译选项
#SET(CMAKE_C_COMPILER ${NDK_STANDALONE_TOOLCHAIN}/bin/aarch64-linux-android-gcc)
#SET(CMAKE_CXX_COMPILER ${NDK_STANDALONE_TOOLCHAIN}/bin/aarch64-linux-android-g++)

#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -O2 -std=gnu++0x")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -std=gnu++0x")

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#设置生成的so动态库最后输出的路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

add_library( # Sets the name of the library.
             bind_cpu

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             affinity.cpp)

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
                       bind_cpu

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
