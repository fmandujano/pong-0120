#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxNetwork.h"
#define PORT 6666
#define BUFFER_SIZE 100

class ofApp : public ofBaseApp{

	public:
		void setup();
		void createServer(); // equivale a setupServer
		void connectServer(); // equvale a setupClient
		void update();
		void updateServer();
		void updateClient();
		void draw();
		void drawServer();
		void drawClient();

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

		//estado del juego
		enum EEstadoApp
		{
			menu, client, server
		} estadoApp ;

		//variables del menu
		ofxPanel mainPanel;
		ofxButton btnCreate;
		ofxButton btnConnect;

		//variables de los objetos de juego
		ofVec2f *posPelota;
		ofVec2f *velPelota;
		ofVec2f *posPlayer1;
		ofVec2f *posPlayer2;

		//inputs
		bool w, s;

		//Manejo de red
		ofxUDPManager udpManager;
		char  buffer[BUFFER_SIZE];
		
};
