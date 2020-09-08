#include "ofApp.h"

void ofApp::setup() {
	//게임판 설치
	game_state = "start";
	score = 0;

	max_enemy_amplitude = 3.0;
	max_enemy_shoot_interval = 1.5;

	player_image.load("images/player.png");
	player_bullet_image.load("images/player_bullet.png");
	center_image.load("images/Center.png");
	//	player_bullet_sound.load("sounds/player_bullet.mp3");
	enemy_image.load("images/enemy.png");
	enemy_image2.load("images/enemy2.png");
	enemy_image3.load("images/enemy3.png");
//	enemy_bullet_image.load("images/enemy_bullet.png");
	start_button.load("images/start_button.png");
	exit_button.load("images/exit.png");
	instructer.load("images/Enemy_bullet2.png");
	stage1image.load("images/stage1.png");
	stage2image.load("images/stage2.png");
	stage3image.load("images/stage3.png");
	closeimage.load("images/clear.png");

	player_start.set(256, 650);

	float width = 50;
	float height = 50;

	player_1.setup(&player_image, player_start, visiblecenter,
		&center_image);
//	enemies.setup(max_enemy_shoot_interval, &enemy_image);

	start_screen.load("images/startScreen.png");
	end_screen.load("images/end_screen.png");
	score_font.load("fonts/steelworks_vintage.otf", 48);
	lobby_screen.load("images/lobby_image.png");
	//	ofSetFrameRate(15);

	//	ofSetLineWidth(4);
}

void ofApp::update() {
	if (game_state == "start")
	{

	}

	else if (game_state == "lobby")
	{

	}

	else if (game_state == "game")
	{
		player_1.update(visiblecenter);
		player_1.limitPlayer();
		update_bullets();

//		enemies.update();

		switch (stageNum) {
		case 1:
			stg1.update(player_1.pos);
		//	printf("%d\n", stg1.nowhealth);
			if (stg1.nowhealth < 0) {
				game_state = "clear";
			}
			break;
		case 2:
			stg2.update();
			if (stg2.enemyhealth < 0)
				game_state = "clear";
			break;
		case 3:
			stg3.update(player_1.pos);
			if (stg3.enemyhealth < 0)
				game_state = "clear";
			break;
		}
		
//		if (enemies.time_to_shoot() && enemies.enemymoving >= 0)
//		{
//			Bullet b;
//			b.setup(0, enemies.pos, enemies.speed,
//				&enemy_bullet_image);
//			bullets.push_back(b);
//		}
//		if (stg2.time_to_shoot())
		switch(stageNum)
		{
			case 1: 
				if (stg1.time_to_shoot())
				stg1.stage1Bullet(player_1.pos);
				//			b.setup(0, enemies.pos, enemies.speed,
				//				&enemy_bullet_image);
				//			bullets.push_back(b);
				break;
			case 2:
				if (stg2.time_to_shoot())
				stg2.stage2Bullet(player_1.pos);
				break;
			case 3:
				if (stg3.time_to_shoot())
				stg3.stage3Bullet(player_1.pos);
				break;
		}
		
	}

	else if (game_state == "end")
	{
	}

	else if (game_state == "clear") {

	}
}

