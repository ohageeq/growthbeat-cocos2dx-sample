LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/Growthbeat/GrowthbeatInstance.cpp \
                   ../../Classes/Growthbeat/android/Growthbeat.cpp \
                   ../../Classes/GrowthPush/GrowthPushInstance.cpp \
                   ../../Classes/GrowthPush/android/GrowthPush.cpp \
                   ../../Classes/GrowthAnalytics/GrowthAnalyticsInstance.cpp \
                   ../../Classes/GrowthAnalytics/android/GrowthAnalytics.cpp \
                   ../../Classes/GrowthLink/GrowthLinkInstance.cpp \
                   ../../Classes/GrowthLink/android/GrowthLink.cpp \
                   ../../Classes/GrowthbeatCore/GrowthbeatCoreInstance.cpp \
                   ../../Classes/GrowthbeatCore/android/GrowthbeatCore.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../Classes/Growthbeat/ \
					$(LOCAL_PATH)/../../Classes/Growthbeat/android \
					$(LOCAL_PATH)/../../Classes/GrowthPush/ \
					$(LOCAL_PATH)/../../Classes/GrowthPush/android \
					$(LOCAL_PATH)/../../Classes/GrowthAnalytics/ \
					$(LOCAL_PATH)/../../Classes/GrowthAnalytics/android \
                    $(LOCAL_PATH)/../../Classes/GrowthbeatCore/ \
                    $(LOCAL_PATH)/../../Classes/GrowthbeatCore/android \
					$(LOCAL_PATH)/../../Classes/GrowthLink/ \
                    $(LOCAL_PATH)/../../Classes/GrowthLink/android

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
