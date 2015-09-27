//
//  GrowthAnalyticsCCInternal.m
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthAnalyticsCCInternal.h"

@implementation GrowthAnalyticsCCInternal

+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId {
    [[GrowthAnalytics sharedInstance] initializeWithApplicationId:applicationId
                                                     credentialId:credentialId];
}

+ (void)track:(NSString *)name {
    [[GrowthAnalytics sharedInstance] track:name];
}
+ (void)track:(NSString *)name properties:(NSDictionary *)properties {
    [[GrowthAnalytics sharedInstance] track:name
                                 properties:properties];
}
+ (void)track:(NSString *)name option:(int)option {
    [[GrowthAnalytics sharedInstance] track:name
                                     option:[self convertIntToGATrackOption:option]];
}
+ (void)track:(NSString *)name properties:(NSDictionary *)properties option:(int)option {
    [[GrowthAnalytics sharedInstance] track:name
                                 properties:properties
                                     option:[self convertIntToGATrackOption:option]];
}
+ (void)track:(NSString *)_namespace name:(NSString *)name properties:(NSDictionary *)properties option:(int)option {
    [[GrowthAnalytics sharedInstance] track:_namespace
                                       name:name
                                 properties:properties
                                     option:[self convertIntToGATrackOption:option]
                                 completion:nil];
}

+ (void)tag:(NSString *)name {
    [[GrowthAnalytics sharedInstance] tag:name];
}
+ (void)tag:(NSString *)name value:(NSString *)value {
    [[GrowthAnalytics sharedInstance] tag:name
                                    value:value];
}
+ (void)tag:(NSString *)_namespace name:(NSString *)name value:(NSString *)value {
    [[GrowthAnalytics sharedInstance] tag:_namespace name:name value:value completion:nil];
}

+ (void)open {
    [[GrowthAnalytics sharedInstance] open];
}
+ (void)close {
    [[GrowthAnalytics sharedInstance] close];
}
+ (void)purchase:(int)price setCategory:(NSString *)category setProduct:(NSString *)product {
    [[GrowthAnalytics sharedInstance] purchase:price
                                   setCategory:category
                                    setProduct:product];
}

+ (void)setUserId:(NSString *)userId {
    [[GrowthAnalytics sharedInstance] setUserId:userId];
}
+ (void)setName:(NSString *)name {
    [[GrowthAnalytics sharedInstance] setName:name];
}
+ (void)setAge:(int)age {
    [[GrowthAnalytics sharedInstance] setAge:age];
}
+ (void)setGender:(int)gender {
    [[GrowthAnalytics sharedInstance] setGender:[self convertIntToGAGender:gender]];
}
+ (void)setLevel:(int)level {
    [[GrowthAnalytics sharedInstance] setLevel:level];
}
+ (void)setDevelopment:(BOOL)development {
    [[GrowthAnalytics sharedInstance] setDevelopment:development];
}
+ (void)setDeviceModel {
    [[GrowthAnalytics sharedInstance] setDeviceModel];
}
+ (void)setOS {
    [[GrowthAnalytics sharedInstance] setOS];
}
+ (void)setLanguage {
    [[GrowthAnalytics sharedInstance] setLanguage];
}
+ (void)setTimeZone {
    [[GrowthAnalytics sharedInstance] setTimeZone];
}
+ (void)setTimeZoneOffset {
    [[GrowthAnalytics sharedInstance] setTimeZoneOffset];
}
+ (void)setAppVersion {
    [[GrowthAnalytics sharedInstance] setAppVersion];
}
+ (void)setRandom {
    [[GrowthAnalytics sharedInstance] setRandom];
}
+ (void)setAdvertisingId:(NSString *)idfa {
    [[GrowthAnalytics sharedInstance] setAdvertisingId];
}
+ (void)setBasicTags {
    [[GrowthAnalytics sharedInstance] setBasicTags];
}

+ (GAGender) convertIntToGAGender:(int)gender {
    
    switch (gender) {
            
        case 1:
            return GAGenderMale;
            
        case 2:
            return GAGenderFemale;
            
        default:
            return GAGenderNone;
            
    }
    
}

+ (GATrackOption) convertIntToGATrackOption:(int)option {
    
    switch (option) {
            
        case 1:
            return GATrackOptionOnce;
            
        case 2:
            return GATrackOptionCounter;
            
        default:
            return GATrackOptionDefault;
            
    }
    
}

@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */
