#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main(int argc, char** argv )
{
	///int rx = atoi(argv[1])
	for (int i = 0; i < argc; i++)
	{
		printf("Argumento %i: %s\n", i, argv[i]);
	}

	if (argc == 3)
	{
		ofSetupOpenGL( atoi(argv[1]), atoi(argv[2]), OF_WINDOW);
	}
	else //fallback de tamano estandar de pantalla
	{
		ofSetupOpenGL(640, 480, OF_WINDOW);
	}
				// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
