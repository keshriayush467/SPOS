#include <jni.h>
#include "MathJNI.h"

JNIEXPORT jint JNICALL
Java_MathJNI_add( JNIEnv*, jobject, jint a, jint b)
{
    return a+b;
}


 // Compiled Shared Lib .so file command
 // g++ -fPIC -shared -o libMathDLL.so MathDLL.cpp -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux"

   // After this run the program
   //   export LD_LIBRARY_PATH =.java MathJNI