//
//  GrowthLink.h
//  growthbeat-cocos2dx
//
//  Created by TABATAKATSUTOSHI on 2015/09/07.
//
//

#ifndef GROWTHLINKPLUGIN_GROWTHLINK_H_
#define GROWTHLINKPLUGIN_GROWTHLINK_H_
#include "cocos2d.h"
#include "GLMacros.h"

NS_GROWTHLINK_BEGIN

class CC_DLL GrowthLink
{
public:
    
    GrowthLink();
    ~GrowthLink();
    static GrowthLink* getInstance();
    
    void initialize(const std::string& applicationId, const std::string& credentialId);
    void handleOpenUrl(const std::string& url);
    
private:
    static GrowthLink* instance;
};

NS_GROWTHLINK_END

#endif
