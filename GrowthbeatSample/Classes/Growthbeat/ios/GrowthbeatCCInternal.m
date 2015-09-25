//
//  GrowthbeatCCInternal.m
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/07.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthbeatCCInternal.h"

@implementation GrowthbeatCCInternal

+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId {
    [[Growthbeat sharedInstance] initializeWithApplicationId:applicationId
                                                     credentialId:credentialId];
}

+ (void)start {
  [[Growthbeat sharedInstance] start];
}

+ (void)stop {
  [[Growthbeat sharedInstance] stop];
}

+ (void)setLoggerSilent:(bool)silent {
  [[Growthbeat sharedInstance] setLoggerSilent:silent];
}

@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */
