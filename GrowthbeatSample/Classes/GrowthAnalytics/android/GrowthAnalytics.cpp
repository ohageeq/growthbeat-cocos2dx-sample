//
//  GrowthAnalytics.cpp
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "GrowthAnalytics.h"

#include <string>
#include <jni.h>

#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

USING_NS_CC;
USING_NS_GROWTHANALYTICS;

static const char *const JavaClassName = "com/growthbeat/analytics/GrowthAnalyticsJNI";

growthanalytics::GrowthAnalytics::GrowthAnalytics() {};

void GrowthAnalytics::track(const std::string& eventId) {
	JniMethodInfo t;

	if (JniHelper::getStaticMethodInfo(t, JavaClassName, "track", "(Ljava/lang/String;)V")) {
		jstring jEventId = t.env->NewStringUTF(eventId.c_str());
	    t.env->CallStaticVoidMethod(t.classID, t.methodID, jEventId);
	    t.env->DeleteLocalRef(jEventId);
	    t.env->DeleteLocalRef(t.classID);
	}
}
void GrowthAnalytics::track(const std::string& eventId, const std::map<std::string, std::string>& properties) {
	JniMethodInfo t;

	if (JniHelper::getStaticMethodInfo(t, JavaClassName, "track", "(Ljava/lang/String;Ljava/util/Map;)V")) {
		jstring jEventId = t.env->NewStringUTF(eventId.c_str());

		jobject jProperties = 0;
		jclass hashMapClass = t.env->FindClass("java/util/HashMap");
		if(hashMapClass) {
			jsize mapSize = properties.size();
			jmethodID init = t.env->GetMethodID(hashMapClass, "<init>", "(I)V");
			jobject hashMap = t.env->NewObject(hashMapClass, init, mapSize);
			jmethodID putMethod = t.env->GetMethodID(hashMapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

			for(std::map<std::string, std::string>::const_iterator it = properties.begin();
					it != properties.end(); ++it) {
				jstring key = t.env->NewStringUTF(it->first.c_str());
				jstring value = t.env->NewStringUTF(it->second.c_str());
				t.env->CallObjectMethod(hashMap, putMethod, key, value);
				t.env->DeleteLocalRef(key);
				t.env->DeleteLocalRef(value);
			}
			jProperties = hashMap;
			t.env->DeleteLocalRef(hashMapClass);
		}
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jEventId, jProperties);
	    t.env->DeleteLocalRef(jEventId);
	    t.env->DeleteLocalRef(jProperties);
	    t.env->DeleteLocalRef(t.classID);
	}
}
void GrowthAnalytics::track(const std::string& eventId, GATrackOption option) {
	JniMethodInfo t;

	if (JniHelper::getStaticMethodInfo(t, JavaClassName, "track", "(Ljava/lang/String;I)V")) {
		jstring jEventId = t.env->NewStringUTF(eventId.c_str());
	    t.env->CallStaticVoidMethod(t.classID, t.methodID, jEventId, option);
	    t.env->DeleteLocalRef(jEventId);
	    t.env->DeleteLocalRef(t.classID);
	}
}
void GrowthAnalytics::track(const std::string& eventId, const std::map<std::string, std::string>& properties, GATrackOption option) {
	JniMethodInfo t;

	if (JniHelper::getStaticMethodInfo(t, JavaClassName, "track", "(Ljava/lang/String;Ljava/util/Map;I)V")) {
		jstring jEventId = t.env->NewStringUTF(eventId.c_str());

		jobject jProperties = 0;
		jclass hashMapClass = t.env->FindClass("java/util/HashMap");
		if(hashMapClass) {
			jsize mapSize = properties.size();
			jmethodID init = t.env->GetMethodID(hashMapClass, "<init>", "(I)V");
			jobject hashMap = t.env->NewObject(hashMapClass, init, mapSize);
			jmethodID putMethod = t.env->GetMethodID(hashMapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

			for(std::map<std::string, std::string>::const_iterator it = properties.begin();
					it != properties.end(); ++it) {
				jstring key = t.env->NewStringUTF(it->first.c_str());
				jstring value = t.env->NewStringUTF(it->second.c_str());
				t.env->CallObjectMethod(hashMap, putMethod, key, value);
				t.env->DeleteLocalRef(key);
				t.env->DeleteLocalRef(value);
			}
			jProperties = hashMap;
			t.env->DeleteLocalRef(hashMapClass);
		}
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jEventId, jProperties, option);
	    t.env->DeleteLocalRef(jEventId);
	    t.env->DeleteLocalRef(jProperties);
	    t.env->DeleteLocalRef(t.classID);
	}
}

void GrowthAnalytics::tag(const std::string& tagId) {
	JniMethodInfo t;

	if (JniHelper::getStaticMethodInfo(t, JavaClassName, "tag", "(Ljava/lang/String;)V")) {
		jstring jTagId = t.env->NewStringUTF(tagId.c_str());
	    t.env->CallStaticVoidMethod(t.classID, t.methodID, jTagId);
	    t.env->DeleteLocalRef(jTagId);
	    t.env->DeleteLocalRef(t.classID);
	}
}
void GrowthAnalytics::tag(const std::string& tagId, const std::string& value) {
	JniMethodInfo t;

	if (JniHelper::getStaticMethodInfo(t, JavaClassName, "tag", "(Ljava/lang/String;Ljava/lang/String;)V")) {
		jstring jTagId = t.env->NewStringUTF(tagId.c_str());
		jstring jValue = t.env->NewStringUTF(value.c_str());
	    t.env->CallStaticVoidMethod(t.classID, t.methodID, jTagId, jValue);
	    t.env->DeleteLocalRef(jTagId);
	    t.env->DeleteLocalRef(jValue);
	    t.env->DeleteLocalRef(t.classID);
	}
}

void GrowthAnalytics::open(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "open", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::close(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "close", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::purchase(int price, const std::string& category, const std::string& product) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "purchase", "(ILjava/lang/String;Ljava/lang/String;)V")) {
        jstring jCategory = t.env->NewStringUTF(category.c_str());
        jstring jProduct = t.env->NewStringUTF(product.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, price, jCategory, jProduct);
        t.env->DeleteLocalRef(jCategory);
        t.env->DeleteLocalRef(jProduct);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthAnalytics::setUserId(const std::string& userId) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setUserId", "(Ljava/lang/String;)V")) {
        jstring jUserId = t.env->NewStringUTF(userId.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jUserId);
        t.env->DeleteLocalRef(jUserId);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setName(const std::string& name) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setName", "(Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setAge(int age) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setAge", "(I)V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, age);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setGender(GAGender gender) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setGender", "(I)V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, gender);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setLevel(int level) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setLevel", "(I)V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, level);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setDevelopment(bool development) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setDevelopment", "(Z)V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, development);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setDeviceModel(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setDeviceModel", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setOS(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setOS", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setLanguage(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setLanguage", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setTimeZone(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setTimeZone", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setTimeZoneOffset(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setTimeZoneOffset", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setAppVersion(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setAppVersion", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}
void GrowthAnalytics::setRandom(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setRandom", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthAnalytics::setAdvertisingId(const std::string& Temp) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setAdvertisingId", "(Ljava/lang/String;)V")) {
    	t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }

}
void GrowthAnalytics::setBasicTags(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setBasicTags", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

#endif
