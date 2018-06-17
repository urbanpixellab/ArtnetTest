#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //https://github.com/hideakitai/ofxArtnetProtocol
    artnet.begin("192.168.178.200");
//    ofSetFrameRate(30);
    fbo.allocate(6, 6,GL_RGB);
    
    //create downstripes
    for (int d = 0; d < 3; d++)
    {
        stripe s;
        for (int l; l < 6; l++)
        {
            s.ledBegin.push_back(l * 3);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //create send buffer by ofFbo
    {
        fbo.begin();
        ofClear(0);
        float colorR = (sin(ofGetElapsedTimeMillis() / 1000.f) / 2.f + 0.5f) * 255.f;
        float colorG = (sin((ofGetElapsedTimeMillis() / 1000.f) + PI / 3.f) / 2.f + 0.5f) * 255.f;
        float colorB = (sin((ofGetElapsedTimeMillis() / 1000.f)  + PI * 2.f / 3.f) / 2.f + 0.5f) * 255.f;
        ofSetColor((int)colorR, (int)colorG, (int)colorB);
        ofDrawRectangle(0, 0, 6*(0.5 + sin(ofGetElapsedTimef() * 2)* 0.5), 1);
        ofDrawRectangle(0, 1, 6*(0.5 + sin(ofGetElapsedTimef() * 2 + PI)* 0.5), 1);
        ofDrawRectangle(0, 2, 6*(0.5 + sin(ofGetElapsedTimef() * 2)* 0.5), 1);
        ofDrawRectangle(0, 3, 6*(0.5 + sin(ofGetElapsedTimef() * 2 + PI)* 0.5), 1);
        ofDrawRectangle(0, 4, 6*(0.5 + sin(ofGetElapsedTimef() * 2)* 0.5), 1);
        ofDrawRectangle(0, 5, 6*(0.5 + sin(ofGetElapsedTimef() * 2 + PI)* 0.5), 1);
        fbo.end();
        fbo.readToPixels(pixels);
    }

    //map the arrays
    
    
    for (int i = 0; i < pixels.size(); i++)
    {
        universe1[i] = pixels[i];
    }
    int universe = 0;
    int chnCount = 99;//33 leds * 3
    artnet.send(universe1,universe,chnCount);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    float scalex = ofGetWidth() / fbo.getWidth();
    float scaley = ofGetHeight() / fbo.getHeight();
    ofScale(scalex, scaley);
    fbo.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
