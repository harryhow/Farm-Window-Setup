#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetWindowShape(width, height);
    gui.setup(); // most of the time you don't need a name
    gui.add(mediaCenter.setup("FW Media Center", false));
    gui.add(fwplayer.setup("FW Player", true));
    gui.setPosition(60, 250);
    
    
    myfont32.loadFont("FZLTZCHJW.ttf", 32);
    myfont24.loadFont("FZLTZCHJW.ttf", 24);
    myfont16.loadFont("FZLTXHJW.ttf", 16);
    

    rect.set(350, 100, 400, 200);
    
    // Transformations applied to the rectangle
    dx = 100; dy = 450;          // A translation...
    scaleX = 0.5; scaleY = 0.3; // ... followed by a scale ...
    angle = 0;                 // ... followed by a rotation
    
    // All the transformations in one matrix
    matrix.glTranslate( dx, dy, 0 );
    matrix.glRotate( angle, 0, 0, 1 );
    matrix.glScale( scaleX, scaleY, 1 );
    
    isInside = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
        
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    gui.draw();
    
    myfont32.drawString("Farm Window", 60, 150);
    myfont24.drawString("choose service(s) to be installed", 60, 200);
    
    ofSetColor(ofColor::slateGray);
    if(mediaCenter && !fwplayer){
        myfont16.drawString("You will install \"FW Media Center\"",  60, 400);
    }
    
    if (fwplayer && !mediaCenter) {
        myfont16.drawString("You will install \"FW Player\"",  60, 400);
    }
    
    if (mediaCenter && fwplayer)
        myfont16.drawString("You will install \"FW Player\" and \"Media Center\"",  60, 400);
    
    ofSetColor(ofColor::darkSlateGrey);
    
    if (mediaCenter || fwplayer) {
        
        isProceedClickable = true;
    }
    else
        isProceedClickable = false;
    
    
    ofPushMatrix();
        ofMultMatrix(matrix);
        // Same as :
        // ofTranslate( dx, dy, 0 );
        // ofRotate( angle, 0, 0, 1 );
        // ofScale( scaleX, scaleY, 1 );
    
    
    
        if(isInside){
            ofSetColor(ofColor::darkSlateGrey, 100);
            ofFill();
        }
        else{
            ofSetColor(ofColor::darkSlateGrey);
            ofFill();
        }
    
        if (!isProceedClickable){
            ofSetColor(ofColor::darkSlateGrey, 100);
            ofNoFill();
        }
    
        ofRect(rect);
    ofPopMatrix();
    
    
    ofSetColor(ofColor::white);
    myfont16.drawString("Install",  345, 515);
    ofSetColor(ofColor::darkSlateGrey);
    
   
}

void ofApp::proceedBtnPressed() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 's') {
        gui.saveToFile("settings.xml");
    }
    if(key == 'l') {
        gui.loadFromFile("settings.xml");
    }


}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    ofVec3f mouse( x, y, 0 );
    mouse = mouse * matrix.getInverse();
    isInside = rect.inside( mouse );

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //cout << "mouse pressed, x: " << x << "y:" << y;
//    bool clicked;
//    if (button == 0) {
//        clicked = !clicked;
//        cout << clicked << endl;
//    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    //cout << "mouse release, x: " << x << "y:" << y;

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    //fix window shape
    ofSetWindowShape(width, height);
    ofSetWindowPosition((ofGetScreenWidth()-width)/2,(ofGetScreenHeight()-height)/2);
    //auto_layout(w,h);

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}



