#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int width = 800;
        int height = 600;

    
        //ofxUI setup
        ofxPanel gui;
        ofxPanel guiBtn;
    	ofxToggle mediaCenter;
        ofxToggle fwplayer;
        ofxButton proceed;
    
        ofTrueTypeFont myfont24;
        ofTrueTypeFont myfont32;
        ofTrueTypeFont myfont16;
    
        void proceedBtnPressed();
        bool isProceedClickable;
    
        // button rectangle
        float top, bottom, left, right;
        ofRectangle rect;
        float dx, dy;
        float scaleX, scaleY;
        float angle;
        ofMatrix4x4 matrix;
        bool isInside;
    
};
