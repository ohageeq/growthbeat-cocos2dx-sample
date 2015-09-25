//
//  GrowthbeatInstance.cpp
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/03.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "Growthbeat.h"

NS_GROWTHBEAT_BEGIN

Growthbeat* Growthbeat::instance = new Growthbeat();

Growthbeat::~Growthbeat() {
	instance = NULL;
}

Growthbeat* Growthbeat::getInstance() {
    return instance;
}

NS_GROWTHBEAT_END
