#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "Growthbeat.h"
#include "GrowthPush.h"
#include "GrowthbeatCore.h"
#include "GrowthAnalytics.h"
#include "GrowthLink.h"

USING_NS_CC;
USING_NS_GROWTHBEAT;
USING_NS_GROWTHPUSH;
USING_NS_GROWTHBEATCORE;
USING_NS_GROWTHLINK;
USING_NS_GROWTHANALYTICS;

#ifdef COCOS2D_DEBUG
GPEnvironment kGPEnvironment = GPEnvironmentDevelopment;
#else
GPEnvironment kGPEnvironment = GPEnvironmentProduction;
#endif

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    register_all_packages();
    
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();
    
    // run
    director->runWithScene(scene);
    
    // Growthbeat initializing.
    Growthbeat::getInstance()->initialize("PIaD6TaVt7wvKwao", "FD2w93wXcWlb68ILOObsKz5P3af9oVMo");
    GrowthAnalytics::getInstance()->setAge(3);
    GrowthAnalytics::getInstance()->setName("Cocos2d");
    GrowthbeatCore::getInstance()->initializeIntentHandlers();
    GrowthbeatCore::getInstance()->addNoopIntentHandler();
    GrowthbeatCore::getInstance()->addUrlIntentHandler();
    GrowthbeatCore::getInstance()->addCustomIntentHandler([](std::map<std::string,std::string> extra)->bool{
        log("cutomintenthandler called.");
        return true;
    });
    GrowthLink::getInstance()->initialize("PIaD6TaVt7wvKwao", "FD2w93wXcWlb68ILOObsKz5P3af9oVMo");
    GrowthPush::getInstance()->requestDeviceToken("1000565500410", kGPEnvironment);
    GrowthPush::getInstance()->setOpenNotificationCallback(this, gp_remote_notification_selector(AppDelegate::didReceiveRemoteNotification));
    Growthbeat::getInstance()->start();

    GrowthAnalytics::getInstance()->purchase(100, "category", "product");
    GrowthAnalytics::getInstance()->setGender(GAGenderMale);
    
    GrowthAnalytics::getInstance()->track("Full", "CustomEvent", {{"prop","val"}}, GATrackOptionDefault);
    GrowthAnalytics::getInstance()->tag("Full", "CustomTag");
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    
    Growthbeat::getInstance()->stop();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    
    
    Growthbeat::getInstance()->start();
}

void AppDelegate::didReceiveRemoteNotification(cocos2d::Value extra) {
    CCLOG("%s", extra.getDescription().c_str());
}
