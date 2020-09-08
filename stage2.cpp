#include "stage2.h"
#include <functional>
#include <windows.h>

//water setup
void stage2::setup(float max_enemy_shoot_interval,
	ofImage * enemy_img, ofPoint player)
{
	enemy_bullet_image.load("images/enemy_bullet.png");
	img = enemy_img;
	width = img->getWidth();
	height = img->getHeight();
	pos.x = middlepoint1;
	pos.y = middlepoint2 - 4 * height;
	speed = 8;
	//	amplitude = ofRandom(max_enemy_amplitude);
	shoot_interval = ofRandom(0.5, max_enemy_shoot_interval);

	start_shoot = ofGetElapsedTimef();
	enemymoving = -1;
	pt = player;
}

void stage2::update() {
	if (enemymoving == -1)
	{
		pos.y += speed;
		//	pos.y += amplitude * cos(ofGetElapsedTimef());
		//	pos.x += amplitude * sin(ofGetElapsedTimef());
		if (abs(pos.y - middlepoint2) < 8)
			enemymoving = 0;
	}

	actualTime = ofGetElapsedTimef();

	if (enemymoving != -1)
	{
		if ((int)actualTime % 5 == 0 && enemymoving == 0)
		{
			movex = ofRandom(-100, 100);
			movey = ofRandom(-30, 30);
			//	movex = ofRandom(-middlepoint1 / 5,
			//		middlepoint1 / 5);
			//	movey = ofRandom(-middlepoint2 / 10,
			//		middlepoint2 / 10);
			motox = pos.x;
			motoy = pos.y;
			enemymoving = 1;
		}

		if (enemymoving == 1)
		{
			if (movex < 0)
				movex_speed = -1;
			else
				movex_speed = 1;

			if (movey < 0)
				movey_speed = -1;
			else
				movey_speed = 1;

			//		printf("%f, %f, %f, %f,  %d %d\n",
			//			abs(motox-movex), pos.x,
			//			abs(motoy - movey), pos.y,
			//			movex_speed, movey_speed);
				//	while (abs(motox+movex-pos.x) > 1 &&
			//			abs(motoy+movey-pos.y) > 1)
			if (abs(motox + movex - pos.x) > 1)
			{
				pos.x += movex_speed;
			}
			if (abs(motoy + movey - pos.y) > 1)
			{
				pos.y += movey_speed;
			}

			if (abs(motox + movex - pos.x) <= 1 ||
				abs(motoy + movey - pos.y) <= 1)
			{
				enemymoving = 0;
			}
		}
		checkBoundary();
	}
}

void stage2::checkBoundary()
{
	if (pos.x < leftscreen + (img->getWidth()) / 2)
		pos.x = leftscreen + (img->getWidth()) / 2;
	if (pos.x > leftscreen + rightscreen - (img->getWidth()) / 2)
		pos.x = leftscreen + rightscreen - (img->getWidth()) / 2;
	if (pos.y < upscreen + (img->getHeight()) / 2)
		pos.y = upscreen + (img->getHeight()) / 2;
	if (pos.y > upscreen + downscreen - (img->getHeight()) / 2)
		pos.y = upscreen + downscreen - (img->getHeight()) / 2;
}

void stage2::draw() {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}

bool stage2::time_to_shoot()
{
	if (ofGetElapsedTimef() - start_shoot > shoot_interval)
	{
		start_shoot = ofGetElapsedTimef();
		return true;
	}

	return false;
}

void stage2::stage2Bullet(ofPoint player) {
	Bullet b1, b2, b3, b4, b5, b6, b7, b8;
	b1.setup(-1, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	enemyBullet.push_back(b1);
	b2.setup(-2, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	b3.setup(-3, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	b4.setup(-4, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	b5.setup(-5, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	b6.setup(-6, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	b7.setup(-7, pos, 10,
		&enemy_bullet_image, 2, pt, 0);
	b8.setup(-8, pos, 10,
		&enemy_bullet_image, 2, pt, 0);

	enemyBullet.push_back(b2);
	enemyBullet.push_back(b3);
	enemyBullet.push_back(b4);
	enemyBullet.push_back(b5);
	enemyBullet.push_back(b6);
	enemyBullet.push_back(b7);
	enemyBullet.push_back(b8);
}