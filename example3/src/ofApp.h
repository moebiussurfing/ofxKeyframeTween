#pragma once

#include "ofMain.h"
#include "ofxKeyframeTween.h"
#include "ofxTweenTypeInterpolation.h"

// object to tween
struct MyStruct {
    ofVec2f position;
    float rotation;
};
// your interpolator
struct MyInterpolator {
    static inline int dim() { return 2; }
    static inline MyStruct getInterpolated(float k, float k0, float k1, const MyStruct &v0, const MyStruct &v1, std::vector<ofEaseFunction> ease) {
        using namespace ofx::tweentype::interpolate;
        MyStruct ret;
        ret.position = Typical<ofVec2f>::type::getInterpolated(k, k0, k1, v0.position, v1.position, {ease[0]});
        ret.rotation = Typical<float>::type::getInterpolated(k, k0, k1, v0.rotation, v1.rotation, {ease[1]});
        return ret;
    }
};



class ofApp : public ofBaseApp{
	
public:

    // use it
//    float time;
    MyStruct ms0,ms1;
    MyStruct ms;
//    MyStruct ms = ofxTweenType<MyStruct, MyInterpolator>(time, 0, 1, ms0, ms1, OF_EASE_CUBIC_IN);0
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
private:
    ofxKeyframeTween<ofVec2f> p1;
    ofxKeyframeTween<ofVec2f> p2;
    ofxKeyframeTween<ofVec2f> p3;
    ofxKeyframeTween<ofVec2f> p4;

    ofVec2f v1;
    ofVec2f v2;
    ofVec2f v3;
    ofVec2f v4;

    float timer = 0;

//    ofxKeyframeTween<MyInterpolator> cm;

};
