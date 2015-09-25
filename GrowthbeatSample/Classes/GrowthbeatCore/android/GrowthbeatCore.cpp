//
//  GrowthbeatCore.cpp
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/17.
//
//


#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "GrowthbeatCore.h"

#include <string>
#include <jni.h>

#include "cocos2d.h"
# include "platform/android/jni/JniHelper.h"
#include "json/document.h"
# include "../../Growthbeat/GbJsonHelper.h"

USING_NS_CC;
USING_NS_GROWTHBEATCORE;

static std::function<bool(std::map<std::string,std::string>)> s_selector = nullptr;

extern "C"
{
    JNIEXPORT void JNICALL Java_com_growthbeat_intenthandler_JavaNativeListener_onHandled(JNIEnv* env, jobject thiz, jlong delegate, jstring jJson)
    {
        if (s_selector != nullptr) {
            std::string json = JniHelper::jstring2string(jJson);
            rapidjson::Document doc;
            
            doc.Parse<0>(json.c_str());
            bool error = doc.HasParseError();
            if(error){
                printf("parse error\n");
                return;
            }
            std::map<std::string,std::string> extraMap;
            for(rapidjson::Value::ConstMemberIterator itr = doc.MemberonBegin();
                itr != doc.MemberonEnd(); itr++)
            {
                const char* name = itr->name.GetString();
                const char* value = itr->value.GetString();
                extraMap[std::string(name)] = std::string(value);
            }
            (s_selector)(extraMap);
        }
    }
};

static const char *const JavaClassName = "com/growthbeat/intenthandler/IntentHandlerJNI";

growthbeatcore::GrowthbeatCore::GrowthbeatCore() {};

void GrowthbeatCore::initializeIntentHandlers(void){
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "initializeIntentHandlers", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthbeatCore::addNoopIntentHandler(void){
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "addNoopIntentHandler", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthbeatCore::addUrlIntentHandler(void){
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "addUrlIntentHandler", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthbeatCore::addCustomIntentHandler(const OnHandle& handle){
    CCAssert(handle, "selector should not be NULL");
    s_selector = handle;
}

#endif
