#include "Flag.h"

USING_NS_CC;

Flag* Flag::create(cocos2d::Vec2 position) {
	Flag* flag = new Flag(position);
	if (flag && flag->initWithSpriteFrameName("flagRed.png")) {
		flag->autorelease();
		flag->start();
		return flag;
	}
	CC_SAFE_DELETE(flag);
	return nullptr;
}

Flag::Flag(Vec2 postion) {
	this->setPosition(postion);
}

void Flag::start() {
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(2);
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	animFrames.pushBack(cache->getSpriteFrameByName("flagRed.png"));
	animFrames.pushBack(cache->getSpriteFrameByName("flagRed2.png"));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 1.0f);
	Animate* animate = Animate::create(animation);
	this->runAction(RepeatForever::create(animate));
}

void Flag::stop() {
	this->stopAllActions();
}