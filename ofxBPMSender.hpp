//
//  ofxBPMSender.hpp
//  ofxBPMSender
//
//  Created by 今井亨 on 2020/04/18.
//
//This app returns bool type at the tempo you tapped at the time of VJ. The getAttack() type bool is used to receive the tempo, and the getBPM() type float is used to receive the bpm.
//このappはVJの時にタップしたテンポでbool型を返します。テンポの受け取りにはbool型の getAttack()、bpmの受け取りにはfloat 型getBPM()を使用。

//Basically, we're assuming that you'll be typing in KEY.
//基本的に、keyでの入力を想定しています。

#pragma once

#include "ofMain.h"

class ofxBPMSender{
    
    
    
//  key------------------------

    
//  mouse----------------------
    glm::vec2 position;
    float size;
    
//    tap_count;
    int tap_count = 0;
    
//    time manager
    float first_time;
    float second_time;
    float second_time_data;
    float time_distance;
    
    void calculateBPM(float _time_distance);
    void noticeBPM();
    
    float bpm; // -> getBPM()
    bool isAttack; // -> getAttack()
    
    

public:
//    絶対に書くやつ
    void update();
    float getBPM();
    bool getAttack();
    
//  key入力の時
    void keyReleased(int key);
    
//  mouse入力の時
    void setupButton(glm::vec2 _position, float _size);
    void drawButton();
    void mouseReleased(int x, int y);
};

