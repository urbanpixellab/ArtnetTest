#pragma once

#include "ofMain.h"
#include "ofxArtnetProtocol.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

private:
    
public:
    void setup();
    void update();
    void draw();
    
    void drawOpbouwend();

    void keyPressed(int key);
		
private:
    
    ofxArtnetProtocol artnet1;
    //uint8_t universe1[6*6*3];//33leds = 99 values in rgb
    uint8_t universe0[150*3];//33leds = 99 values in rgb
    ofFbo       fbo;
    ofPixels    pixels;
    int         count;
    bool        direction;
    
    
    ofxPanel        gui;
    ofxIntSlider    brightness;
    ofxToggle       toggle;
    int             counter;
};
