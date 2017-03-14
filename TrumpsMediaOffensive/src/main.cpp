//Made by Brad Tully
//10 March 2017
//Intro to Game Design
//Final Project: In this game the player is a reporter that chose to write a negative story about Trump and
//gets sucked into Trump's dream that night where he dreams about dropping bombs on them the player uses
//WASD to avoid the exploding bombs for as long as possible

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//Makes the screen size
	ofSetupOpenGL(400,500,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	ofRunApp(new ofApp());

}
