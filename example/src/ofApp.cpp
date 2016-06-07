#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // cams[0] is left with the default camera settings, the others are randomized
    for (int i = 1; i < NUM_CAMERAS; i++) {
        cams[i].setFov(ofRandom(50, 90));
        float nc = ofRandom(0, 200);
        cams[i].setNearClip(nc);
        float fc = ofRandom(nc+500, 2000);
        cams[i].setFarClip(fc);
        
        
        cams[i].setPosition(0,0, ofRandom(nc, fc));
        ofVec3f axis(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
        axis.normalize();
        
        cams[i].rotateAround(ofRandom(360), axis, ofVec3f(0));
        
        cams[i].lookAt(ofVec3f(0));
        
        cams[i].setAutoDistance(false);
        viewports[i-1].set(2, 203 * (i-1), 300, 200);
        
    }
    
    mainViewport.set(302, 0, ofGetWidth() -300, ofGetHeight());
    
    
    ofSeedRandom(1);
    for (int i =0; i < NUM_CAMERAS; i++) {
        colors[i].setHsb(ofRandom(255), 200, 230);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cams[0].begin(mainViewport);
    
    drawSomeStuff();
    
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    ofSeedRandom(1);
    for (int i = 1; i < NUM_CAMERAS; i++) {
        
        ofSetColor(0);
        ofDrawBitmapString(ofToString(i), cams[i].getPosition());
        
        ofSetColor(colors[i]);
        ofxDrawCamera::draw(cams[i]);// this is the important line
    }
    cams[0].end();
    
    
    ofSetColor(0);
    ofDrawRectangle(0, 0,viewports[0].getWidth()+5, ofGetHeight());
    
    int vpInd = 0;
    for (int i = 1; i < NUM_CAMERAS; i++) {
        
        cams[i].begin(viewports[vpInd]);
        drawSomeStuff();
        cams[i].end();
        
        ofSetColor(colors[i]);
        ofSetLineWidth(3);
        ofNoFill();
        ofDrawRectangle(viewports[vpInd]);
        vpInd ++;
    }
    
    string message = "Drag the mouse over the above viewports\n";
    message += "Press the 'g' key to toggle the grid\n";
    
    ofDrawBitmapStringHighlight(message, 20, viewports[NUM_CAMERAS -2].getMaxY() + 30);
    
}
//--------------------------------------------------------------
void ofApp::drawSomeStuff(){
    if (bDrawGrid) {
        ofDrawGrid(100,15, true);
    }
    ofEnableDepthTest();
    
    ofPushStyle();
    
    ofFill();
    
    ofSetColor(colors[0]);
    ofDrawBox(0, 0, 0, 300, 300, 300 );
    
    ofSetColor(colors[1]);
    ofDrawBox(0, 0, 200, 100, 100, 100 );
    
    ofSetColor(colors[2]);
    ofDrawCone(300, 0, 0, 150, 300);
    
    ofSetColor(colors[3]);
    ofDrawSphere(0, 300, 150);
    
    
    ofSetLineWidth(1);
    ofSetColor(ofColor::black);
    ofNoFill();
    ofDrawBox(0, 0, 200, 100, 100, 100 );
    ofDrawBox(0, 0, 0, 300, 300, 300 );
    ofDrawCone(300, 0, 0, 150, 300);
    ofDrawSphere(0, 300, 150);
    
    ofPopStyle();
    ofDisableDepthTest();
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 'g'){
        bDrawGrid ^=true;
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
