#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ThreadEmulation.h"
#include <stdio.h>

#include "RakPeerInterface.h"

#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include "BitStream.h"
#define MAX_CLIENTS 10
#define SERVER_PORT 60000



class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	void update();
	char str[512];
	RakNet::RakPeerInterface *peer;
	RakNet::Packet *packet;
	void printDataMessages(char);
};

#endif // __HELLOWORLD_SCENE_H__
