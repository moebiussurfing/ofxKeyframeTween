#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

//    rot_.addKeyFrame(0, ofQuaternion(0, ofVec3f(1,0,0)), OF_EASE_CUBIC_IN);
//    rot_.addKeyFrame(1, ofQuaternion(90, ofVec3f(0,1,0)), OF_EASE_EXPO_IN);
//    rot_.addKeyFrame(2, ofQuaternion(90, ofVec3f(0,1,1)), OF_EASE_CUBIC_IN);
//    rot_.addKeyFrame(3, ofQuaternion(180, ofVec3f(1,1,0)), OF_EASE_BOUNCE_INOUT);
//    rot_.addKeyFrame(4, ofQuaternion(270, ofVec3f(1,0,1)), OF_EASE_ELASTIC_INOUT);
//    rot_.addKeyFrame(5, ofQuaternion(0, ofVec3f(1,0,0)), OF_EASE_EXPO_INOUT);
//
//    color_.addKeyFrame(0, ofColor::white, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(1, ofColor::red, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(2, ofColor::green, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(3, ofColor::blue, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(4, ofColor::red, OF_EASE_CUBIC_IN);
//    color_.addKeyFrame(5, ofColor::white, OF_EASE_CUBIC_IN);



////    camera.setAspectRatio(16/9.f);
////    camera.setLensOffset(ofVec2f(0.5f,0));
//    lookat.set(0,-100,0);
//    camera.lookAt(lookat);
//    camera.setFov(60);
//    camera_.addKeyFrame(4, {camera, lookat}, OF_EASE_CUBIC_IN);
//    camera.setPosition(ofVec3f(0,0,100));
//    lookat.set(100,0,0);
//    camera.lookAt(lookat);
////    camera.setLensOffset(ofVec2f(0,0));
//    camera_.addKeyFrame(5, {camera, lookat}, OF_EASE_BOUNCE_OUT);
}

//--------------------------------------------------------------
void ofApp::update(){
	timer += ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    float timef = ofGetElapsedTimef();
//    timef = ofWrap(timef,0,5);

    camera_.getValue(ofClamp(timer,0,1)).apply(camera);


//    ofCamera camera;
//    camera_.getValue(timef).apply(camera);


    camera.begin();

    ofPushMatrix();

//    float d,x,y,z;
//    rot_.getValue(timef).getRotate(d,x,y,z);
//    ofRotate(d,x,y,z);

	ofPushStyle();
//    ofSetColor(color_.getValue(timef));
    ofSetColor(color_.getValue(timer));

//    ofDrawRectangle(-50,-50, 100,100);
    ofDrawBox(100);

	ofPopStyle();
	ofPopMatrix();
	ofDrawAxis(200);

	camera.end();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1')
    {
        camera_.clear();
        ofCamera cam;
        ofVec3f lookat;

        cam.setPosition(camera.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, { cam, lookat }, OF_EASE_CUBIC_IN);

        cam.setPosition(ofVec3f(50, 500, 1000));
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, {cam, lookat}, OF_EASE_CUBIC_IN);
    }
    if (key == '2')
    {
        camera_.clear();
        ofCamera cam;
        ofVec3f lookat;

        cam.setPosition(camera.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, {cam, lookat}, OF_EASE_CUBIC_IN);

        cam.setPosition(ofVec3f(50, 500, -1000));
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, {cam, lookat}, OF_EASE_CUBIC_IN);
    }

    if (key == '3')
    {
        camera_.clear();

        ofCamera _c;
        ofVec3f lookat;

        _c.setPosition(ofVec3f(0,0,100));
        lookat.set(100,0,0);
        _c.lookAt(lookat);
        _c.setFov(60);
        //    _c(4/3.f);
        camera_.addKeyFrame(0, {camera, lookat}, OF_EASE_CUBIC_INOUT);
        _c.setFov(120);
        camera_.addKeyFrame(1, {_c, lookat}, OF_EASE_CUBIC_IN);

        _c.setPosition(ofVec3f(100,500,-200));
        lookat.set(0,100,0);
        _c.lookAt(lookat);
        camera_.addKeyFrame(2, {_c, lookat}, OF_EASE_CUBIC_IN);

        _c.setPosition(ofVec3f(-100,50,200));
        lookat.set(-100,0,0);
        _c.lookAt(lookat);
        camera_.addKeyFrame(3, {_c, lookat}, OF_EASE_SINE_INOUT);
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
