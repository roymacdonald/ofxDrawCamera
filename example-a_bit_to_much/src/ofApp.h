#pragma once

#include "ofMain.h"
#include "ofxDrawCamera.h"

#define NUM_CAMERAS 4

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
		
    
    ofEasyCam cams [NUM_CAMERAS]; //several cameras that we can switch.
    
    bool bDrawGrid;
    
    ofRectangle viewports [NUM_CAMERAS -1];
    ofRectangle mainViewport;
    
    void drawSomeStuff();
    
    ofColor colors[NUM_CAMERAS];
    
};
