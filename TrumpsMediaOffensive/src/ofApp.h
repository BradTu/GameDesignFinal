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
			void setPlayerX(float x);
			void setPlayerY(float y);
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
		


		Player thePlayer = Player(200, 250);
		Bomb bombs[10];
		Bomb bombs1[10];
		Bomb bombs2[10];
		Bomb bombs3[10];
		int incrementBombs;
		bool gameEnd;
};
