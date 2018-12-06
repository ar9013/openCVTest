#include <jni.h>
#include <string>
#include "../../../../mathlib/src/main/cpp/add.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>


using namespace std;
using namespace cv;



extern "C"
JNIEXPORT jstring JNICALL
Java_opencv_smartdata_com_opencvtest_MainActivity_stringFromJNI(JNIEnv *env, jobject instance) {

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_opencv_smartdata_com_opencvtest_MainActivity_addFromCpp
        (JNIEnv *env, jobject instance, jint a, jint b) {



    return add(a,b);

}

extern "C"
void JNICALL Java_opencv_smartdata_com_opencvtest_MainActivity_salt
        (JNIEnv *env, jobject instance, jlong matAddrGray, jint nbrElem) {
    Mat &mGr = *(Mat *) matAddrGray;
    for (int k = 0; k < nbrElem; k++) {
        int i = rand() % mGr.cols;
        int j = rand() % mGr.rows;
        mGr.at<uchar>(j, i) = 255;
    }
}