void ofApp::draw() {
	if (game_state == "start")
	{
		start_screen.draw(0, 0);
		start_button.draw(ofGetWidth() / 3, ofGetHeight() / 3);
		exit_button.draw(ofGetWidth() / 3,
			70 + ofGetHeight() / 3);

		if (buttonnum == 0)
			instructer.draw(ofGetWidth() / 3 - 20,
				30 + ofGetHeight() / 3);
		else
			instructer.draw(ofGetWidth() / 3 - 20,
				100 + ofGetHeight() / 3);
	}

	if (game_state == "lobby")
	{
		lobby_screen.draw(0, 0);
		stage1image.draw(2 * ofGetWidth() / 3, ofGetHeight() / 8);
		stage2image.draw(2 * ofGetWidth() / 3,
			80 + ofGetHeight() / 8);
		stage3image.draw(2 * ofGetWidth() / 3,
			160 + ofGetHeight() / 8);

		if (lobbybutton == 0)
			instructer.draw(2 * ofGetWidth() / 3 - 20,
				30 + ofGetHeight() / 8);
		else if (lobbybutton == 1)
			instructer.draw(2 * ofGetWidth() / 3 - 20,
				110 + ofGetHeight() / 8);
		else if (lobbybutton == 2)
			instructer.draw(2 * ofGetWidth() / 3 - 20,
				190 + ofGetHeight() / 8);

	}

	else if (game_state == "game")
	{
		ofBackground(0, 0, 0);
		ofDrawRectangle(leftscreen, upscreen,
			rightscreen, downscreen);
		ofSetColor(255, 0, 0);
		switch (stageNum) {
		case 1:
			ofDrawRectangle(lefthealbar, upscreen + ofGetHeight() / 70,
				(righthealthbar / stg1.enemyhealth)*stg1.nowhealth,
				ofGetHeight() / 150);
			break;
		case 2:
			ofDrawRectangle(lefthealbar, upscreen + ofGetHeight() / 70,
				(righthealthbar / stg2.enemyhealth)*stg2.nowhealth,
				ofGetHeight() / 150);
			break;
		case 3:
			ofDrawRectangle(lefthealbar, upscreen + ofGetHeight() / 70,
				(righthealthbar / stg3.enemyhealth)*stg3.nowhealth,
				ofGetHeight() / 150);
			break;
		}

		ofSetColor(255, 255, 255);

		switch (stageNum) {
		case 1:
			stg1.draw();
			break;
		case 2:
			stg2.draw();
			break;
		case 3:
			stg3.draw();
			break;
		}
		//	enemies.draw();

		for (int i = 0; i < manage_bullet.bullet.size(); ++i)
			manage_bullet.bullet[i].draw();

		switch (stageNum) {
		case 1:
			for (int i = 0; i < stg1.enemyBullet.size(); ++i) {
				stg1.enemyBullet[i].draw();
			}
			break;
		case 2:
			for (int i = 0; i < stg2.enemyBullet.size(); ++i) {
				stg2.enemyBullet[i].draw();
			}
			break;
		case 3:
			for (int i = 0; i < stg3.enemyBullet.size(); ++i) {
				stg3.enemyBullet[i].draw();
			}
			break;
		}

		player_1.draw(visiblecenter);
		draw_score();
		draw_lives();
	}

	else if (game_state == "end")
		end_screen.draw(0, 0);

	else if (game_state == "clear")
		closeimage.draw(0, 0);
}

void ofApp::keyPressed(int key) {
	if (game_state == "start")
	{
		if (key == OF_KEY_DOWN)
		{
			buttonnum++;
			if (buttonnum > 2)
				buttonnum = 1;
		}
		if (key == OF_KEY_UP)
		{
			buttonnum--;
			if (buttonnum < 0)
				buttonnum = 0;
		}
	}

	if (game_state == "lobby")
	{
		if (key == OF_KEY_DOWN)
		{
			lobbybutton++;
			if (lobbybutton > 3)
				lobbybutton = 2;
		}
		if (key == OF_KEY_UP)
		{
			lobbybutton--;
			if (lobbybutton < 0)
				lobbybutton = 0;
		}
	}

	if (game_state == "game")
	{
		if (key == OF_KEY_LEFT)
			player_1.is_left_pressed = true;
		if (key == OF_KEY_RIGHT)
			player_1.is_right_pressed = true;
		if (key == OF_KEY_UP)
			player_1.is_up_pressed = true;
		if (key == OF_KEY_DOWN)
			player_1.is_down_pressed = true;

		if (key == OF_KEY_SHIFT)
		{
			player_1.speed = 1.5;
			visiblecenter = true;
		}

		if (key == ' ')
		{
			Bullet b1;
			Bullet b2;
			Bullet b3;

			b1.setup(1, player_1.pos, 10,
				&player_bullet_image, 0, player_1.pos, 0);
			b2.setup(2, player_1.pos, 10,
				&player_bullet_image, 0, player_1.pos, 0);
			b3.setup(3, player_1.pos, 10,
				&player_bullet_image, 0, player_1.pos, 0);

			manage_bullet.bullet.push_back(b1);
			manage_bullet.bullet.push_back(b2);
			manage_bullet.bullet.push_back(b3);
		//	bullets.push_back(b1);
		//	bullets.push_back(b2);
		//	bullets.push_back(b3);
			//	player_bullet_sound.play();
		}
	}
}

