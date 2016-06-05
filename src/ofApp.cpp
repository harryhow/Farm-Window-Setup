#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetWindowShape(width, height);
    gui.setup(); // most of the time you don't need a name
    gui.add(mediaCenter.setup("FW Media Center", false));
    gui.add(fwplayer.setup("FW Player", false));
    gui.setPosition(60, 250);
    
    
    myfont32.loadFont("FZLTZCHJW.ttf", 32);
    myfont24.loadFont("FZLTZCHJW.ttf", 24);
    myfont16.loadFont("FZLTXHJW.ttf", 16);
    myfontCH16.loadFont("FZLTZCHJW.ttf", 16);
    

    rect.set(350, 100, 400, 200);
    
    // Transformations applied to the rectangle
    dx = 100; dy = 450;          // A translation...
    scaleX = 0.5; scaleY = 0.3; // ... followed by a scale ...
    angle = 0.0;                 // ... followed by a rotation
    
    // All the transformations in one matrix
    matrix.glTranslate(dx, dy, 0);
    matrix.glRotate(angle, 0, 0, 1);
    matrix.glScale(scaleX, scaleY, 1);
    
    isInside = false;
    isCopying = false;
    isCopyDone = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
        
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    
    if (!isCopyDone)
        gui.draw();
    
    myfont32.drawString("Farm Window", 60, 150);
    
    if (!isCopyDone)
        myfont24.drawString("choose service(s) to be installed", 60, 200);
    
    ofSetColor(ofColor::slateGray);
    if(mediaCenter && !fwplayer){
        if (!isCopyDone)
            myfont16.drawString("You will install \"FW Media Center\"",  60, 400);
    }
    
    if (fwplayer && !mediaCenter) {
        if (!isCopyDone)
            myfont16.drawString("You will install \"FW Player\"",  60, 400);
    }
    
    if (mediaCenter && fwplayer) {
        if (!isCopyDone)
            myfont16.drawString("You will install \"FW Player\" and \"Media Center\"",  60, 400);
    }
    
    if (isCopying) {
        if (fwplayer && !mediaCenter) {
            copyFWFiles(1);
        }
        else if (mediaCenter && !fwplayer) {
            copyFWFiles(0);
        }
        else if (fwplayer && mediaCenter) {
            copyFWFiles(0);
            copyFWFiles(1);
        }
    }
    
    if (!isCopying && isCopyDone) {
        myfont24.drawString("Install Succeeded.\r\nWelcome to Farm Window!",  60, 300);
    }
    
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
    myfontCH16.drawString("Install",  340, 515);
    ofSetColor(ofColor::darkSlateGrey);
    
   
}

void ofApp::copyFWFiles(int module) {
    if (module == 0) { // media center
        cout << "copying media center files" << "\r\n";
        isCopyDone = true;
        //myfont16.drawString("Copying media center",  60, 430);
    }
    else if (module == 1) { // fw player
        cout << "copying fwplayer files" << "\r\n";
        //myfont16.drawString("Copying fwplayer",  60, 430);
        isCopyDone = true;
    }
    else {
        cout << "wrong module number" << "\r\n";
    }
    
    isCopying = false;
}

void ofApp::proceedBtnPressed() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "keypress:" << key << "\r\n";

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
    
    
    
    if (isInside) {
        cout << "mouse pressed, x: " << x << "y:" << y << "\r\n";
        isCopying = true;
    }
        
    
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



