#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(30);
    //https://github.com/hideakitai/ofxArtnetProtocol
//    artnet1.begin("192.168.178.200");
//    artnet2.begin("10.0.0.40");
    artnet1.begin("192.168.12.200");
//    artnet.begin("192.168.178.200");
    fbo.allocate(150, 1,GL_RGB);
    count = 0;
    direction = true;
    gui.setup();
    gui.add(toggle.setup("on/off", false));
    gui.add(brightness.setup("brightness",100,0,255));
    counter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    //map the arrays

    for (int i = 0; i < 150; i++)
    {
        if (i <= counter)
        {
            universe0[i*3+0] = 255*brightness;
            universe0[i*3+1] = 255*brightness;
            universe0[i*3+2] = 255*brightness;
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
    
    if (toggle)
    {
        int universe = 0;
        int chnCount = 450;//33 leds * 3
        artnet1.send(universe0,0,chnCount);
        artnet1.send(universe0,1,chnCount);
        artnet1.send(universe0,2,chnCount);
        artnet1.send(universe0,3,chnCount);
        artnet1.send(universe0,4,chnCount);
        artnet1.send(universe0,5,chnCount);
        artnet1.send(universe0,6,chnCount);
        artnet1.send(universe0,7,chnCount);
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
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
