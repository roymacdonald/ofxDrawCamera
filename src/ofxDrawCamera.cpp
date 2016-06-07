//
//  ofxDrawCamera.cpp
//  emptyExample
//
//  Created by Roy Macdonald on 16-08-15.
//
//

#include "ofxDrawCamera.h"

bool ofxDrawCamera::bStaticInited = false;
vector<ofVec3f> ofxDrawCamera::vertices = vector<ofVec3f>();
vector<ofIndexType> ofxDrawCamera::indices = vector<ofIndexType>();
ofMesh ofxDrawCamera::drawBox = ofMesh();
//------------------------------------------------------------------------
void ofxDrawCamera::initStatics(){
    if (!bStaticInited) {
        bStaticInited = true;
        vertices.push_back(ofVec3f(-1, -1, -1));
        vertices.push_back(ofVec3f(-1, -1, +1));
        vertices.push_back(ofVec3f(-1, +1, +1));
        vertices.push_back(ofVec3f(+1, +1, +1));
        vertices.push_back(ofVec3f(+1, -1, +1));
        vertices.push_back(ofVec3f(+1, -1, -1));
        vertices.push_back(ofVec3f(+1, +1, -1));
        vertices.push_back(ofVec3f(-1, +1, -1));
        
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(3);
        indices.push_back(4);
        indices.push_back(4);
        indices.push_back(5);
        indices.push_back(5);
        indices.push_back(6);
        indices.push_back(6);
        indices.push_back(7);
        indices.push_back(7);
        indices.push_back(0);
        
        indices.push_back(7);
        indices.push_back(2);
        
        indices.push_back(6);
        indices.push_back(3);
        
        indices.push_back(1);
        indices.push_back(4);
        
        indices.push_back(0);
        indices.push_back(5);
        
        drawBox.addVertices(vertices);
        drawBox.addIndices(indices);
        drawBox.setMode(OF_PRIMITIVE_LINES);
    }
}
void ofxDrawCamera::draw(ofCamera& cam, bool bDrawCameraPosition){
    initStatics();
    ofPushMatrix();
    glMultMatrixf(cam.getGlobalTransformMatrix().getPtr());
    glMultMatrixf(cam.getProjectionMatrix().getInverse().getPtr());
    drawBox.draw();
    ofDrawLine(ofVec3f(0.0f,0.0f,-1.0f), ofVec3f(2.0f,0.0f,-1.0f));
    ofDrawLine(ofVec3f(0.0f,0.0f,-1.0f), ofVec3f(0.0f,2.0f,-1.0f));
    ofPopMatrix();
    if (bDrawCameraPosition) {
        cam.draw();
    }
    
}





