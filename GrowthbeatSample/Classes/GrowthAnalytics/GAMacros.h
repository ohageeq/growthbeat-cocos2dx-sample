//
//  GAMacros.h
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#ifndef GROWTHANALYTICSPLUGIN_GAMACROS_H_
#define GROWTHANALYTICSPLUGIN_GAMACROS_H_

#ifdef __cplusplus
    #define NS_GROWTHANALYTICS_BEGIN    namespace growthanalytics {
    #define NS_GROWTHANALYTICS_END      }
    #define USING_NS_GROWTHANALYTICS    using namespace growthanalytics
#else
    #define NS_GROWTHANALYTICS_BEGIN
    #define NS_GROWTHANALYTICS_END
    #define USING_NS_GROWTHANALYTICS
#endif

#endif  // GROWTHANALYTICSPLUGIN_GAMACROS_H_
