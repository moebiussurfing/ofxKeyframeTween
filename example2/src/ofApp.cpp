#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

    gui.setup();
    gui.add(latitude.set("latitude", -30,-360,360));
    gui.add(longitude.set("longitude", 0,-360,360));
    gui.add(radius.set("radius", 1000, 0, 1000));
    gui.add(step.set("step", 45, 0, 360));
    gui.add(timeMax.set("time", 1, 0, 2));
//    gui.add(tw.set("tw", 0, 0, 10));
    int _m = 1000;
    gui.add(centerPoint.set("center", ofVec3f(0),ofVec3f(0),ofVec3f(_m)));

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

    ofNode c;
    c.setPosition(centerPoint.get().x, centerPoint.get().y, centerPoint.get().z);

      node.orbitDeg(longitude, latitude, radius, c);

    c.lookAt(glm::vec3(0,0,0));

//    twf = (tw);
//    cout << "twf:" << tw<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    float timef = ofGetElapsedTimef();
//    timef = ofWrap(timef,0,5);

    camera_.getValue(ofClamp(timer,0,timeMax)).apply(camera);


//    ofCamera camera;
//    camera_.getValue(timef).apply(camera);


    camera.begin();

    ofPushMatrix();
    ofPushStyle();

//    float d,x,y,z;
//    rot_.getValue(timef).getRotate(d,x,y,z);
//    ofRotate(d,x,y,z);
//    ofSetColor(color_.getValue(timef));
//    ofSetColor(color_.getValue(timer));
//    ofDrawRectangle(-50,-50, 100,100);

    ofFill();
    ofSetColor(255);
    ofDrawBox(100);
    ofNoFill();
    ofSetColor(0);
    ofDrawBox(100);


    node.draw();


    ofDrawAxis(10);

    ofPopStyle();
    ofPopMatrix();

    camera.end();



//    if(ofGetKeyPressed(' ')){
//        ofCamera c;
//        c.setTransformMatrix(node.getGlobalTransformMatrix());
//        c.begin();
//        ofDrawGrid(100,10, true);
//        c.end();
//    }else{
//        cam.begin();
//        ofDrawGrid(100,10, true);
//        node.draw();
//        cam.end();
//    }

    gui.draw();
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ')
    {
        camera_.clear();

        ofCamera cam;
        ofVec3f lookat;
        lookat.set(0, 0, 0);

        cam.setPosition(camera.getPosition());
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, { cam, lookat }, OF_EASE_LINEAR_INOUT);

        cam.setPosition(node.getPosition());
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, { cam, lookat }, OF_EASE_LINEAR_INOUT);

        timer = 0;
    }

    if (key == OF_KEY_LEFT)
    {
        longitude -= step;
        longitude = ofWrap(longitude, longitude.getMin(), longitude.getMax());

        camera_.clear();
        ofCamera cam;
        ofVec3f lookat;

        cam.setPosition(camera.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, { cam, lookat }, OF_EASE_LINEAR_INOUT);

        cam.setPosition(node.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, {cam, lookat}, OF_EASE_LINEAR_INOUT);

        timer = 0;
    }

    if (key == OF_KEY_RIGHT)
    {
        longitude += step;
        longitude = ofWrap(longitude, longitude.getMin(), longitude.getMax());

        camera_.clear();
        ofCamera cam;
        ofVec3f lookat;

        cam.setPosition(camera.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, { cam, lookat }, OF_EASE_LINEAR_INOUT);

        cam.setPosition(node.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, {cam, lookat}, OF_EASE_LINEAR_INOUT);

        timer = 0;
    }

    if (key == '1')
    {
        camera_.clear();
        ofCamera cam;
        ofVec3f lookat;

        cam.setPosition(camera.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, { cam, lookat }, OF_EASE_LINEAR_INOUT);

        cam.setPosition(ofVec3f(0, 0, 500));
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, {cam, lookat}, OF_EASE_LINEAR_INOUT);
        timer = 0;
    }
    if (key == '2')
    {
        camera_.clear();
        ofCamera cam;
        ofVec3f lookat;

        cam.setPosition(camera.getPosition());
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(0, {cam, lookat}, OF_EASE_LINEAR_INOUT);

        cam.setPosition(ofVec3f(0, 500, 00));
        lookat.set(0, 0, 0);
        cam.lookAt(lookat);
        camera_.addKeyFrame(1, {cam, lookat}, OF_EASE_LINEAR_INOUT);
        timer = 0;
    }
//
//    if (key == '3')
//    {
//        camera_.clear();
//
//        ofCamera _c;
//        ofVec3f lookat;
//
//        _c.setPosition(ofVec3f(0,0,100));
//        lookat.set(100,0,0);
//        _c.lookAt(lookat);
//        _c.setFov(60);
//        //    _c(4/3.f);
//        camera_.addKeyFrame(0, {camera, lookat}, OF_EASE_CUBIC_INOUT);
//        _c.setFov(120);
//        camera_.addKeyFrame(1, {_c, lookat}, OF_EASE_CUBIC_IN);
//
//        _c.setPosition(ofVec3f(100,500,-200));
//        lookat.set(0,100,0);
//        _c.lookAt(lookat);
//        camera_.addKeyFrame(2, {_c, lookat}, OF_EASE_CUBIC_IN);
//
//        _c.setPosition(ofVec3f(-100,50,200));
//        lookat.set(-100,0,0);
//        _c.lookAt(lookat);
//        camera_.addKeyFrame(3, {_c, lookat}, OF_EASE_SINE_INOUT);
//        timer = 0;
//
//    }
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
