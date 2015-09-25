//
//  Growthbeat.cpp
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "Growthbeat.h"

#include <string>
#include <jni.h>

#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

USING_NS_CC;
USING_NS_GROWTHBEAT;

static const char *const JavaClassName = "com/growthbeat/GrowthbeatJNI";

growthbeat::Growthbeat::Growthbeat() {};

void Growthbeat::initialize(const std::string& applicationId, const std::string& credentialId) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "initialize", "(Ljava/lang/String;Ljava/lang/String;)V")) {
    	jstring jApplicationId = t.env->NewStringUTF(applicationId.c_str());
    	jstring jCredentialId = t.env->NewStringUTF(credentialId.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jApplicationId, jCredentialId);
        t.env->DeleteLocalRef(jApplicationId);
        t.env->DeleteLocalRef(jCredentialId);
        t.env->DeleteLocalRef(t.classID);
    }
}

void Growthbeat::start(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "start", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void Growthbeat::stop(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "stop", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void Growthbeat::setLoggerSilent(bool silent) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setLoggerSilent", "(Z)V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, silent);
        t.env->DeleteLocalRef(t.classID);
    }
}

#endif
