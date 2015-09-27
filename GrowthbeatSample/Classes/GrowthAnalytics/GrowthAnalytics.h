//
//  GrowthAnalytics.h
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#ifndef GROWTHANALYTICSPLUGIN_GROWTHANALYTICS_H_
#define GROWTHANALYTICSPLUGIN_GROWTHANALYTICS_H_

#include <map>
#include "cocos2d.h"
#include "GAGender.h"
#include "GATrackOption.h"

NS_GROWTHANALYTICS_BEGIN

class CC_DLL GrowthAnalytics
{

public:
    GrowthAnalytics();
    ~GrowthAnalytics();
    static GrowthAnalytics* getInstance();
    void initialize(const std::string& applicationId, const std::string& credentialId);

    void track(const std::string& name);
    void track(const std::string& name, const std::map<std::string, std::string>& properties);
    void track(const std::string& name, GATrackOption option);
    void track(const std::string& name, const std::map<std::string, std::string>& properties, GATrackOption option);
    void track(const std::string& _namespace,const std::string& name, const std::map<std::string, std::string>& properties, GATrackOption option);

    void tag(const std::string& name);
    void tag(const std::string& name, const std::string& value);
    void tag(const std::string& _namespace,const std::string& name, const std::string& value);

    void open(void);
    void close(void);
    void purchase(int price, const std::string& category, const std::string& product);

    void setUserId(const std::string& userId);
    void setName(const std::string& name);
    void setAge(int age);
    void setGender(GAGender gender);
    void setLevel(int level);
    void setDevelopment(bool development);
    void setDeviceModel(void);
    void setOS(void);
    void setLanguage(void);
    void setTimeZone(void);
    void setTimeZoneOffset(void);
    void setAppVersion(void);
    void setRandom(void);
    void setAdvertisingId(const std::string& idfa);
    void setBasicTags(void);

private:
    static GrowthAnalytics* instance;
};

NS_GROWTHANALYTICS_END

#endif	// GROWTHANALYTICSPLUGIN_GROWTHANALYTICS_H_
