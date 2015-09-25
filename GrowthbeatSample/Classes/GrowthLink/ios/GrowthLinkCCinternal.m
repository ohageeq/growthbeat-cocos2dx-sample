//
//  GrowthLinkCCInternal.m
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/07.
//
//


#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthLinkCCInternal.h"

@implementation GrowthLinkCCInternal


+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId{
    [[GrowthLink sharedInstance] initializeWithApplicationId:applicationId credentialId:credentialId];
}

+ (void) handleOpenUrl:(NSString *)urlString{
    [[GrowthLink sharedInstance] handleOpenUrl:[NSURL URLWithString:urlString]];
}

@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */

