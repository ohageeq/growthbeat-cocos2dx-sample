//
//  Growthbeat.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/03.
//  Copyright (c) 2015 SIROK Inc. All rights reserved.
//

#ifndef __GROWTHBEATPLUGIN_GROWTHBEAT_H__
#define __GROWTHBEATPLUGIN_GROWTHBEAT_H__

#include "cocos2d.h"
#include "GbMacros.h"

NS_GROWTHBEAT_BEGIN

class CC_DLL Growthbeat
{
public:

	Growthbeat();
	~Growthbeat();
	static Growthbeat* getInstance();

	void initialize(const std::string &applicationId, const std::string &secret);

	void start();

	void stop();

	void setLoggerSilent(bool silent);

private:
 	static Growthbeat* instance;
};

NS_GROWTHBEAT_END

#endif  // __GROWTHBEATPLUGIN_GROWTHBEAT_H__
