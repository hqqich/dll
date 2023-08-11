#include <iostream>
#include <Hello.h>
#include <libdllCreate.h>

// 实现JNI的头文件
// env变量是 JNIEnv 类型的对象，该对象是一个 Java 虚拟机所运行的环境，通过它可以访问到 Java 虚拟机内部的各种对象。
extern "C"
JNIEXPORT jlong JNICALL Java_Hello_add(JNIEnv *env, jclass x, jlong y, jlong z, jstring str_) {

    // 将 jni 类型转化为 c++ 类型
    int64_t cppLongY = static_cast<int64_t>(y);
    int64_t cppLongZ = static_cast<int64_t>(z);

    int64_t cppLongSum = cppLongY + cppLongZ;
    // 打印int64_t
    printf("%lld", cppLongSum);

    // 生成 jstring 类型的字符串
    jstring returnValue = env->NewStringUTF("hello native string");
    printf("%s", returnValue);
    // 将 jstring 类型的字符串转换为 C 风格的字符串，会额外申请内存
    const char *str = env->GetStringUTFChars(str_, 0);
    // 释放掉申请的 C 风格字符串的内存
    env->ReleaseStringUTFChars(str_, str);

    // 调用c++编译过的dll
    hello();

    // 计算
    jlong sum = y + z;
    // 返回
    return sum;
}