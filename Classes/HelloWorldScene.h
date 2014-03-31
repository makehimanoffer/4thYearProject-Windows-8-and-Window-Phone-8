#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

#include <RakPeerInterface.h>

#include <RakNetTypes.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakSleep.h>
#define MAX_CLIENTS 10
#define SERVER_PORT 60000
using namespace std;



class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void BuzzerButton(CCObject* pBuzzerButton);
	void redButton(CCObject* pRedButton);
	void blueButton(CCObject* pBlueButton);
	void greenButton(CCObject* pGreenButton);
	void purpleButton(CCObject* pPurpleButton);
	void update(float dt);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	
	char str[512];
	RakNet::RakPeerInterface *peer;
	RakNet::Packet *packet;
	void printDataMessages(char);
	bool connected;
	RakNet::RakString rs;
	int int_message;
	RakNet::BitStream bsOut;
	bool red,green,blue,purple,buzzer;
	time_t currentTime;
	int clientid;
	int firstUpdate;
	string ipAddress;
};

#endif // __HELLOWORLD_SCENE_H__
