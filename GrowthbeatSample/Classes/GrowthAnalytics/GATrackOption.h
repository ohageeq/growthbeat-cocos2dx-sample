//
//  GATrackOption.h
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#ifndef __GROWTHANALYTICSPLUGIN_GATRACKOPTION_H__
#define __GROWTHANALYTICSPLUGIN_GATRACKOPTION_H__

#include "GAMacros.h"

NS_GROWTHANALYTICS_BEGIN

typedef enum GATrackOption {
    GATrackOptionDefault = 0,
    GATrackOptionOnce = 1,
    GATrackOptionCounter = 2,
} GATrackOption;

NS_GROWTHANALYTICS_END

#endif // __GROWTHANALYTICSPLUGIN_GATRACKOPTION_H__
