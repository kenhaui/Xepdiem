#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;


enum
{
	TICK11,
	TICK12,
	TICK13,
	TICK21,
	TICK22,
	TICK23,
	TICK24,
	TICK31,
	TICK32,
	TICK33,
	TICK41,
	TICK42,
	TICK43,
	TICK44,
	TICK51,
	TICK52,
	TICK53,
	TICK61,
	TICK62,
	TICK63,
	TICK64,
	TICK71,
	TICK72,
	TICK73


};

class HelloWorld : public cocos2d::Layer
{
public:
	unsigned int ktr;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	void update( float dt );
	void checkkq();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
	
	unsigned int sumTick;
	Vector<Sprite*> tick;
	Vector<Sprite*> T;
	Vector<Sprite*> T1;
	
	Sprite *_bg;
	Sprite *_t1;
	Sprite *_t2, *_t3 , *_t4, *_t5,*_t6,*_t7,*_t8, *_t9, *_t10,*_t11,*_t12;
	Sprite *t1,*t2,*t3;

};

#endif // __HELLOWORLD_SCENE_H__
