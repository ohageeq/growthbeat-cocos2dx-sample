//
//  GrowthbeatCore.h
//  growthbeat-cocos2dx
//  GrowthbeatCocos2dxSample
//
//  Created by TABATAKATSUTOSHI on 2015/09/16.
//
//

#ifndef GROWTHBEATCOREPLUGIN_GROWTHBEATCORE_H_
#define GROWTHBEATCOREPLUGIN_GROWTHBEATCORE_H_
#include "cocos2d.h"
#include "GBCMacros.h"

NS_GROWTHBEATCORE_BEGIN
typedef std::function<bool(std::map<std::string,std::string>)> OnHandle;

class CC_DLL GrowthbeatCore
{
public:
    
    GrowthbeatCore();
    ~GrowthbeatCore();
    static GrowthbeatCore* getInstance();
    void initializeIntentHandlers();
    void addNoopIntentHandler();
    void addUrlIntentHandler();
    void addCustomIntentHandler(const OnHandle& handle);
    
private:
    OnHandle _handle;
    static GrowthbeatCore* instance;

};

NS_GROWTHBEATCORE_END

#endif

