#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Bullet.h"
#include "Life.h"
#include "EnemyParent.h"
#include "stage2.h"
#include "stage3.h"
#include "Enemy.h"
#include "LevelController.h"
#include "bomb.h"
#include "ofxGif.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEnterd(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void update_bullets();
	void limitPlayer(ofPoint * point);
	void check_bullet_collisions();
	void draw_lives();
	void draw_score();
	void reset_game();
	void ofToggleFullscreen();
	void check_bullet_out();
	bool visiblecenter=false;

	string game_state;
	int score;
	float max_enemy_amplitude;
	float max_enemy_shoot_interval;
	int buttonnum;
	int lobbybutton;
	int stageNum;
	float leftscreen=ofGetWidth()/20;
	float rightscreen=55*(ofGetWidth()/100);
	float upscreen=ofGetHeight()/13;
	float downscreen=11*(ofGetHeight()/13);
	float middlepoint1 = (leftscreen + rightscreen) / 2;
	float middlepoint2 = 4 * upscreen;
	float lefthealbar = 2 * leftscreen;;
	float righthealthbar = rightscreen - leftscreen -
		ofGetWidth()/50;
	float realhealthbar;

	Player player_1;
//	vector<Bullet> bullets;
	Bullet manage_bullet;
	EnemyParent enemies;
	Enemy stg1;
	stage2 stg2;
	stage3 stg3;
	LevelController level_controller;

	ofPoint player_start;

	ofImage player_image;
//	ofImage enemy_bullet_image;
	ofImage player_bullet_image;
	ofImage enemy_image;
	ofImage enemy_image2;
	ofImage enemy_image3;
	ofImage start_screen;
	ofImage end_screen;
	ofImage lobby_screen;
	ofImage center_image;
	ofImage start_button;
	ofImage exit_button;
	ofImage instructer;
	ofImage stage1image;
	ofImage stage2image;
	ofImage stage3image;
	ofImage closeimage;

	ofSoundPlayer player_bullet_sound;

	ofTrueTypeFont score_font;
};