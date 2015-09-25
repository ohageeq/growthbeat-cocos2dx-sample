//
//  GrowthLinkPlugin.h
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/15.
//
//
#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>

@interface UIApplication(SupressWarnings)

- (BOOL)application:(UIApplication *)application linkOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end
#endif
