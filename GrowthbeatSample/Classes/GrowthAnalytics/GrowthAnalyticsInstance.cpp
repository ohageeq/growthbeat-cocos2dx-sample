//
//  GrowthAnalytics.cpp
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "GrowthAnalytics.h"

NS_GROWTHANALYTICS_BEGIN

GrowthAnalytics* GrowthAnalytics::instance = new GrowthAnalytics();

GrowthAnalytics::~GrowthAnalytics() {
	instance = NULL;
}

GrowthAnalytics* GrowthAnalytics::getInstance() {
    return instance;
}

NS_GROWTHANALYTICS_END
