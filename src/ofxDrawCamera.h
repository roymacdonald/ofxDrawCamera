//
//  ofxDrawCamera.h
//  emptyExample
//
//  Created by Roy Macdonald on 16-08-15.
//
//

#pragma once
#include "ofMain.h"
class ofxDrawCamera{
public:
//    ofxDrawCamera();
    static void draw(ofCamera& cam);
protected:
    static void initStatics();
    static vector<ofVec3f> vertices;
    static vector<ofIndexType> indices;
    static ofMesh drawBox;
    static bool bStaticInited;
};