void ofApp::keyReleased(int key) {
	if (game_state == "start")
	{
		if (buttonnum == 0 && key == OF_KEY_RETURN)
		{
			game_state = "lobby";
		}

		else if (buttonnum == 1 && key == OF_KEY_RETURN)
		{
			game_state = "end";
		}
	}

	else if (game_state == "lobby")
	{
		if (lobbybutton == 0 && key == OF_KEY_RETURN)
		{
			game_state = "game";
			stg1.setup(max_enemy_shoot_interval, &enemy_image
			, player_1.pos);
			level_controller.setup(ofGetElapsedTimeMillis());
			stageNum = 1;
		}

		if (lobbybutton == 1 && key == OF_KEY_RETURN)
		{
			game_state = "game";
			stg2.setup(max_enemy_shoot_interval, &enemy_image2
				, player_1.pos);
			level_controller.setup(ofGetElapsedTimeMillis());
			stageNum = 2;
		}

		if (lobbybutton == 2 && key == OF_KEY_RETURN)
		{
			game_state = "game";
			stg3.setup(max_enemy_shoot_interval, &enemy_image3
				, player_1.pos);
			level_controller.setup(ofGetElapsedTimeMillis());
			stageNum = 3;
		}
	}

	if (game_state == "game")
	{
		if (key == OF_KEY_LEFT)
			player_1.is_left_pressed = false;
		if (key == OF_KEY_RIGHT)
			player_1.is_right_pressed = false;
		if (key == OF_KEY_UP)
			player_1.is_up_pressed = false;
		if (key == OF_KEY_DOWN)
			player_1.is_down_pressed = false;

		if (key == OF_KEY_SHIFT)
		{
			player_1.speed = 3;
			visiblecenter = false;
		}
	}

	if (game_state == "end")
	{
		if (key == OF_KEY_RETURN)
		{
			game_state = "lobby";
		}
	}

	if (game_state == "clear")
	{
		if (key == OF_KEY_RETURN)
		{
			game_state = "start";
		}
	}
}

void ofApp::update_bullets()
{
	for (int i = 0; i < manage_bullet.bullet.size(); i++)
	{
		manage_bullet.bullet[i].update();
//		if (bullets[i].pos.y - bullets[i].width / 2 < 0
//			|| bullets[i].pos.y + bullets[i].width / 2 >
//			ofGetHeight())
//		{
//			bullets.erase(bullets.begin() + i);
//		}
	}

	switch (stageNum) {
	case 1:
		for (int i = 0; i < stg1.enemyBullet.size(); i++)
		{
			stg1.enemyBullet[i].update();
		}
		break;
	case 2:
		for (int i = 0; i < stg2.enemyBullet.size(); i++)
		{
			stg2.enemyBullet[i].update();
		}
		break;
	case 3:
		for (int i = 0; i < stg3.enemyBullet.size(); i++)
		{
			stg3.enemyBullet[i].update();
		}
		break;
	}

	check_bullet_collisions();
	check_bullet_out();
}

//checkcollision이 참일 때, 해당 water을 vector내에서 erase
void ofApp::check_bullet_collisions()
{
//	for (int i = 0; i < manage_bullet.bullet.size(); i++) {
//		if (ofDist(manage_bullet.bullet[i].pos.x, manage_bullet.bullet[i].pos.y,
//				stg2.pos.x, stg2.pos.y) <
//				(stg2.width + manage_bullet.bullet[i].width) / 2) {
				//enemies.erase(enemies.begin() + e);
//				stg2.nowhealth--;
//				manage_bullet.bullet.erase(manage_bullet.bullet.begin() + i);
//				score += 10;
//		}
//	}

	switch (stageNum) {
	case 1:
		for (int i = 0; i < manage_bullet.bullet.size(); i++) {
			if (ofDist(manage_bullet.bullet[i].pos.x, manage_bullet.bullet[i].pos.y,
				stg1.pos.x, stg1.pos.y) <
				(stg1.width + manage_bullet.bullet[i].width) / 2) {
				//enemies.erase(enemies.begin() + e);
				stg1.nowhealth--;
				manage_bullet.bullet.erase(manage_bullet.bullet.begin() + i);
				score += 10;
			}
		}
		for(int i=0; i<stg1.enemyBullet.size(); ++i)
		if (ofDist(stg1.enemyBullet[i].pos.x, stg1.enemyBullet[i].pos.y,
			player_1.pos.x, player_1.pos.y)
			< (stg1.enemyBullet[i].width + player_1.centerwidth) / 2)
		{
			stg1.enemyBullet.erase(stg1.enemyBullet.begin() + i);
			player_1.lives--;

			if (player_1.lives <= 0)
				game_state = "end";
		}
		break;
	case 2:
		for (int i = 0; i < manage_bullet.bullet.size(); i++) {
			if (ofDist(manage_bullet.bullet[i].pos.x, manage_bullet.bullet[i].pos.y,
				stg2.pos.x, stg2.pos.y) <
				(stg2.width + manage_bullet.bullet[i].width) / 2) {
				//enemies.erase(enemies.begin() + e);
				stg2.nowhealth--;
				manage_bullet.bullet.erase(manage_bullet.bullet.begin() + i);
				score += 10;
			}
		}

		for (int i = 0; i < stg2.enemyBullet.size(); ++i)
			if (ofDist(stg2.enemyBullet[i].pos.x, stg2.enemyBullet[i].pos.y,
				player_1.pos.x, player_1.pos.y)
				< (stg2.enemyBullet[i].width + player_1.centerwidth) / 2)
			{
				stg2.enemyBullet.erase(stg2.enemyBullet.begin() + i);
				player_1.lives--;

				if (player_1.lives <= 0)
					game_state = "end";
			}
		break;
	case 3:
		for (int i = 0; i < manage_bullet.bullet.size(); i++) {
			if (ofDist(manage_bullet.bullet[i].pos.x, manage_bullet.bullet[i].pos.y,
				stg3.pos.x, stg3.pos.y) <
				(stg3.width + manage_bullet.bullet[i].width) / 2) {
				//enemies.erase(enemies.begin() + e);
				stg3.nowhealth--;
				manage_bullet.bullet.erase(manage_bullet.bullet.begin() + i);
				score += 10;
			}
		}
		for (int i = 0; i < stg3.enemyBullet.size(); ++i)
			if (ofDist(stg3.enemyBullet[i].pos.x, stg3.enemyBullet[i].pos.y,
				player_1.pos.x, player_1.pos.y)
				< (stg3.enemyBullet[i].width + player_1.centerwidth) / 2)
			{
				stg3.enemyBullet.erase(stg3.enemyBullet.begin() + i);
				player_1.lives--;

				if (player_1.lives <= 0)
					game_state = "end";
			}
		break;
	}
}

