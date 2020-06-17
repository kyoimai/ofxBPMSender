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
    
    
    void calculateTime();
    float dtime;
    float lastTime;
    float lastdtime;
    
    float bpm; // -> getBPM()
    bool isAttack; // -> getAttack()
    
//    easing
    float x;
    
public:
    //    絶対に書くやつ
    void update();
    float getBPM();
    bool getAttack();
    
    
//    https://easings.net/ja easing fuctions
    
    float easeInSine(float _min, float _max);
    float easeOutSine(float _min, float _max);
    float easeInOutSine(float _min, float _max);
    float easeInCubic(float _min, float _max);
    float easeOutCubic(float _min, float _max);
    float easeInOutCubic(float _min, float _max);
    float easeInQuint(float _min, float _max);
    float easeOutQuint(float _min, float _max);
    float easeInOutQuint(float _min, float _max);
    float easeInCirc(float _min, float _max);
    float easeOutCirc(float _min, float _max);
    float easeInOutCirc(float _min, float _max);
    float easeInElastic(float _min, float _max);
    float easeOutElastic(float _min, float _max);
    float easeInOutElastic(float _min, float _max);
    float easeInQuad(float _min, float _max);
    float easeOutQuad(float _min, float _max);
    float easeInOutQuad(float _min, float _max);
    float easeInQuart(float _min, float _max);
    float easeOutQuart(float _min, float _max);
    float easeInOutQuart(float _min, float _max);
    float easeInExpo(float _min, float _max);
    float easeOutExpo(float _min, float _max);
    float easeInOutExpo(float _min, float _max);
    float easeInBack(float _min, float _max);
    float easeOutBack(float _min, float _max);
    float easeInOutBack(float _min, float _max);
    float easeInBounce(float _min, float _max);
    float easeOutBounce(float _min, float _max);
    float easeOutBounce2(float _value);
    float easeInOutBounce(float _min, float _max);
    
    
//  key入力の時------------------------------
    void keyReleased(int key);
    
//  mouse入力の時----------------------------
    void setupButton(glm::vec2 _position, float _size);
    void drawButton();
    void mouseReleased(int x, int y);
};

