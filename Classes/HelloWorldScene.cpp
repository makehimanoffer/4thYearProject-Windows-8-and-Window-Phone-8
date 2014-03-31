#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"  


USING_NS_CC;
using namespace RakNet;



enum GameMessages
{
	WELCOME = ID_USER_PACKET_ENUM + 1,
        UPDATE,
        MY_TURN,
        GREEN,
        RED,
        BLUE,
        PURPLE,
        BUZZER

	
};
CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	clientid=1;
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	firstUpdate=0;
	
	

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	/*
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"ButtonNormal.png",
		"ButtonHit.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x +320 ,
		origin.y + 240));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);
	*/
#ifdef WINDOWS_PHONE_8
	CCMenuItemImage *BuzzerButtonObject = CCMenuItemImage::create(
		"BuzzerButtonSmaller.png",
		"BuzzerButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::BuzzerButton));

	BuzzerButtonObject->setPosition(ccp(origin.x +320 ,
		origin.y+ 395));
	
	//this->addChild(BuzzerButtonObject, 1);
	CCMenuItemImage *greenButtonObject = CCMenuItemImage::create(
		"greenButtonSmaller.png",
		"greenButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::greenButton));

	greenButtonObject->setPosition(ccp(origin.x +320 ,
		origin.y+ 285));
	CCMenuItemImage *redButtonObject = CCMenuItemImage::create(
		"redButtonSmaller.png",
		"redButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::redButton));

	redButtonObject->setPosition(ccp(origin.x +320 ,
		origin.y+ 205));

	CCMenuItemImage *blueButtonObject = CCMenuItemImage::create(
		"blueButtonSmaller.png",
		"blueButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::blueButton));

	blueButtonObject->setPosition(ccp(origin.x +320 ,
		origin.y+ 125));
	CCMenuItemImage *purpleButtonObject = CCMenuItemImage::create(
		"purpleButtonSmaller.png",
		"purpleButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::purpleButton));

	purpleButtonObject->setPosition(ccp(origin.x +320 ,
		origin.y+ 45));
#endif
#ifdef WINRT
	CCMenuItemImage *BuzzerButtonObject = CCMenuItemImage::create(
		"BuzzerButton.png",
		"BuzzerButtonHit.png",
		this,
		menu_selector(HelloWorld::BuzzerButton));

	BuzzerButtonObject->setPosition(ccp(origin.x +920 ,
		origin.y+ 800));
	
	//this->addChild(BuzzerButtonObject, 1);
	CCMenuItemImage *greenButtonObject = CCMenuItemImage::create(
		"greenButton.png",
		"greenButtonHit.png",
		this,
		menu_selector(HelloWorld::greenButton));

	greenButtonObject->setPosition(ccp(origin.x +920 ,
		origin.y+ 600));
	CCMenuItemImage *redButtonObject = CCMenuItemImage::create(
		"redButton.png",
		"redButtonHit.png",
		this,
		menu_selector(HelloWorld::redButton));

	redButtonObject->setPosition(ccp(origin.x +920 ,
		origin.y+ 450));

	CCMenuItemImage *blueButtonObject = CCMenuItemImage::create(
		"blueButton.png",
		"blueButtonHit.png",
		this,
		menu_selector(HelloWorld::blueButton));

	blueButtonObject->setPosition(ccp(origin.x +920 ,
		origin.y+ 300));
	CCMenuItemImage *purpleButtonObject = CCMenuItemImage::create(
		"purpleButton.png",
		"purpleButtonHit.png",
		this,
		menu_selector(HelloWorld::purpleButton));

	purpleButtonObject->setPosition(ccp(origin.x +920 ,
		origin.y+ 150));

#endif
	#ifdef WIN32x
	CCMenuItemImage *BuzzerButtonObject = CCMenuItemImage::create(
		"BuzzerButtonSmaller.png",
		"BuzzerButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::BuzzerButton));

	BuzzerButtonObject->setPosition(ccp(origin.x+ 200 ,
		origin.y+ 400));
	
	//this->addChild(BuzzerButtonObject, 1);
	CCMenuItemImage *greenButtonObject = CCMenuItemImage::create(
		"greenButtonSmaller.png",
		"greenButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::greenButton));

	greenButtonObject->setPosition(ccp(origin.x +200,
		origin.y+ 325));
	CCMenuItemImage *redButtonObject = CCMenuItemImage::create(
		"redButtonSmaller.png",
		"redButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::redButton));

	redButtonObject->setPosition(ccp(origin.x+200,
		origin.y+250));

	CCMenuItemImage *blueButtonObject = CCMenuItemImage::create(
		"blueButtonSmaller.png",
		"blueButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::blueButton));

	blueButtonObject->setPosition(ccp(origin.x +200 ,
		origin.y+ 175));
	CCMenuItemImage *purpleButtonObject = CCMenuItemImage::create(
		"purpleButtonSmaller.png",
		"purpleButtonSmallerHit.png",
		this,
		menu_selector(HelloWorld::purpleButton));

	purpleButtonObject->setPosition(ccp(origin.x +200 ,
		origin.y+100));

#endif
	//this->addChild(greenButtonObject, 1);
	CCMenu* pMenu = CCMenu::create(greenButtonObject, NULL);
	pMenu->addChild(BuzzerButtonObject,1,1);
	pMenu->addChild(redButtonObject,1,1);
	pMenu->addChild(blueButtonObject,1,1);
	pMenu->addChild(purpleButtonObject,1,1);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);
	connected=false;
	peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd;
	peer->Startup(1,&sd,1);
	CCLOG("Starting the client.\n");
	ipAddress="172.30.8.209";
	peer->Connect(ipAddress.c_str(), SERVER_PORT, 0,0);
	// add "HelloWorld" splash screen"
	//  CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	// pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(pSprite, 0);
	//this->schedule( schedule_selector( HelloWorld::update ), 1.0 / 20 );
	green=blue=red=purple=buzzer=false;
	this->schedule( schedule_selector(HelloWorld::update) );
	return true;
}

void HelloWorld::update(float dt){
	
	CCLOG("UPDATING");
		for (packet=peer->Receive();packet;peer->DeallocatePacket(packet), packet=peer->Receive())
		{
			CCLOG("getting here");
			//RakSleep(3);
			RakNet::BitStream bsIn(packet->data,packet->length,false);
			bsIn.IgnoreBytes(sizeof(MessageID));
			//bsIn.Read(rs);
			switch (packet->data[0])
			{
			
			case ID_CONNECTION_REQUEST_ACCEPTED:
				connected = true;
				
				break;
			case UPDATE:
				// report the server's new counter value
				//bsIn.Read(currentTime);
				//CCLOG("SYSTEM TIME %i",currentTime);
				if(firstUpdate==0){
					bsIn.Read(clientid);
					firstUpdate++;
				}
				
				if(buzzer){
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("buzzer.wav"); 
				bsOut.Reset();
				
				bsOut.Write((MessageID)BUZZER);
				
				
				buzzer=false;
				}
				else if(green){
					bsOut.Reset();
					bsOut.Write((MessageID)GREEN);
					
					green=false;
				}
				else if(red){
					bsOut.Reset();
					bsOut.Write((MessageID)RED);
					
					red=false;
				}
				else if(blue){
					bsOut.Reset();
					bsOut.Write((MessageID)BLUE);
					
					blue=false;
				}
				else if(purple){
					bsOut.Reset();
					bsOut.Write((MessageID)PURPLE);
					
					purple=false;
				}
				else{
				bsOut.Reset();
				bsOut.Write((MessageID)UPDATE);
				}
				bsOut.Write(clientid);
				peer->Send(&bsOut,HIGH_PRIORITY,RELIABLE_ORDERED,0,packet->systemAddress,false);
				
				break;
			
			default:
				CCLOG("Message with identifier %i has arrived.\n", packet->data[0]);
				break;
			}
			
			
		}
	

	//RakPeerInterface::DestroyInstance(peer);
	
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	//CCLOG("Starting the client.\n");
	peer->Connect("127.0.0.1", SERVER_PORT, 0,0);
	//CCMessageBox("Starting The Client","Alert");
	// CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

void HelloWorld::BuzzerButton(CCObject* pSender)
{
	 
	buzzer=true;
	         
	
				
}

void HelloWorld::greenButton(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
"green.wav"); 
	green=true;
	
}

void HelloWorld::redButton(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
"red.wav"); 
	red=true;
	
	
}
void HelloWorld::blueButton(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
"blue.wav"); 
	blue=true;
	
}
void HelloWorld::purpleButton(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
"purple.wav"); 
	purple=true;
}
