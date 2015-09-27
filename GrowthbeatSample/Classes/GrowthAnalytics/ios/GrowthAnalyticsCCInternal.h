//
//  GrowthAnalyticsCCInternal.h
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/GrowthAnalytics.h>

@interface GrowthAnalyticsCCInternal : NSObject

/* GrowthAnalytics SDK interface */
+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId;

+ (void)track:(NSString *)name;
+ (void)track:(NSString *)name properties:(NSDictionary *)properties;
+ (void)track:(NSString *)name option:(int)option;
+ (void)track:(NSString *)name properties:(NSDictionary *)properties option:(int)option;
+ (void)track:(NSString *)_namespace name:(NSString *)name properties:(NSDictionary *)properties option:(int)option;

+ (void)tag:(NSString *)name;
+ (void)tag:(NSString *)name value:(NSString *)value;
+ (void)tag:(NSString *)_namespace name:(NSString *)name value:(NSString *)value;

+ (void)open;
+ (void)close;
+ (void)purchase:(int)price setCategory:(NSString *)category setProduct:(NSString *)product;

+ (void)setUserId:(NSString *)userId;
+ (void)setName:(NSString *)name;
+ (void)setAge:(int)age;
+ (void)setGender:(int)gender;
+ (void)setLevel:(int)level;
+ (void)setDevelopment:(BOOL)development;
+ (void)setDeviceModel;
+ (void)setOS;
+ (void)setLanguage;
+ (void)setTimeZone;
+ (void)setTimeZoneOffset;
+ (void)setAppVersion;
+ (void)setRandom;
+ (void)setAdvertisingId:(NSString *)idfa;
+ (void)setBasicTags;

@end

#endif // if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
