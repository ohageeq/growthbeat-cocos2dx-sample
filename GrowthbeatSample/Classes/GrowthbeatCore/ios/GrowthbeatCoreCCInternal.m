//
//  GrowthbeatCoreCCInternal.m
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/16.
//
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthbeatCoreCCInternal.h"

@implementation GrowthbeatCoreCCInternal


+ (void)initializeIntentHandlers{
    [GrowthbeatCore sharedInstance].intentHandlers = [NSMutableArray array];
}

+ (void)addNoopIntentHandler{
    NSMutableArray *mutableArray = [[GrowthbeatCore sharedInstance].intentHandlers mutableCopy];
    [mutableArray addObject:[[GBNoopIntentHandler alloc] init]];
    [GrowthbeatCore sharedInstance].intentHandlers = mutableArray;
}

+ (void)addUrlIntentHandler{
    NSMutableArray *mutableArray = [[GrowthbeatCore sharedInstance].intentHandlers mutableCopy];
    [mutableArray addObject:[[GBUrlIntentHandler alloc] init]];
    [GrowthbeatCore sharedInstance].intentHandlers = mutableArray;
}

+ (void)addCustomIntentHandlerWithBlock:(BOOL(^)(GBCustomIntent *customIntent))block{
    NSMutableArray *mutableArray = [[GrowthbeatCore sharedInstance].intentHandlers mutableCopy];
    [mutableArray addObject:[[GBCustomIntentHandler alloc] initWithBlock:block]];
    [GrowthbeatCore sharedInstance].intentHandlers = mutableArray;
}


@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */