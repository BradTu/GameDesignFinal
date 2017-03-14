//Made by Brad Tully
//10 March 2017
//Intro to Game Design
//Final Project: In this game the player is a reporter that chose to write a negative story about Trump and
//gets sucked into Trump's dream that night where he dreams about dropping bombs on them the player uses
//WASD to avoid the exploding bombs for as long as possible

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(27, 194, 12);
	ofSetFrameRate(30);
	ofSetCircleResolution(100);
	gameEnd = false;
	gameStart = false;
	incrementBombs = 0;
	//Give all the bombs random starting locations
	for (int i = 0; i < 10; i++) {
		bombs[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs1[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs2[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs3[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs4[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs5[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs6[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs7[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs8[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs9[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
		bombs10[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	//Start the game
	if (gameStart == true) {
		//if the last element of the bomb arrays is reached start over at element 0
		if (incrementBombs == 9) {
			incrementBombs = 0;
			//Reset the bombs coordinates and set them back to falling
			for (int i = 0; i < 10; i++) {
				bombs[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs1[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs2[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs3[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs4[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs5[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs6[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs7[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs8[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs9[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs10[i] = Bomb(ofRandom(0, screenX), ofRandom(0, screenY));
				bombs[i].setFalling();
				bombs1[i].setFalling();
				bombs2[i].setFalling();
				bombs3[i].setFalling();
				bombs4[i].setFalling();
				bombs5[i].setFalling();
				bombs6[i].setFalling();
				bombs7[i].setFalling();
				bombs8[i].setFalling();
				bombs9[i].setFalling();
				bombs10[i].setFalling();
			}
		}
		//Track whether or not the player has collided with an exploding bomb
		gameEnd = thePlayer.isHitByBomb(bombs[incrementBombs].getBombX(), bombs[incrementBombs].getBombY(),
			bombs[incrementBombs].getBombWidth(), bombs[incrementBombs].isItExploding());
		gameEnd = thePlayer.isHitByBomb(bombs1[incrementBombs].getBombX(), bombs1[incrementBombs].getBombY(),
			bombs1[incrementBombs].getBombWidth(), bombs1[incrementBombs].isItExploding());
		gameEnd = thePlayer.isHitByBomb(bombs2[incrementBombs].getBombX(), bombs2[incrementBombs].getBombY(),
			bombs2[incrementBombs].getBombWidth(), bombs2[incrementBombs].isItExploding());
		gameEnd = thePlayer.isHitByBomb(bombs3[incrementBombs].getBombX(), bombs3[incrementBombs].getBombY(),
			bombs3[incrementBombs].getBombWidth(), bombs3[incrementBombs].isItExploding());
		gameEnd = thePlayer.isHitByBomb(bombs4[incrementBombs].getBombX(), bombs4[incrementBombs].getBombY(),
			bombs4[incrementBombs].getBombWidth(), bombs4[incrementBombs].isItExploding());
		gameEnd = thePlayer.isHitByBomb(bombs5[incrementBombs].getBombX(), bombs5[incrementBombs].getBombY(),
			bombs5[incrementBombs].getBombWidth(), bombs5[incrementBombs].isItExploding());
		gameEnd = thePlayer.isHitByBomb(bombs6[incrementBombs].getBombX(), bombs6[incrementBombs].getBombY(),
			bombs6[incrementBombs].getBombWidth(), bombs6[incrementBombs].isItExploding());
		if (score >= 2500) {
			gameEnd = thePlayer.isHitByBomb(bombs7[incrementBombs].getBombX(), bombs7[incrementBombs].getBombY(),
				bombs7[incrementBombs].getBombWidth(), bombs7[incrementBombs].isItExploding());
			gameEnd = thePlayer.isHitByBomb(bombs8[incrementBombs].getBombX(), bombs8[incrementBombs].getBombY(),
				bombs8[incrementBombs].getBombWidth(), bombs8[incrementBombs].isItExploding());
		}
		if (score >= 5000) {
			gameEnd = thePlayer.isHitByBomb(bombs9[incrementBombs].getBombX(), bombs9[incrementBombs].getBombY(),
				bombs9[incrementBombs].getBombWidth(), bombs9[incrementBombs].isItExploding());
			gameEnd = thePlayer.isHitByBomb(bombs10[incrementBombs].getBombX(), bombs10[incrementBombs].getBombY(),
				bombs10[incrementBombs].getBombWidth(), bombs10[incrementBombs].isItExploding());
		}
		//Keep track of the bombs falling/ exploding status
		bombs[incrementBombs].exploding(bombs[incrementBombs].falling());
		bombs1[incrementBombs].exploding(bombs1[incrementBombs].falling());
		bombs2[incrementBombs].exploding(bombs2[incrementBombs].falling());
		bombs3[incrementBombs].exploding(bombs3[incrementBombs].falling());
		bombs4[incrementBombs].exploding(bombs4[incrementBombs].falling());
		bombs5[incrementBombs].exploding(bombs5[incrementBombs].falling());
		bombs6[incrementBombs].exploding(bombs6[incrementBombs].falling());
		if (score >= 2500) {
			bombs7[incrementBombs].exploding(bombs7[incrementBombs].falling());
			bombs8[incrementBombs].exploding(bombs8[incrementBombs].falling());
		}
		if (score >= 5000) {
			bombs9[incrementBombs].exploding(bombs9[incrementBombs].falling());
			bombs10[incrementBombs].exploding(bombs10[incrementBombs].falling());
		}
		//Increment through the bomb arrays after the bombs have finished exploding
		if (bombs[incrementBombs].getBombX() == 5000) {
			incrementBombs = incrementBombs + 1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw the hills on the background
	ofSetColor(21, 119, 29);
	ofNoFill();
	ofDrawBezier(50, 200, 90, 180, 130, 180, 170, 200);
	ofDrawBezier(200, 400, 240, 380, 280, 380, 320, 400);
	ofDrawBezier(200, 50, 240, 30, 280, 30, 320, 50);
	ofFill();
	//When the game is started
	if (gameStart == true) {
		//Draw the bombs
		if (gameEnd == false) {
			thePlayer.draw();
			bombs[incrementBombs].draw();
			bombs1[incrementBombs].draw();
			bombs2[incrementBombs].draw();
			bombs3[incrementBombs].draw();
			bombs4[incrementBombs].draw();
			bombs5[incrementBombs].draw();
			bombs6[incrementBombs].draw();
			if (score >= 2500) {
				bombs7[incrementBombs].draw();
				bombs8[incrementBombs].draw();
			}
			if (score >= 5000) {
				bombs9[incrementBombs].draw();
				bombs10[incrementBombs].draw();
			}
			score = score + 2;
		}
		//If the player lost print out the losing statement and final score
		else if (gameEnd == true) {
			ofSetColor(255, 255, 255);
			ofDrawBitmapString("Score: ", 250, 15);
			ofDrawBitmapString(score, 300, 15);
			ofDrawBitmapString("'You're a L-O-S-E-R, I'm a WINNER!'", 75, 215);
			ofDrawBitmapString("-Donald Trump", 150, 230);
			
			ofSetColor(255, 0, 0);
			ofDrawRectangle(205, 245, 75, 20);
			ofSetColor(255, 255, 255);
			ofDrawBitmapString("Restart", 175, 250);
		}
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Score: ", 250, 15);
		ofDrawBitmapString(score, 300, 15);
	}
	//Starting splash screen
	if (gameStart == false) {
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Do your job as a journalist and write", 75, 225);
		ofDrawBitmapString("a critical article about and Trump get on", 60, 240);
		ofDrawBitmapString("his bad side?", 150, 255);
		ofSetColor(252, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(screenX / 2, 275, 50, 15);
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Yes", screenX / 2 - 15, 280);
		ofDrawBitmapString("(He has access to the most powerful military ever)", 0, 300);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (gameStart == true) {
		//move the player up and don't let them cross the screen boundary
		if (key == 'w') {
			if (thePlayer.getPlayerY() <= 15) {
				thePlayer.setPlayerY(10 + thePlayer.getPlayerWidth());
			}
			else {
				thePlayer.setPlayerY(thePlayer.getPlayerY() - 20);
			}
		}
		//Move the player down and don't let them cross the screen boundary
		if (key == 's') {
			if (thePlayer.getPlayerY() >= screenY - 15) {
				thePlayer.setPlayerY(screenY - thePlayer.getPlayerWidth() - 10);
			}
			else {
				thePlayer.setPlayerY(thePlayer.getPlayerY() + 20);
			}
		}
		//Move the player left and don't let them cross the screen boundary
		if (key == 'a') {
			if (thePlayer.getPlayerX() <= 15) {
				thePlayer.setPlayerX(10 + thePlayer.getPlayerWidth());
			}
			else {
				thePlayer.setPlayerX(thePlayer.getPlayerX() - 20);
			}
		}
		//Move the player right and don't let them cross the screen boundary
		if (key == 'd') {
			if (thePlayer.getPlayerX() >= screenX - 15) {
				thePlayer.setPlayerX(screenX - thePlayer.getPlayerWidth() - 10);
			}
			else {
				thePlayer.setPlayerX(thePlayer.getPlayerX() + 20);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//Track whether or not the player pressed the "Yes" button on the start splash screen
	if (gameStart == false && x <= screenX / 2 + 25 && x >= screenX / 2 - 25 && y <= 275 + 7.5 && y >= 275 - 7.5) {
		gameStart = true;
		gameEnd = false;
	}
	//Track whether or not the player pressed the "Restart" button on the end game spash screen
	if (gameEnd == true && x <= 205 + 75 / 2 && x >= 205 - 75 / 2 && y <= 255 && y >= 235) {
		gameEnd = false;
		thePlayer.setPlayerX(screenX / 2);
		thePlayer.setPlayerY(screenY / 2);
		thePlayer.setHit(false);
		incrementBombs = 9;
		score = 0;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//-------------------------------------------------------------------------------------------------------------------
//----------------------------------------Player class methods-------------------------------------------------------

//Player argument constructor
ofApp::Player::Player(float theX, float theY) {
	playerX = theX;
	playerY = theY;
	playerWidth = 10;
	hit = false;
}

//No argument constructor
ofApp::Player::Player() {

}

//Draws the player on the screen
void ofApp::Player::draw() {
	//Base of player character
	ofSetColor(222, 196, 166);
	ofDrawCircle(playerX, playerY, playerWidth);
	//Face features
	ofSetColor(0, 0, 0);
	//Mouth
	ofDrawCircle(playerX, playerY + 4, 4);
	//Eyes R/L
	ofDrawCircle(playerX + 3, playerY - 3, 2);
	ofDrawCircle(playerX - 3, playerY - 3, 2);
}

//Return player X coordinate
float ofApp::Player::getPlayerX() {
	return playerX;
}

//Return player Y coordinate
float ofApp::Player::getPlayerY() {
	return playerY;
}

//Returns the width of the player
float ofApp::Player::getPlayerWidth() {
	return playerWidth;
}

//Set player's X coordinate
void ofApp::Player::setPlayerX(float x) {
	playerX = x;
}

//Set player's Y coordinate
void ofApp::Player::setPlayerY(float y) {
	playerY = y;
}

//Reset the hit value to restart game
void ofApp::Player::setHit(bool h) {
	hit = h;
}

//Tells whether or not the player is hit by a bomb
bool ofApp::Player::isHitByBomb(float x, float y, float width, bool b) {
	xDif = playerX - x;
	yDif = playerY - y;
	distanceSquared = xDif * xDif + yDif * yDif;
	if ((distanceSquared < (playerWidth + width) * (playerWidth + width)) && b == true) {
		hit = true;
	}
	return hit;
}
//-------------------------------------------------End Player Class Methods---------------------------------------------


//-----------------------------------------------------Bomb Class Methods-----------------------------------------------

//Class argument constructor
ofApp::Bomb::Bomb(float x, float y) {
	bombX = x;
	bombY = y;
	bombWidth = 30;
	isFalling = true;
	isExploding = false;
	explosionSize = 30 + floor(ofRandom(0, 70));
}

//No argument constructor
ofApp::Bomb::Bomb() {

}

//Draws the bomb
void ofApp::Bomb::draw() {
	if (isFalling == true) {
		//bomb base grey
		ofSetColor(175, 175, 175);
		ofDrawCircle(bombX, bombY, bombWidth);
		//bomb flame center orange
		ofSetColor(252, 160, 0);
		ofDrawCircle(bombX, bombY, bombWidth / 3);
		//fins on bombs red
		ofSetColor(255, 0, 0);
		ofDrawCircle(bombX + bombWidth, bombY, bombWidth / 4);
		ofDrawCircle(bombX - bombWidth, bombY, bombWidth / 4);
		ofDrawCircle(bombX, bombY + bombWidth, bombWidth / 4);
		ofDrawCircle(bombX, bombY - bombWidth, bombWidth / 4);
	}
	else if (isExploding == true) {
		//base of explosion
		ofSetColor(252, 160, 0);
		ofDrawCircle(bombX, bombY, bombWidth);

		//Top layers for flavor!
		ofSetColor(230, 237, 17);
		ofDrawCircle(bombX + bombWidth / 5, bombY, bombWidth / 5);
		ofSetColor(194, 16, 16);
		ofDrawCircle(bombX - bombWidth / 5, bombY, bombWidth / 5);
		ofSetColor(250, 50, 12);
		ofDrawCircle(bombX, bombY + bombWidth / 5, bombWidth / 5);
		ofSetColor(223, 242, 17);
		ofDrawCircle(bombX, bombY - bombWidth / 5, bombWidth / 5);
		ofSetColor(250, 50, 12);
		ofDrawCircle(bombX + bombWidth / 1.5, bombY, bombWidth / 3);
		ofSetColor(230, 237, 17);
		ofDrawCircle(bombX - bombWidth / 1.5, bombY, bombWidth / 3);
		ofSetColor(223, 242, 17);
		ofDrawCircle(bombX, bombY + bombWidth / 1.5, bombWidth / 3);
		ofSetColor(194, 16, 16);
		ofDrawCircle(bombX, bombY - bombWidth / 1.5, bombWidth / 3);
		ofSetColor(250, 100, 12);
		ofDrawCircle(bombX + bombWidth / 2, bombY - bombWidth / 2, bombWidth / 4);
		ofSetColor(230, 90, 17);
		ofDrawCircle(bombX - bombWidth / 2, bombY - bombWidth / 2, bombWidth / 4);
		ofSetColor(242, 208, 17);
		ofDrawCircle(bombX - bombWidth / 2, bombY + bombWidth / 2, bombWidth / 4);
		ofSetColor(194, 55, 16);
		ofDrawCircle(bombX + bombWidth / 2, bombY + bombWidth / 2, bombWidth / 4);
	}
}

//Returns bomb x coord
float ofApp::Bomb::getBombX() {
	return bombX;
}

//Returns bomb y coord
float ofApp::Bomb::getBombY() {
	return bombY;
}

//Returns the bomb's width
float ofApp::Bomb::getBombWidth() {
	return bombWidth;
}

//Set the bomb's x coord
void ofApp::Bomb::setBombX(float x) {
	bombX = x;
}

//Set the bomb's y coord
void ofApp::Bomb::setBombY(float y) {
	bombY = y;
}

//Set the bomb's width
void ofApp::Bomb::setBombWidth(float width) {
	bombWidth = width;
}

//Animates the bomb falling from the sky
bool ofApp::Bomb::falling() {
	if (isFalling == true) {
		bombWidth = bombWidth - 1;
	}
	if (bombWidth == 1) {
		isFalling = false;
	}
	return isFalling;
}

//Animates the bomb exploding
void ofApp::Bomb::exploding(bool fall) {
	if (fall == false) {
		isExploding = true;
		bombWidth = bombWidth + 3;
	}
	if (isExploding == true && bombWidth >= explosionSize) {
		bombX = 5000;
	}
}

//Returns true if exploding false if it isn't
bool ofApp::Bomb::isItExploding() {
	return isExploding;
}

//Resets a bomb to its falling state
void ofApp::Bomb::setFalling() {
	isFalling = true;
	isExploding = false;
	bombWidth = 30;
	ofSetColor(0, 0, 0);
}

//------------------------------------------End Bomb Class Methods-------------------------------------------------------