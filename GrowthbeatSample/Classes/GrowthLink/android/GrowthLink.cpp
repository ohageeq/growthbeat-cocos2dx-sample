//
//  GrowthLinkCCInternal.h
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/08.
//
//

#include "cCconfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "GrowthLink.h"
#include <string>
#include <jni.h>

#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

USING_NS_CC;
USING_NS_GROWTHLINK;

static const char *const JavaClassName = "com/growthbeat/link/GrowthLinkJNI";

growthlink::GrowthLink::GrowthLink() {}

void growthlink::GrowthLink::initialize(const std::string& applicationId, const std::string& credentialId) {
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

bool handleOpenUrl(const std::string& url){
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "handleOpenUrl", "(Ljava/lang/String;)V")) {
    	jstring jUrl = t.env->NewStringUTF(url.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jUrl);
        t.env->DeleteLocalRef(jUrl);
        t.env->DeleteLocalRef(t.classID);
    }
    return true;
}

#endif