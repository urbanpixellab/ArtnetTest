#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);
    //https://github.com/hideakitai/ofxArtnetProtocol
//    artnet1.begin("192.168.178.200");
    artnet1.begin("192.168.12.200");
    fbo.allocate(150, 1,GL_RGB);
    count = 0;
    direction = true;
    counter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    //map the arrays

    for (int i = 0; i < 150; i++)
    {
        if (i <= counter)
        {
            universe0[i*3+0] = 255;
            universe0[i*3+1] = 255;
            universe0[i*3+2] = 255;
        }
        else
        {
            universe0[i*3+0] = 0;
            universe0[i*3+1] = 0;
            universe0[i*3+2] = 0;
        }
    }
    counter++;
    if (counter >= 150) counter = 0;
    
    int universe = 0;
    int chnCount = 450;//33 leds * 3
    for (int i = 0; i < 8; i++)
    {
        universe = i;
        artnet1.send(universe0,universe,chnCount);
    }
}

void ofApp::drawOpbouwend()
{
     fbo.begin();
//     ofClear(0);
     float colorR = (sin(ofGetElapsedTimeMillis() / 1000.f) / 2.f + 0.5f) * 255.f;
     float colorG = (sin((ofGetElapsedTimeMillis() / 1000.f) + PI / 3.f) / 2.f + 0.5f) * 255.f;
     float colorB = (sin((ofGetElapsedTimeMillis() / 1000.f)  + PI * 2.f / 3.f) / 2.f + 0.5f) * 255.f;
     ofSetColor((int)colorR, (int)colorG, (int)colorB);
     int speed = 8;
     ofDrawRectangle(0, 0, 6*(0.5 + sin(ofGetElapsedTimef() * speed)* 0.5), 1);
     ofDrawRectangle(0, 1, 6*(0.5 + sin(ofGetElapsedTimef() * speed + PI)* 0.5), 1);
     ofDrawRectangle(0, 2, 6*(0.5 + sin(ofGetElapsedTimef() * speed)* 0.5), 1);
     ofDrawRectangle(0, 3, 6*(0.5 + sin(ofGetElapsedTimef() * speed + PI)* 0.5), 1);
     ofDrawRectangle(0, 4, 6*(0.5 + sin(ofGetElapsedTimef() * speed)* 0.5), 1);
     ofDrawRectangle(0, 5, 6*(0.5 + sin(ofGetElapsedTimef() * speed + PI)* 0.5), 1);
     fbo.end();
    fbo.readToPixels(pixels);

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(255);
//    float scalex = ofGetWidth() / fbo.getWidth();
//    float scaley = ofGetHeight() / fbo.getHeight();
//    ofScale(scalex, scaley);
//    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
