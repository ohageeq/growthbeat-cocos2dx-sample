//
//  GrowthAnalytics.mm
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "GrowthAnalytics.h"

#import "GrowthAnalyticsCCInternal.h"

USING_NS_CC;

growthanalytics::GrowthAnalytics::GrowthAnalytics() {};

void growthanalytics::GrowthAnalytics::initialize(const std::string& applicationId, const std::string& credentialId) {
    [GrowthAnalyticsCCInternal initializeWithApplicationId:[NSString stringWithUTF8String:applicationId.c_str()]
                                              credentialId:[NSString stringWithUTF8String:credentialId.c_str()]];
}

void growthanalytics::GrowthAnalytics::track(const std::string &eventId) {
    [GrowthAnalyticsCCInternal track:[NSString stringWithUTF8String:eventId.c_str()]];
}
void growthanalytics::GrowthAnalytics::track(const std::string &eventId, growthanalytics::GATrackOption option) {
    [GrowthAnalyticsCCInternal track:[NSString stringWithUTF8String:eventId.c_str()]
                              option:option];
}
void growthanalytics::GrowthAnalytics::track(const std::string &eventId, const std::map<std::string, std::string>& properties) {
    growthanalytics::GrowthAnalytics::track(eventId, properties, GATrackOptionDefault);
}
void growthanalytics::GrowthAnalytics::track(const std::string &eventId, const std::map<std::string, std::string>& properties, GATrackOption option) {
    
    NSMutableDictionary* dict = [[NSMutableDictionary dictionary] init];
    
    for( std::map< std::string, std::string >::const_iterator iter = properties.begin(); iter != properties.end(); iter++ ) {
    
        [dict setObject:[NSString stringWithUTF8String:((*iter).first).c_str()]
                 forKey:[NSString stringWithUTF8String:((*iter).second).c_str()]];
        
    }
    [GrowthAnalyticsCCInternal track:[NSString stringWithUTF8String:eventId.c_str()]
                          properties:dict
                              option:option];
}

void growthanalytics::GrowthAnalytics::tag(const std::string &tagId) {
    [GrowthAnalyticsCCInternal tag:[NSString stringWithUTF8String:tagId.c_str()]];
}
void growthanalytics::GrowthAnalytics::tag(const std::string &tagId, const std::string &value) {
    [GrowthAnalyticsCCInternal tag:[NSString stringWithUTF8String:tagId.c_str()]
                             value:[NSString stringWithUTF8String:value.c_str()]];
}

void growthanalytics::GrowthAnalytics::open(void) {
    [GrowthAnalyticsCCInternal open];
}
void growthanalytics::GrowthAnalytics::close(void) {
    [GrowthAnalyticsCCInternal close];
}
void growthanalytics::GrowthAnalytics::purchase(int price, const std::string &category, const std::string &product) {
    [GrowthAnalyticsCCInternal purchase:price
                            setCategory:[NSString stringWithUTF8String:category.c_str()]
                             setProduct:[NSString stringWithUTF8String:product.c_str()]];
}

void growthanalytics::GrowthAnalytics::setUserId(const std::string &userId) {
    [GrowthAnalyticsCCInternal setUserId:[NSString stringWithUTF8String:userId.c_str()]];
}
void growthanalytics::GrowthAnalytics::setName(const std::string &name) {
    [GrowthAnalyticsCCInternal setName:[NSString stringWithUTF8String:name.c_str()]];
}
void growthanalytics::GrowthAnalytics::setAge(int age) {
    [GrowthAnalyticsCCInternal setAge:age];
}
void growthanalytics::GrowthAnalytics::setGender(GAGender gender) {
    [GrowthAnalyticsCCInternal setGender:gender];
}
void growthanalytics::GrowthAnalytics::setLevel(int level) {
    [GrowthAnalyticsCCInternal setLevel:level];
}
void growthanalytics::GrowthAnalytics::setDevelopment(bool development) {
    [GrowthAnalyticsCCInternal setDevelopment:development];
}
void growthanalytics::GrowthAnalytics::setDeviceModel(void) {
    [GrowthAnalyticsCCInternal setDeviceModel];
}
void growthanalytics::GrowthAnalytics::setOS(void) {
    [GrowthAnalyticsCCInternal setOS];
}
void growthanalytics::GrowthAnalytics::setLanguage(void) {
    [GrowthAnalyticsCCInternal setLanguage];
}
void growthanalytics::GrowthAnalytics::setTimeZone(void) {
    [GrowthAnalyticsCCInternal setTimeZone];
}
void growthanalytics::GrowthAnalytics::setTimeZoneOffset(void) {
    [GrowthAnalyticsCCInternal setTimeZoneOffset];
}
void growthanalytics::GrowthAnalytics::setAppVersion(void) {
    [GrowthAnalyticsCCInternal setAppVersion];
}
void growthanalytics::GrowthAnalytics::setRandom(void) {
    [GrowthAnalyticsCCInternal setRandom];
}
void growthanalytics::GrowthAnalytics::setAdvertisingId(const std::string &idfa) {
    [GrowthAnalyticsCCInternal setAdvertisingId:[NSString stringWithUTF8String:idfa.c_str()]];
}
void growthanalytics::GrowthAnalytics::setBasicTags(void) {
    [GrowthAnalyticsCCInternal setBasicTags];
}

#endif
