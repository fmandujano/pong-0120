#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//condiciones iniciales

	posPlayer1 = new ofVec2f(30, 30);
	posPelota = new ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	velPelota = new ofVec2f(100, -80);
}

//--------------------------------------------------------------
void ofApp::update()
{
	//movimiento local del player 1
	if (w)
		posPlayer1->y -= 200 * ofGetLastFrameTime();
	if (s)
		posPlayer1->y += 200 * ofGetLastFrameTime();

	//movimiento de la pelota
	posPelota->x += velPelota->x * ofGetLastFrameTime();
	posPelota->y += velPelota->y * ofGetLastFrameTime();

	//colisiones
	if (posPelota->x <= 0 || posPelota->x >= ofGetWidth())
	{
		velPelota->x *= -1;
	}
	if (posPelota->y <= 0 || posPelota->y >= ofGetHeight())
	{
		velPelota->y *= -1;
 	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetBackgroundColor(0, 0, 0, 255);

	ofSetColor(255, 0, 0);
	ofCircle(posPelota->x, posPelota->y, 15);

	ofSetColor(255, 255, 255);
	ofRect( posPlayer1->x, posPlayer1->y, 15, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if(key=='w')
	{
		w = true;
	}
	if (key == 's')
	{
		s = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (key == 'w')
	{
		w = false;
	}
	if (key == 's')
	{
		s = false;
	}
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
