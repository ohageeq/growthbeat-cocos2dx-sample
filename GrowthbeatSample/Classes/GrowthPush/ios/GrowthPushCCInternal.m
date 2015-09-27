//
//  GrowthPushCCInternal.m
//
//  Created by TSURUDA Ryo on 2013/12/09.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthPushCCInternal.h"

#import <Growthbeat/GrowthPush.h>

static void (^s_didReceiveRemoteNotificationBlock)(NSString *json) = NULL;

@implementation GrowthPushCCInternal

- (void) dealloc {

    if (s_didReceiveRemoteNotificationBlock) {
        Block_release(s_didReceiveRemoteNotificationBlock);
        s_didReceiveRemoteNotificationBlock = NULL;
    }
    [super dealloc];

}

+ (void) requestDeviceTokenWithEnvironment:(int)environment {
    [[GrowthPush sharedInstance] requestDeviceTokenWithEnvironment:[self convertIntToGPEnvironment:environment]];
}

+ (void) trackEvent:(NSString *)name {
    [[GrowthPush sharedInstance] trackEvent:name];
}

+ (void) trackEvent:(NSString *)name value:(NSString *)value {
    [[GrowthPush sharedInstance] trackEvent:name value:value];
}

+ (void) setTag:(NSString *)name {
    [[GrowthPush sharedInstance] setTag:name];
}

+ (void) setTag:(NSString *)name value:(NSString *)value {
    [[GrowthPush sharedInstance] setTag:name value:value];
}

+ (void) setDeviceTags {
    [[GrowthPush sharedInstance] setDeviceTags];
}

+ (void) clearBadge {
    [[GrowthPush sharedInstance] clearBadge];
}

+ (void) setDidReceiveNotificationBlock:(void (^)(NSString *json))block {

    if (s_didReceiveRemoteNotificationBlock) {
        Block_release(s_didReceiveRemoteNotificationBlock);
    }
    s_didReceiveRemoteNotificationBlock = Block_copy(block);

}

#pragma mark -
#pragma UIApplicationDelegate hook methods

+ (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    NSDictionary *userInfo = [launchOptions objectForKey:UIApplicationLaunchOptionsRemoteNotificationKey];

    if (userInfo) {
        [self invokeLaunchWithNotificationCallback:userInfo];
    }

    return YES;

}

+ (void) application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [[GrowthPush sharedInstance] setDeviceToken:deviceToken];
}

+ (void) application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    [[GrowthPush sharedInstance] setDeviceToken:nil];
}

+ (void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {

    if (application.applicationState == UIApplicationStateActive) {
        return;
    }

    [self invokeLaunchWithNotificationCallback:userInfo];

}

+ (void) invokeLaunchWithNotificationCallback:(NSDictionary *)userInfo {

    if (!s_didReceiveRemoteNotificationBlock) {
        return;
    }

    NSError *error = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:userInfo options:0 error:&error];
    if (error) {
        NSLog(@"failed to parse json: error=%@", [error description]);
        return;
    }

    NSString *json = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    if (json) {
        s_didReceiveRemoteNotificationBlock(json);
    }

}

+ (GPEnvironment) convertIntToGPEnvironment:(int)environment {

    switch (environment) {
        case 1:
            return GPEnvironmentDevelopment;
        case 2:
            return GPEnvironmentProduction;
        default:
            return GPEnvironmentUnknown;
    }

}

@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */
