#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(237, 225, 130);
	ofSetFrameRate(30);
	ofSetCircleResolution(100);
	gameEnd = false;
	incrementBombs = 0;
	for (int i = 0; i < 10; i++) {
		bombs[i] = Bomb(ofRandom(0, 1200), ofRandom(0, 640));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	gameEnd = thePlayer.isHitByBomb(theBomb.getBombX(), theBomb.getBombY(), theBomb.getBombWidth());
	theBomb.exploding(theBomb.falling());
	gameEnd = thePlayer.isHitByBomb(bombs[incrementBombs].getBombX(), bombs[incrementBombs].getBombY(), bombs[incrementBombs].getBombWidth());
	bombs[incrementBombs].exploding(bombs[incrementBombs].falling());
	if (bombs[incrementBombs].getBombX() == 5000) {
		incrementBombs = incrementBombs + 1;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (gameEnd == false) {
		thePlayer.draw();
		theBomb.draw();
		bombs[incrementBombs].draw();
	}
	else if (gameEnd == true) {
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("You're a L-O-S-E-R, I'm a WINNER!", 560, 320);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
		thePlayer.setPlayerY(thePlayer.getPlayerY() - 10);
	}
	if (key == 's') {
		thePlayer.setPlayerY(thePlayer.getPlayerY() + 10);
	}
	if (key == 'a') {
		thePlayer.setPlayerX(thePlayer.getPlayerX() - 10);
	}
	if (key == 'd') {
		thePlayer.setPlayerX(thePlayer.getPlayerX() + 10);
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
	ofSetColor(26, 125, 237);
	ofDrawCircle(playerX, playerY, playerWidth);
}

//Return player X coordinate
float ofApp::Player::getPlayerX() {
	return playerX;
}

//Return player Y coordinate
float ofApp::Player::getPlayerY() {
	return playerY;
}

//Set player's X coordinate
void ofApp::Player::setPlayerX(float x) {
	playerX = x;
}

//Set player's Y coordinate
void ofApp::Player::setPlayerY(float y) {
	playerY = y;
}

//Tell's whether or not the player is hit by a bomb
bool ofApp::Player::isHitByBomb(float x, float y, float width) {
	xDif = playerX - x;
	yDif = playerY - y;
	distanceSquared = xDif * xDif + yDif * yDif;
	if (distanceSquared < (playerWidth + width) * (playerWidth + width)) {
		hit = true;
		//cout << "true";
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
}

//No argument constructor
ofApp::Bomb::Bomb() {

}

//Draws the bomb
void ofApp::Bomb::draw() {
	if (isFalling == true) {
		ofSetColor(0, 0, 0);
	}
	else if (isExploding == true) {
		ofSetColor(255, 0, 00);
	}
	ofDrawCircle(bombX, bombY, bombWidth);
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
		bombWidth = bombWidth - 0.5;
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
		bombWidth = bombWidth + .5;
	}
	if (isExploding == true && bombWidth == 50) {
		bombX = 5000;
	}
}

//------------------------------------------End Bomb Class Methods-------------------------------------------------------