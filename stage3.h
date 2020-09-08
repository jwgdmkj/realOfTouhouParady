#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "EnemyParent.h"

class stage3 : public EnemyParent{
public:

	ofPoint pos;
	float speed;
	float amplitude;
	float width;
	float height;

	float start_shoot;
	float shoot_interval;
	float when_tomove;
	float actualTime;
	int movex_speed = 1;
	int movey_speed = 1;
	float movex;
	float movey;
	float motox;
	float motoy;

	void setup(float max_enemy_shoot_interval,
		ofImage * enemy_image, ofPoint player);
	void update(ofPoint player);
	void draw();
	bool time_to_shoot();
	void checkBoundary();
	void stage3Bullet(ofPoint player);

	float leftscreen = ofGetWidth() / 20;
	float rightscreen = 55 * (ofGetWidth() / 100);
	float upscreen = ofGetHeight() / 13;
	float downscreen = 11 * (ofGetHeight() / 13);
	float middlepoint1 = leftscreen + (rightscreen) / 2;
	float middlepoint2 = 3 * upscreen;
	int enemymoving = -1;
	int enemyhealth = 100;
	int nowhealth = enemyhealth;

	ofImage * img;
	ofPoint pt;
};