//
//  GrowthLinkInstance.cpp
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/07.
//
//

#include "GrowthLink.h"

NS_GROWTHLINK_BEGIN

GrowthLink* GrowthLink::instance = new GrowthLink();

GrowthLink::~GrowthLink() {
    instance = NULL;
}

GrowthLink* GrowthLink::getInstance() {
    return instance;
}

NS_GROWTHLINK_END
