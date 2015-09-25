//
//  GrowthbeatCoreInstance.cpp
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/17.
//
//

#include "GrowthbeatCore.h"

NS_GROWTHBEATCORE_BEGIN

GrowthbeatCore* GrowthbeatCore::instance = new GrowthbeatCore();

GrowthbeatCore::~GrowthbeatCore() {
    instance = NULL;
}

GrowthbeatCore* GrowthbeatCore::getInstance() {
    return instance;
}

NS_GROWTHBEATCORE_END
