#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxKeyframeTween.h"
#include "ofxTweenTypeInterpolation.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    //void keyReleased(int key);

    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //private:
    ofxKeyframeTween<ofQuaternion> rot_;
    ofxKeyframeTween<ofColor, ofx::tweentype::interpolate::HSBColor<ofx::tweentype::interpolate::HueIPFar<ofColor>>> color_;
    ofxKeyframeTween<ofx::tweentype::interpolate::camera::Orbit> camera_;

    ofCamera camera;
    float timer = 0;



    ofxPanel gui;
    ofParameter<ofVec3f> centerPoint;
    ofParameter<float>latitude, longitude, radius, step, timeMax;
    ofParameter<int> tw;
    ofEaseFunction twf;

    ofEasyCam cam;

    ofNode node;
};
