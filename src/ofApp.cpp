#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetWindowShape(width, height);
    gui.setup(); // most of the time you don't need a name
    gui.add(choose.setup("", ""));
    gui.add(mediaCenter.setup("FW Media Center", false));
    gui.add(fwplayer.setup("FW Player", true));

    gui.setPosition(100, 250);
    gui.setDefaultWidth(550);
    
    myfont32.loadFont("FZLTZCHJW.ttf", 32);
    myfont24.loadFont("FZLTZCHJW.ttf", 24);
    myfont16.loadFont("FZLTXHJW.ttf", 16);

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


