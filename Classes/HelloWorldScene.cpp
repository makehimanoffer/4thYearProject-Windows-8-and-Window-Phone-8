#include "HelloWorldScene.h"

USING_NS_CC;
using namespace RakNet;



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
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
	
	
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
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

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("David Ryan's Cocos 2d-x Game", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
	peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd;
	peer->Startup(1,&sd,1);
    // add "HelloWorld" splash screen"
  //  CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
   // pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(pSprite, 0);
	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(){
	while (1)
	{
		for (packet=peer->Receive(); packet; peer->DeallocatePacket(packet), packet=peer->Receive())
		{
			printDataMessages(packet->data[0]);
		}
	}
	RakNet::RakPeerInterface::DestroyInstance(peer);

	
}
void HelloWorld::printDataMessages(char data)
{

	switch (data)
				{
				case ID_REMOTE_DISCONNECTION_NOTIFICATION:
					CCMessageBox("Another client has disconnected.\n","Alert");
					break;
				case ID_REMOTE_CONNECTION_LOST:
					CCMessageBox("Another client has lost the connection.\n","Alert");
					break;
				case ID_REMOTE_NEW_INCOMING_CONNECTION:
					CCMessageBox("Another client has connected.\n","Alert");
					break;
				case ID_CONNECTION_REQUEST_ACCEPTED:
					CCMessageBox("Our connection request has been accepted.\n","Alert");
					break;					
				case ID_NEW_INCOMING_CONNECTION:
					CCMessageBox("A connection is incoming.\n","Alert");
					break;
				case ID_NO_FREE_INCOMING_CONNECTIONS:
					CCMessageBox("The server is full.\n","Alert");
					break;
				case ID_DISCONNECTION_NOTIFICATION:
					
						CCMessageBox("We have been disconnected.\n","Alert");
					
					break;
				case ID_CONNECTION_LOST:
					CCMessageBox("Connection lost.\n","Alert");
					
					break;
				default:
					CCMessageBox("Message with identifier data has arrived","Alert");
					break;
				}

}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	//printf("Starting the client.\n");
		peer->Connect("127.0.0.1", SERVER_PORT, 0,0);
	//CCMessageBox("Starting The Client","Alert");
   // CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
