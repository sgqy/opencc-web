#include <opencc/SimpleConverter.hpp>
#include "opencc4j.h"


inline
std::string jstr2str(JNIEnv* env, jstring s)
{
    if (!s) // example: String (java) is null
    {
        return std::string("");
    }
    jsize len = env->GetStringUTFLength(s);
    const char* cs = env->GetStringUTFChars(s, 0);
    auto&& ret = std::string(cs, len);
    env->ReleaseStringUTFChars(s, cs);
    return ret;
}


inline
jstring str2jstr(JNIEnv* env, const std::string& s)
{
    return env->NewStringUTF(s.c_str());
}


JNIEXPORT jlong JNICALL Java_cc_sgqy_utils_cxx_OpenCC_new_1obj
  (JNIEnv * env, jobject, jstring conf)
{
    try
    {
        const std::string&& fn = jstr2str(env, conf);
        const opencc::SimpleConverter* instance = new opencc::SimpleConverter(fn);
        return reinterpret_cast<jlong>(instance);
    }
    catch(...)
    {
        return 0; // return NULL on any cpp exception
    }
}


JNIEXPORT jlong JNICALL Java_cc_sgqy_utils_cxx_OpenCC_del_1obj
  (JNIEnv *, jobject, jlong ptr)
{
    try
    {
        opencc::SimpleConverter* instance = reinterpret_cast<opencc::SimpleConverter*>(ptr);
        delete instance;
        return 0;
    }
    catch(...)
    {
        return -1;
    }
}


JNIEXPORT jstring JNICALL Java_cc_sgqy_utils_cxx_OpenCC_conv_1text
  (JNIEnv * env, jobject, jlong ptr, jstring text)
{
    try
    {
        opencc::SimpleConverter* instance = reinterpret_cast<opencc::SimpleConverter*>(ptr);
        const std::string&& src = jstr2str(env, text);
        const std::string&& dst = instance->Convert(src);
        return str2jstr(env, dst);
    }
    catch(const std::exception& e)
    {
        std::string ec = "opencc4j/cpp: convert error.";
        ec += e.what();
        return str2jstr(env, ec);
    }
}