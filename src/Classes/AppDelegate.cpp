#include "AppDelegate.h"
#include "base/ChapterManager.h"

USING_NS_CC;

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

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    Director* director = Director::getInstance();
    GLView* glview = director->getOpenGLView();

    if (!glview) {
        glview = GLViewImpl::createWithFullScreen("Cape of Helius");
        director->setOpenGLView(glview);
    }

    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("characters/zoe-nocape.plist");
    cache->addSpriteFramesWithFile("characters/father.plist");
    cache->addSpriteFramesWithFile("characters/mother.plist");
    cache->addSpriteFramesWithFile("characters/anouk.plist");
    cache->addSpriteFramesWithFile("characters/martine.plist");
    cache->addSpriteFramesWithFile("hud/hud.plist");
    cache->addSpriteFramesWithFile("tiles/items.plist");
    cache->addSpriteFramesWithFile("enemies/enemies.plist");

    // turn off display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object && run
    ChapterManager::getInstance()->init();
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
