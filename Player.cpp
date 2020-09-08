#include "Player.h"

//�÷��̾� �¾�.
void Player::setup(ofImage * _img, ofPoint _pos, 
	bool visiblecenter, ofImage * _center)
{
	img = _img;
	height = img->getHeight();
	width = img->getWidth();
	pos.set(_pos);
	collisionpos.set(pos.x - width / 3, pos.y);
	speed = 3;
	lives = 5;
	visible = visiblecenter;
	center = _center;
	centerwidth = center->getWidth();
}

//������Ʈ��, �����̳� �������̳Ŀ� ���� player�� xpos�� ������ 30������
void Player::update(bool visible) {
	if (is_up_pressed)
		pos.y -= speed;
	if (is_down_pressed)
		pos.y += speed;
	if (is_left_pressed)
		pos.x -= speed;
	if (is_right_pressed)
		pos.x += speed;
}

void Player::limitPlayer()
{
	if (pos.x < leftscreen + (img->getWidth()) / 2)
		pos.x = leftscreen + (img->getWidth()) / 2;
	if (pos.x > leftscreen + rightscreen - (img->getWidth()) / 2)
		pos.x = leftscreen + rightscreen -(img->getWidth()) / 2;
	if (pos.y < upscreen + (img->getHeight()) / 2)
		pos.y = upscreen + (img->getHeight())/2;
	if (pos.y > upscreen + downscreen - (img->getHeight()) / 2)
		pos.y = upscreen + downscreen - (img->getHeight()) / 2;
}

//�÷��̾� �׸���
void Player::draw(bool visible) 
{
	img->draw(pos.x - width / 2, pos.y - height / 2);
	if (visible)
		center->draw(pos.x-width/3, pos.y);
}

void Player::shoot() 
{
}
