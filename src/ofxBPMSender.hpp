//
//  ofxBPMSender.hpp
//  bpm_sender
//
//  Created by kyo imai on 2020/04/06.
//

#pragma once

#include "ofMain.h"

class ofxBPMSender{
  
public:
    ofxBPMSender();
    ~ofxBPMSender();
    
    
    static ofEvent<bool> attack;
    
    float bpm;
    
    void setButton(ofVec2f position, ofVec2f size);
    void updateBPM();
    void drawButton();
    
    float getBPM();
    void mousePressed(ofMouseEventArgs & args);
    
    bool is_on = false; //マウスを押した時
    bool is_attack = false; //bpm通知
    
    
//
    void keyPressed(ofKeyEventArgs & args);
    void keyReleased(ofKeyEventArgs & args);
    
//
    void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    void mouseScrolled(ofMouseEventArgs & args);
    void mouseEntered(ofMouseEventArgs & args);
    void mouseExited(ofMouseEventArgs & args);
    
private:
    ofVec2f position;
    ofVec2f size;

    int tap_count;
    
    float first_time;
    float second_time;
    float time_distance;
    float second_time_data;

    
    void calculateBPM(float time_distance);
    void noticeBPM();
};

