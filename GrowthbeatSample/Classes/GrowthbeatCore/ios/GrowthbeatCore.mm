//
//  GrowthbeatCore.mm
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/16.
//
//
#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "GrowthbeatCore.h"

#import "GrowthbeatCoreCCInternal.h"

USING_NS_CC;

growthbeatcore::GrowthbeatCore::GrowthbeatCore() {};

void growthbeatcore::GrowthbeatCore::initializeIntentHandlers(){
    [GrowthbeatCoreCCInternal initializeIntentHandlers];
}
void growthbeatcore::GrowthbeatCore::addNoopIntentHandler(){
    [GrowthbeatCoreCCInternal addNoopIntentHandler];

}
void growthbeatcore::GrowthbeatCore::addUrlIntentHandler(){
    [GrowthbeatCoreCCInternal addUrlIntentHandler];

}
void growthbeatcore::GrowthbeatCore::addCustomIntentHandler(const OnHandle& handle){
    [GrowthbeatCoreCCInternal addCustomIntentHandlerWithBlock:^BOOL (GBCustomIntent *customIntent){
        NSDictionary *dict = customIntent.extra;
        std::map<std::string,std::string> extraMap;
        for (NSString *key in [dict allKeys]) {
            NSString *value= [dict objectForKey:key];
            extraMap[[key UTF8String]] = [value UTF8String];
        }
        return handle(extraMap);
    }];
    

}



#endif