void ofApp::check_bullet_out()
{
	for (int i = 0; i < manage_bullet.bullet.size(); i++)
	{
		if (manage_bullet.bullet[i].pos.x > rightscreen + leftscreen
			|| manage_bullet.bullet[i].pos.x < leftscreen ||
			manage_bullet.bullet[i].pos.y > upscreen + downscreen ||
			manage_bullet.bullet[i].pos.y < upscreen) {
	//		printf("pl %f\n", manage_bullet.bullet[i].pos.y);
			manage_bullet.bullet.erase(manage_bullet.bullet.begin() + i);
		}
	}

	switch (stageNum) {
	case 1:
		for (int i = 0; i < stg1.enemyBullet.size(); i++) {
			if (stg1.enemyBullet[i].pos.x > rightscreen + leftscreen
				|| stg1.enemyBullet[i].pos.x < leftscreen ||
				stg1.enemyBullet[i].pos.y > upscreen + downscreen ||
				stg1.enemyBullet[i].pos.y < upscreen)
				stg1.enemyBullet.erase(stg1.enemyBullet.begin() + i);
		}
		break;
	case 2:
		for (int i = 0; i < stg2.enemyBullet.size(); i++) {
			if (stg2.enemyBullet[i].pos.x > rightscreen + leftscreen
				|| stg2.enemyBullet[i].pos.x < leftscreen ||
				stg2.enemyBullet[i].pos.y > upscreen + downscreen ||
				stg2.enemyBullet[i].pos.y < upscreen) {
				stg2.enemyBullet.erase(stg2.enemyBullet.begin() + i);
			}
		}
		break;
	case 3:
		for (int i = 0; i < stg3.enemyBullet.size(); ++i) {
			if (stg3.enemyBullet[i].pos.x > rightscreen + leftscreen
				|| stg3.enemyBullet[i].pos.x < leftscreen ||
				stg3.enemyBullet[i].pos.y > upscreen + downscreen ||
				stg3.enemyBullet[i].pos.y < upscreen)
				stg3.enemyBullet.erase(stg3.enemyBullet.begin() + i);
		}
		break;
	}
}

void ofApp::draw_lives()
{
	for (int i = 0; i < player_1.lives; i++) {
		player_image.draw(ofGetWidth()
			- (i * player_image.getWidth()) - 100, 30);
	}
}

void ofApp::draw_score()
{
	if (game_state == "game")
		score_font.drawString(ofToString(score),
			9 * ofGetWidth() / 10, ofGetHeight() / 4);
	else if (game_state == "end")
	{
		float w = score_font.stringWidth(ofToString(score));
		score_font.drawString(ofToString(score), ofGetWidth() / 2
			- w / 2, ofGetHeight() / 2 + 100);
	}
}

void ofApp::reset_game()
{

}

void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}