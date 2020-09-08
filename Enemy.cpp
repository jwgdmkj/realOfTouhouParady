#include "Enemy.h"

//water setup
void Enemy::setup(float max_enemy_shoot_interval,
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

void Enemy::update(ofPoint player) {
	if (enemymoving == -1)
	{
		pos.y += speed;
		//	pos.y += amplitude * cos(ofGetElapsedTimef());
		//	pos.x += amplitude * sin(ofGetElapsedTimef());
		if (abs(pos.y - middlepoint2) < 8)
			enemymoving = 0;
	}

	actualTime = ofGetElapsedTimef();
	pt = player;

	if (enemymoving != -1)
	{
		// enemymoving = 1;
		//when_tomove = ofRandom(5000, 5200);

		// printf("%f, %d\n", actualTime, enemymoving);
		if ((int)actualTime % 5 == 0 && enemymoving == 0)
		{
			// printf("%f\n", actualTime);
			movex = ofRandom(-100, 100);
			movey = ofRandom(-30, 30);
			// movex = ofRandom(-middlepoint1 / 5,
			// middlepoint1 / 5);
			// movey = ofRandom(-middlepoint2 / 10,
			// middlepoint2 / 10);
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

			if (abs(motox + movex - pos.x) > 1)
			{
				pos.x += movex_speed;
			}
			if (abs(motoy + movey - pos.y) > 1)
			{
				pos.y += movey_speed;
			}


			// printf("%f %f\n", abs(motox + movex - pos.x),
			// abs(motoy + movey - pos.y));
			if (abs(motox + movex - pos.x) <= 1 ||
				abs(motoy + movey - pos.y) <= 1)
			{
				enemymoving = 0;
			}
		}
		checkBoundary();
	}
}

void Enemy::checkBoundary()
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

void Enemy::draw() {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}

bool Enemy::time_to_shoot()
{
	if (ofGetElapsedTimef() - start_shoot > shoot_interval)
	{
		start_shoot = ofGetElapsedTimef();
		return true;
	}

	return false;
}

void Enemy::stage1Bullet(ofPoint player) {
	Bullet b1, b2;
	b1.setup(-1, pos, 10,
		&enemy_bullet_image, 1, pt, 1);
	enemyBullet.push_back(b1);
	b2.setup(-2, pos, 10,
		&enemy_bullet_image, 1, pt, 2);

	enemyBullet.push_back(b2);
}