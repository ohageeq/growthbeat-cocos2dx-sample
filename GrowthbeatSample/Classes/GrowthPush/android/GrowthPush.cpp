//

//  GrowthPush.cpp
//  growthpush-cocos2dx
//
//  Created by TSURUDA Ryo on 2013/12/08.
//  Copyright (c) 2013年 TSURUDA Ryo. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

# include "GrowthPush.h"

# include <string>
# include <jni.h>

# include "cocos2d.h"
# include "platform/android/jni/JniHelper.h"

# include "../../Growthbeat/GbJsonHelper.h"

USING_NS_CC;
USING_NS_GROWTHPUSH;

static const char *const JavaClassName = "com/growthpush/GrowthPushJNI";

// FIXME: for C++11
// static gpDidReceiveRemoteNotificationCallback s_callback = nullptr;
static cocos2d::Application *s_target = nullptr;
static GPRemoteNotificationCallback s_selector = nullptr;

extern "C" {
JNIEXPORT void JNICALL Java_com_growthpush_Cocos2dxBridge_didOpenRemoteNotification(JNIEnv *env, jobject thiz, jstring jJson) {
    // FIXME: for C++11

    /*
    if (s_callback != nullptr) {
        std::string json = JniHelper::jstring2string(jJson);
        auto jsonMap = GPJsonHelper::parseJson2Map(json.c_str());
        s_callback(jsonMap);
    }
     */
    if ((s_target != nullptr) && (s_selector != nullptr)) {
        std::string json = JniHelper::jstring2string(jJson);
        auto jsonValue = growthbeat::GbJsonHelper::parseJson2Value(json.c_str());
        (s_target->*s_selector)(jsonValue);
    }
}

}

GrowthPush::GrowthPush(void)
{}

void GrowthPush::requestDeviceToken(GPEnvironment environment) {
    // Do nothing on Android
}

void GrowthPush::requestDeviceToken(const std::string& senderId, GPEnvironment environment) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "requestRegistrationId", "(Ljava/lang/String;I)V")) {
        jstring jSenderId = t.env->NewStringUTF(senderId.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jSenderId, (int) environment);
        t.env->DeleteLocalRef(jSenderId);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::trackEvent(const std::string& name) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "trackEvent", "(Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::trackEvent(const std::string& name, const std::string& value) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "trackEvent", "(Ljava/lang/String;Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        jstring jValue = t.env->NewStringUTF(value.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName, jValue);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(jValue);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::setTag(const std::string& name) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setTag", "(Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::setTag(const std::string& name, const std::string& value) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setTag", "(Ljava/lang/String;Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        jstring jValue = t.env->NewStringUTF(value.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName, jValue);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(jValue);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::setDeviceTags(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setDeviceTags", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::clearBadge(void) {
    // Do nothing on Android
}

// FIXME: for C++11
// void GrowthPush::setOpenNotificationCallback(const gpDidReceiveRemoteNotificationCallback &callback)
void GrowthPush::setOpenNotificationCallback(Application *target, GPRemoteNotificationCallback selector) {
    // s_callback = callback;
    CCAssert(target, "target should not be NULL");
    CCAssert(selector, "selector should not be NULL");

    s_target = target;
    s_selector = selector;

}

#endif
