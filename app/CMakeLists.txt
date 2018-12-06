

cmake_minimum_required(VERSION 3.4.1)


set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution)
include_directories(${distribution_DIR}/include)

add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

add_library(lib_add SHARED IMPORTED)
set_target_properties(lib_add PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libs/${ANDROID_ABI}/libadd.so)

# 系統自帶部分
add_library( # Sets the name of the library.
        native-math

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-math.cpp )


find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )


set_target_properties(native-math PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY
        ${distribution_DIR}/libs/${ANDROID_ABI})

target_link_libraries( # Specifies the target library.
        native-math
        android
        log
        lib_opencv
        lib_add

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )



