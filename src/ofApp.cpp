#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//configurar menu principal
	estadoApp = EEstadoApp::menu;
	mainPanel.setup();
	mainPanel.add(btnConnect.setup("Conectar a partida"));
	mainPanel.add(btnCreate.setup("Crear partida"));
	mainPanel.setPosition(ofGetWidth() / 2 - mainPanel.getWidth() / 2,
		ofGetHeight() / 2 - mainPanel.getHeight() / 2);

	//listeners de los botones 
	btnCreate.addListener(this, &ofApp::createServer);
	btnConnect.addListener(this, &ofApp::connectServer);

	//condiciones iniciales de la pelota
	posPlayer1 = new ofVec2f(30, 30);
	posPlayer2 = new ofVec2f(ofGetWidth() -15 - 30, 30);
	posPelota = new ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	velPelota = new ofVec2f(100, -80);
}

//configuracion del servidor
void ofApp::createServer()
{
	estadoApp = EEstadoApp::server;
	udpManager.Create();
	udpManager.Bind(PORT);
	udpManager.SetNonBlocking(true);
}

//configuracion del cliente
void ofApp::connectServer()
{
	estadoApp = EEstadoApp::client;
	udpManager.Create();
	udpManager.Connect("127.0.0.1", PORT);
	udpManager.SetNonBlocking(true);
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (estadoApp == EEstadoApp::menu)
	{
		//nada, el panel no necesita update
	}
	else if (estadoApp == EEstadoApp::server)
	{
		updateServer();
	}
	else if (estadoApp == EEstadoApp::client)
	{
		updateClient();
	}
}

void ofApp::updateClient()
{
	//movimiento local del player 2, el cliente, siempre a la derecha.
	if (w)
		posPlayer2->y -= 200 * ofGetLastFrameTime();
	if (s)
		posPlayer2->y += 200 * ofGetLastFrameTime();

	//enviar pos al servidor
	memset(buffer, 0, BUFFER_SIZE);
	sprintf(buffer, "%f,%f\n", posPlayer2->x, posPlayer2->y);
	printf("Enviando : %s", buffer);
	udpManager.Send(buffer, BUFFER_SIZE);
}

void ofApp::updateServer()
{
	//movimiento local del player 1, el servidor, siempre a la izquierda.
	if (w)
		posPlayer1->y -= 200 * ofGetLastFrameTime();
	if (s)
		posPlayer1->y += 200 * ofGetLastFrameTime();

	//recibir posicion del jugador 2
	//imprimir lo que llega:
	memset(buffer, 0, BUFFER_SIZE);
	if ( udpManager.Receive(buffer, BUFFER_SIZE) > 0)
	{
		printf(" Cliente : %s", buffer);
	}
	else
	{
		printf(" no llego nada \n", buffer);
	}
	
	


	//movimiento de la pelota
	posPelota->x += velPelota->x * ofGetLastFrameTime();
	posPelota->y += velPelota->y * ofGetLastFrameTime();

	//colisiones
	if (posPelota->x <= 0)
	{
		velPelota->x *= -1;
		posPelota->x = 1;
	}
	if (posPelota->x >= ofGetWidth())
	{
		velPelota->x *= -1;
		posPelota->x = ofGetWidth() - 1;
	}
	if (posPelota->y <= 0)
	{
		velPelota->y *= -1;
		posPelota->y = 1;
	}
	if (posPelota->y >= ofGetHeight())
	{
		velPelota->y *= -1;
		posPelota->y = ofGetHeight() - 1;
	}
}

void ofApp::draw()
{
	if (estadoApp == EEstadoApp::menu)
	{
		mainPanel.draw();
	}
	else if (estadoApp == EEstadoApp::server)
	{
		drawServer();
	}
	else if (estadoApp == EEstadoApp::client)
	{
		drawClient();
	}
}

//--------------------------------------------------------------
void ofApp::drawServer()
{
	ofSetBackgroundColor(ofColor::cornflowerBlue);
	ofSetColor(ofColor::white);
	ofDrawBitmapString("SERVER MODE", 20, 20);
	ofSetColor(255, 0, 0);
	ofCircle(posPelota->x, posPelota->y, 15);

	ofSetColor(255, 255, 255);
	ofRect( posPlayer1->x, posPlayer1->y, 15, 100);
	ofRect(posPlayer2->x, posPlayer2->y, 15, 100);
}

void ofApp::drawClient()
{
	ofSetBackgroundColor(0, 0, 0, 255);
	ofSetColor( ofColor::white);
	ofDrawBitmapString("CLIENT MODE", 20, 20);
	ofSetColor(255, 0, 0);
	ofCircle(posPelota->x, posPelota->y, 15);

	ofSetColor(255, 255, 255);
	ofRect(posPlayer1->x, posPlayer1->y, 15, 100);
	ofRect(posPlayer2->x, posPlayer2->y, 15, 100);
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
