#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();

	auto layer = HelloWorld::create();
		
	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();



	_bg = Sprite::create("sample.png");
	_bg->setPosition(Point( visibleSize.width/2, visibleSize.height/2 ));
	this->addChild( _bg, -1 );

	//Hang 1
	_t1 = Sprite::create("stick_hor.png");
	_t1->setAnchorPoint(Point(0, 0));
	_t1->setPosition(Point(400, 600));
	_t1->setTag(11);
	_t1->setVisible(true);
	tick.pushBack(_t1);


	_t2 = Sprite::create("stick_hor.png");
	_t2->setAnchorPoint(Point(0, 0));
	_t2->setPosition(Point(510, 600));
	_t2->setVisible(true);
	_t2->setTag(12);
	tick.pushBack(_t2);


	_t3 = Sprite::create("stick_hor.png");
	_t3->setAnchorPoint(Point(0, 0));
	_t3->setPosition(Point(610, 600));
	_t3->setTag(13);
	_t3->setVisible(true);
	tick.pushBack(_t3);
	//----------------

	_t4 = Sprite::create("stick_ver.png");
	_t4->setAnchorPoint(Point(1, 1));
	_t4->setPosition(Point(400, 600));
	_t4->setTag(21);
	_t4->setVisible(true);
	tick.pushBack(_t4);
	_t5 = Sprite::create("stick_ver.png");
	_t5->setAnchorPoint(Point(1, 1));
	_t5->setPosition(Point(400, 490));
	_t5->setTag(22);
	_t5->setVisible(true);
	tick.pushBack(_t5);

	_t6 = Sprite::create("stick_ver.png");
	_t6->setAnchorPoint(Point(1, 1));
	_t6->setPosition(Point(400, 380));
	_t6->setTag(23);
	_t6->setVisible(true);
	tick.pushBack(_t6);


	_t7 = Sprite::create("stick_hor.png");
	_t7->setAnchorPoint(Point(0, 0));
	_t7->setPosition(Point(400, 270));
	_t7->setTag(31);
	_t7->setVisible(true);
	tick.pushBack(_t7);


	_t8 = Sprite::create("stick_hor.png");
	_t8->setAnchorPoint(Point(0, 0));
	_t8->setPosition(Point(510, 270));
	_t8->setTag(32);
	_t8->setVisible(true);
	tick.pushBack(_t8);

	_t9 = Sprite::create("stick_hor.png");
	_t9->setAnchorPoint(Point(0, 0));
	_t9->setPosition(Point(620, 270));
	_t9->setTag(33);
	_t9->setVisible(true);
	tick.pushBack(_t9);


	this->addChild( _t3, 1 );

	this->addChild( _t1, 1 );
	this->addChild( _t2, 1 );
	this->addChild( _t4, 1 );
	this->addChild( _t5, 1 );
	this->addChild( _t6, 1 );
	this->addChild(  _t7,1);
	this->addChild( _t8,1 );
	this->addChild( _t9,1 );

	T.pushBack(_t1);
	T.pushBack(_t2);

	sumTick = tick.size();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2( HelloWorld::onTouchBegan, this );
	listener->onTouchMoved = CC_CALLBACK_2( HelloWorld::onTouchMoved, this );
	listener->onTouchEnded = CC_CALLBACK_2( HelloWorld::onTouchEnded, this );

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );

	this->scheduleUpdate();

	return true;
}


void HelloWorld::update( float dt )
{

	


}

void HelloWorld::checkkq()
{
	for (auto t : tick)
	{

		if (t->getTag() ==11 && t->getTag() ==12 && t->getTag() ==13)
		{
			log("WINNNN");
		}

	}

}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	Point locationInNode = touch->getLocationInView();
	locationInNode = Director::getInstance()->convertToGL(locationInNode);


	for(int i =0; i< tick.size(); i++)
	{
		if(tick.at(i)->boundingBox().containsPoint(locationInNode))
		{
			tick.at(i)->setVisible(false);
			sumTick--;
			log("SUM : %d", sumTick);
			log("tick is remove : %d", tick.at(i)->getTag());
			
		}

				
	}
	if (tick.at(0) && tick.at(3)->boundingBox().containsPoint(locationInNode) )
	{
		if ((tick.at(0)->getTag() ==11 && tick.at(3)->getTag() == 21) )
		{
		log("win");
		}
		

	}


	//for (auto t : tick)
	//{
	//	
	//	if (t->boundingBox().containsPoint(locationInNode) )
	//	{
	//		t = tick.at(2);
	//		auto t1 = tick.at(3);

	//		t->setVisible(false);

	//		log("tick is remove : %d", t->getTag());
	//		log("tick is remove : %d", t1->getTag());
	//		sumTick--;
	//		log("indexTick : %d", sumTick);
	//		//ktr = (int)t->getTag();
	//		
	//		/*if (tick.at(0)->getTag() == 11 && tick.at(1)->getTag()==12  )
	//		{
	//		log( "win" );

	//		}*/

	//		
	//	}

	//}			

	/*t1 = tick.at(0);
	t2 = tick.at(1);
	t3 =tick.at(2);

	if ((t1->boundingBox().containsPoint(locationInNode)))
	{
		t1->setVisible(false);
		T.pushBack(t1);
		log("tick is remove : %d", t1->getTag());
	}

	else if ((t2->boundingBox().containsPoint(locationInNode)))
	{
		t2->setVisible(false);
		T.pushBack(t2);
		
		log("tick is remove : %d", t2->getTag());
	}
	else if ((t3->boundingBox().containsPoint(locationInNode)))
	{
		t3->setVisible(false);
		T.pushBack(t3);
		log("tick is remove : %d", t3->getTag());
	}

	if (t1 && t2 && t3->boundingBox().containsPoint(locationInNode))
	{
		if (t1->getTag()==11 && t2->getTag()==12 && t3->getTag()==13)
		{
			log("win");
		}
		
	}*/
	
	
	

	

return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{


}

void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{

	Point locationInNode = touch->getLocationInView();
	locationInNode = Director::getInstance()->convertToGL(locationInNode);

	
	



}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
