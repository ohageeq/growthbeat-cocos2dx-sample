//
//  GbMacros.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/07.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#ifndef __GROWTHBEATPLUGIN_GBMACROS_H__
#define __GROWTHBEATPLUGIN_GBMACROS_H__

#ifdef __cplusplus
    #define NS_GROWTHBEAT_BEGIN namespace growthbeat {
    #define NS_GROWTHBEAT_END   }
    #define USING_NS_GROWTHBEAT using namespace growthbeat
#else
    #define NS_GROWTHBEAT_BEGIN
    #define NS_GROWTHBEAT_END
    #define USING_NS_GROWTHBEAT
#endif

#endif  // __GROWTHBEATPLUGIN_GBMACROS_H__
