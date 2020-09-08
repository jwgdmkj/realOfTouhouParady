#pragma once
#ifndef Bullet_h
#define Bullet_h

#include <stdio.h>
#include <math.h>
#include "ofMain.h"

class Bullet{
public:
	ofPoint pos;
	float speed;
	float width;
	int from_player;
	int stg;
	int direct;
	ofPoint rightpos;
	ofPoint leftpos;
	ofPoint anotherpos;
	vector<Bullet> bullet;
	float leftscreen = ofGetWidth() / 20;
	float rightscreen = 55 * (ofGetWidth() / 100);

	void setup(int f_p, ofPoint p1, 
		float s, ofImage * bullet_img, 
		int stgNum, ofPoint player, int direct);
	void update();
	void draw();

	ofImage* img;
	ofPoint play;
}; 

#endif