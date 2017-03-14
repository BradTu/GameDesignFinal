//Made by Brad Tully
//10 March 2017
//Intro to Game Design
//Final Project: In this game the player is a reporter that chose to write a negative story about Trump and
//gets sucked into Trump's dream that night where he dreams about dropping bombs on them the player uses
//WASD to avoid the exploding bombs for as long as possible

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		//---------------------------------------Player Class------------------------------------------
		class Player {
			float playerX, playerY, playerWidth, xDif, yDif, distanceSquared;
			bool hit;
		public:
			Player(float theX, float theY);
			Player();
			void draw();
			float getPlayerX();
			float getPlayerY();
			float getPlayerWidth();
			void setPlayerX(float x);
			void setPlayerY(float y);
			void setHit(bool h);
			bool isHitByBomb(float x, float y, float width, bool b);
		};
		//---------------------------------End Player Class---------------------------------------------

		//------------------------------------Bomb Class------------------------------------------------
		class Bomb {
			float bombX, bombY, bombWidth, explosionSize;
			bool isFalling, isExploding;
		public:
			Bomb(float x, float y);
			Bomb();
			void draw();
			float getBombX();
			float getBombY();
			float getBombWidth();
			void setBombX(float x);
			void setBombY(float y);
			void setBombWidth(float theWidth);
			bool falling();
			void exploding(bool tf);
			void setFalling();
			bool isItExploding();
		};
		//---------------------------------End Bomb Class-----------------------------------------------
		
		//Initialize some variables and arrays of bombs to have multiple exploding at once
		int screenX = 400;
		int screenY = 500;
		int score = 0;
		Player thePlayer = Player(screenX / 2, screenY / 2);
		Bomb bombs[10];
		Bomb bombs1[10];
		Bomb bombs2[10];
		Bomb bombs3[10];
		Bomb bombs4[10];
		Bomb bombs5[10];
		Bomb bombs6[10];
		Bomb bombs7[10];
		Bomb bombs8[10];
		Bomb bombs9[10];
		Bomb bombs10[10];
		int incrementBombs;
		bool gameEnd, gameStart;
};
