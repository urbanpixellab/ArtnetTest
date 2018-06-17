#pragma once

#include "ofMain.h"
#include "ofxArtnetProtocol.h"

class ofApp : public ofBaseApp{

private:
    
    struct stripe
    {
        vector<int> ledBegin;
    };
    
    
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
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
    
    ofxArtnetProtocol artnet;
    uint8_t universe1[6*6*3];//33leds = 99 values in rgb
    ofFbo       fbo;
    ofPixels    pixels;
    
    vector<stripe>      downStripes;
};
