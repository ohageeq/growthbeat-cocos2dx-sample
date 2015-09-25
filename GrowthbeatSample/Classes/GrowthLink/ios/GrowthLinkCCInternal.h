//
//  GrowthLinkCCInternal.h
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/07.
//
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/Growthbeat.h>
#import <GrowthLink/GrowthLink.h>
@interface GrowthLinkCCInternal : NSObject

+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId;

+ (void) handleOpenUrl:(NSString *)urlString;

@end

#endif
