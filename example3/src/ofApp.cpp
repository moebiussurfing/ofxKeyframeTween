#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

    float size = 100;
    float w = 300;
    float h = 200;

    v1 = ofVec2f(0,0);
    p1.addKeyFrame(0, v1, OF_EASE_CUBIC_IN);
    v1 = ofVec2f(0,-h);
    p1.addKeyFrame(1, v1, OF_EASE_CUBIC_IN);

    v2 = ofVec2f(w,0);
    p2.addKeyFrame(0, v2, OF_EASE_CUBIC_IN);
    v2 = ofVec2f(size,-h);
    p2.addKeyFrame(1, v2, OF_EASE_CUBIC_IN);

    v3 = ofVec2f(w,size);
    p3.addKeyFrame(0, v3, OF_EASE_CUBIC_IN);
    v3 = ofVec2f(size,size-h);
    p3.addKeyFrame(1, v3, OF_EASE_CUBIC_IN);

    v4 = ofVec2f(0,size);
    p4.addKeyFrame(0, v4, OF_EASE_CUBIC_IN);
    v4 = ofVec2f(0,size-h);
    p4.addKeyFrame(1, v4, OF_EASE_CUBIC_IN);

//    color_.addKeyFrame(1, ofColor::red, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(2, ofColor::green, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(3, ofColor::blue, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(4, ofColor::red, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(5, ofColor::white, OF_EASE_CUBIC_IN);





//    cm.addKeyFrame(0, ms0, OF_EASE_CUBIC_IN);


//    ms0.position = ofVec2f(100,100);
//    ms0.rotation = -90;
//    cm.addKeyFrame(1, ms0, OF_EASE_CUBIC_IN);

//    ms = ofxTweenType<MyStruct, MyInterpolator>(time, 0, 1, ms0, ms1, OF_EASE_CUBIC_IN);

}

//--------------------------------------------------------------
void ofApp::update(){
	timer += ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    float timef = ofGetElapsedTimef();
//    timef = ofWrap(timef,0,5);
    ofPushMatrix();
    ofTranslate(500,500);

//    for (int i = 0; i<4; i++){
//    }

//    float r = 5;
//    ofDrawCircle(p1.getValue(timer), r);
//    ofDrawCircle(p2.getValue(timer), r);
//    ofDrawCircle(p3.getValue(timer), r);
//    ofDrawCircle(p4.getValue(timer), r);

    ofDrawLine(p1.getValue(timer),p2.getValue(timer));
    ofDrawLine(p2.getValue(timer),p3.getValue(timer));
    ofDrawLine(p3.getValue(timer),p4.getValue(timer));
    ofDrawLine(p4.getValue(timer),p1.getValue(timer));
    ofPopMatrix();


    ms0.position = ofVec2f(100,100);
    ms0.rotation = 90;
    ms1.position = ofVec2f(100,100);
    ms1.rotation = 360;
    ms = ofxTweenType<MyStruct, MyInterpolator>(timer, 0, 1, ms0, ms1, OF_EASE_CUBIC_IN);

    glm::vec2 p = ms.position;
    float r = ms.rotation;
    ofDrawRectangle(p, r, r);

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ')
    {

    }

    timer = 0;
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
