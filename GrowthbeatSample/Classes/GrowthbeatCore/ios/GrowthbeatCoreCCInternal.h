//
//  GrowthbeatCoreCCInternal.h
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/16.
//
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/GrowthbeatCore.h>
#import <Growthbeat/GBCustomIntentHandler.h>
#import <Growthbeat/GBUrlIntentHandler.h>
#import <Growthbeat/GBNoopIntentHandler.h>

@interface GrowthbeatCoreCCInternal : NSObject

+ (void)initializeIntentHandlers;

+ (void)addNoopIntentHandler;

+ (void)addUrlIntentHandler;

+ (void)addCustomIntentHandlerWithBlock:(BOOL(^)(GBCustomIntent *customIntent))block;


@end

#endif