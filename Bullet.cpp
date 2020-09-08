#include "Bullet.h"

void Bullet::setup(int fp, ofPoint p, float s, 
	ofImage * bullet_img, int stgNum, ofPoint player, int direction)
{
	from_player = fp;
	pos = p;
	speed = s;
	img = bullet_img;
	width = img->getWidth();
	stg = stgNum;
	play = player;
	anotherpos = p;
	direct = direction;

	if (stg == 1) {
		if (fp == -1) {
			pos.y = play.y;
			pos.x = leftscreen + 10;
		}
		if (fp == -2) {
			pos.y = play.y;
			pos.x = rightscreen - 10;
		}
	}
}

void Bullet::update()
{
	if (stg == 0)
	{
		switch (from_player) {
		case 1:
			pos.y -= speed;
			break;
		case 2:
			pos.y -= speed;
			pos.x += speed / 10;
			break;
		case 3:
			pos.y -= speed;
			pos.x -= speed / 10;
			break;
		}
	}
	else if (stg == 1)
	{
		switch (from_player) {
		case -1:
			pos.x += speed;
			break;
		case -2:
			pos.x -= speed;
			break;
		}
	}
	else if (stg == 2)
	{
		switch (from_player) {
		case -1:
			pos.y += speed;
			break;
		case -2:
			pos.x += speed;
			break;
		case -3:
			pos.y -= speed;
			break;
		case -4:
			pos.x -= speed;
			break;
		case -5:
			pos.y += speed;
			pos.x += speed;
			break;
		case -6:
			pos.y += speed;
			pos.x -= speed;
			break;
		case -7:
			pos.y -= speed;
			pos.x += speed;
			break;
		case -8:
			pos.x -= speed;
			pos.y -= speed;
			break;
		}
	}
	else if (stg == 3)
	{
		switch (from_player) {
		case -1: pos.y -= (anotherpos.y - play.y) / speed;
			pos.x -= (anotherpos.x - play.x) / speed;
	//		printf("%f %f %f %f \n", play.x, anotherpos.x - play.x, play.y, anotherpos.y - play.y);
			break;
		}
	}
}

void Bullet::draw() {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}