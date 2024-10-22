//
//  GrowthPushCCInternal.h
//
//  Created by TSURUDA Ryo on 2013/12/09.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/GPEnvironment.h>

@interface GrowthPushCCInternal : NSObject

/* GrowthPush SDK interface */
+ (void)requestDeviceTokenWithEnvironment:(int)environment;
+ (void)trackEvent:(NSString *)name;
+ (void)trackEvent:(NSString *)name value:(NSString *)value;
+ (void)setTag:(NSString *)name;
+ (void)setTag:(NSString *)name value:(NSString *)value;
+ (void)setDeviceTags;
+ (void)clearBadge;

/* ANPs callback method */
+ (void)setDidReceiveNotificationBlock:(void(^) (NSString * json))block;

/* UIApplicationDelegate methods */
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

@end

#endif // if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
