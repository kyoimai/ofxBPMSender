//
//  ofxBPMSender.cpp
//  ofxBPMSender
//
//  Created by 今井亨 on 2020/04/18.
//

#include "ofxBPMSender.hpp"

//絶対に書くやつ----------------------------------------

void ofxBPMSender::update(){
    calculateTime();
    noticeBPM();
}

float ofxBPMSender::getBPM(){
    return bpm;
}

bool ofxBPMSender::getAttack(){
    return isAttack;
}




//key----------------------------------------------------------------
void ofxBPMSender::keyReleased(int key){
    if(tap_count % 2 == 0){
        ofLogNotice() << "first_tap";
        first_time = ofGetElapsedTimef();
    }
    if(tap_count % 2 == 1){
        ofLogNotice() << "second_tap";
        second_time = ofGetElapsedTimef();
        second_time_data = second_time;
        time_distance = second_time - first_time;
        calculateBPM(time_distance);
    }
    tap_count++;
}


//mouse--------------------------------------------------------------
void ofxBPMSender::setupButton(glm::vec2 _position, float _size){
    position = _position;
    size = _size;
}

void ofxBPMSender::drawButton(){
    if(isAttack){
        ofSetColor(255);
        ofDrawRectangle(position.x, position.y, size, size);
    }else{
        ofSetColor(0);
        ofDrawRectangle(position.x, position.y, size, size);
    }
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("tap here", position.x + size / 5, position.y + size / 2);
}


void ofxBPMSender::mouseReleased(int x, int y){
    if(position.x < x && x < position.x + size){
        if(position.y < y && y < position.y + size){
            if(tap_count % 2 == 0){
                ofLogNotice() << "first_tap";
                first_time = ofGetElapsedTimef();
            }
            if(tap_count % 2 == 1){
                ofLogNotice() << "second_tap";
                second_time = ofGetElapsedTimef();
                second_time_data = second_time;
                time_distance = second_time - first_time;
                calculateBPM(time_distance);
            }
            tap_count++;
        }
    }
}



//Private-----------------------------------------------------------
void ofxBPMSender::calculateBPM(float _time_distance){
    float _bpm = 60.f / _time_distance;
    bpm = _bpm;
}

void ofxBPMSender::noticeBPM(){
    if(second_time_data + time_distance < ofGetElapsedTimef()){
        second_time_data += time_distance;
        isAttack = true;
    }else{
        isAttack = false;
    }
}


void ofxBPMSender::calculateTime(){
    dtime = ofGetElapsedTimef() - lastTime;
    if(isAttack){
        lastTime = ofGetElapsedTimef();
        lastdtime = dtime;
    }
    dtime = ofMap(dtime, 0, time_distance, 0, 1, true);
    x = dtime;
}



//easing-----------------------------

//sine
float ofxBPMSender::easeInSine(float _min, float _max){
    float a = 1 - cos((x * PI) / 2);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutSine(float _min, float _max){
    float a = sin((x * PI) / 2);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutSine(float _min, float _max){
    float a = -(cos(PI * x) - 1) / 2;
    return ofMap(a, 0, 1, _min, _max);
}


//cubic
float ofxBPMSender::easeInCubic(float _min, float _max){
    float a = x * x * x;
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutCubic(float _min, float _max){
    float a = 1 - pow(1 - x, 3);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutCubic(float _min, float _max){
    float a = x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
    return ofMap(a, 0, 1, _min, _max);
}


//quint
float ofxBPMSender::easeInQuint(float _min, float _max){
    float a = x * x * x * x * x;
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutQuint(float _min, float _max){
    float a = 1 - pow(1 - x, 5);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutQuint(float _min, float _max){
    float a = x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
    return ofMap(a, 0, 1, _min, _max);
}


//circ
float ofxBPMSender::easeInCirc(float _min, float _max){
    float a = 1 - sqrt(1 - pow(x, 2));
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutCirc(float _min, float _max){
    float a = sqrt(1 - pow(x - 1, 2));
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutCirc(float _min, float _max){
    float a = x < 0.5
    ? (1 - sqrt(1 - pow(2 * x, 2))) / 2
    : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
    return ofMap(a, 0, 1, _min, _max);
}

//elastic
float ofxBPMSender::easeInElastic(float _min, float _max){
    float b = (2 * PI) / 3;
    float a = x == 0
    ? 0
    : x == 1
    ? 1
    : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * b);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutElastic(float _min, float _max){
    float b = (2 * PI) / 3;
    float a =  x == 0
    ? 0
    : x == 1
    ? 1
    : pow(2, -10 * x) * sin((x * 10 - 0.75) * b) + 1;
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutElastic(float _min, float _max){
    float b = (2 * PI) / 4.5;
    float a =  x == 0
    ? 0
    : x == 1
    ? 1
    : x < 0.5
    ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * b)) / 2
    : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * b)) / 2 + 1;
    return ofMap(a, 0, 1, _min, _max);
}


//quad
float ofxBPMSender::easeInQuad(float _min, float _max){
    float a = x * x;
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutQuad(float _min, float _max){
    float a = 1 - (1 - x) * (1 - x);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutQuad(float _min, float _max){
    float a = x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
    return ofMap(a, 0, 1, _min, _max);
}

//quart
float ofxBPMSender::easeInQuart(float _min, float _max){
    float a = x * x * x * x;
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutQuart(float _min, float _max){
    float a = 1 - pow(1 - x, 4);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutQuart(float _min, float _max){
    float a = x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
    return ofMap(a, 0, 1, _min, _max);
}

//expo
float ofxBPMSender::easeInExpo(float _min, float _max){
    float a = x == 0 ? 0 : pow(2, 10 * x - 10);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutExpo(float _min, float _max){
    float a = x == 1 ? 1 : 1 - pow(2, -10 * x);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutExpo(float _min, float _max){
    float a =  x == 0
    ? 0
    : x == 1
    ? 1
    : x < 0.5 ? pow(2, 20 * x - 10) / 2
    : (2 - pow(2, -20 * x + 10)) / 2;
    return ofMap(a, 0, 1, _min, _max);
}


//back
float ofxBPMSender::easeInBack(float _min, float _max){
    float b  = 1.70158;
    float c = b + 1;
    float a =  c * x * x * x - b * x * x;
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutBack(float _min, float _max){
    float b = 1.70158;
    float c = b + 1;
    float a =  1 + c * pow(x - 1, 3) + b * pow(x - 1, 2);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeInOutBack(float _min, float _max){
    float b = 1.70158;
    float c = b * 1.525;
    float a =  x < 0.5
    ? (pow(2 * x, 2) * ((c + 1) * 2 * x - c)) / 2
    : (pow(2 * x - 2, 2) * ((c + 1) * (x * 2 - 2) + c) + 2) / 2;
    return ofMap(a, 0, 1, _min, _max);
}


//bounce
float ofxBPMSender::easeInBounce(float _min, float _max){
    float a = 1 - easeOutBounce2(1 - x);
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutBounce(float _min, float _max){
    float n1 = 7.5625;
    float d1 = 2.75;
    float a;
    if (x < 1 / d1) {
        a =  n1 * x * x;
    } else if (x < 2 / d1) {
        a =  n1 * (x -= 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        a = n1 * (x -= 2.25 / d1) * x + 0.9375;
    } else {
        a =  n1 * (x -= 2.625 / d1) * x + 0.984375;
    }
    return ofMap(a, 0, 1, _min, _max);
}

float ofxBPMSender::easeOutBounce2(float _value){
    float n1 = 7.5625;
    float d1 = 2.75;
    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        return n1 * (x -= 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        return n1 * (x -= 2.25 / d1) * x + 0.9375;
    } else {
        return n1 * (x -= 2.625 / d1) * x + 0.984375;
    }
}

float ofxBPMSender::easeInOutBounce(float _min, float _max){
    float a = x < 0.5
    ? (1 - easeOutBounce2(1 - 2 * x)) / 2
    : (1 + easeOutBounce2(2 * x - 1)) / 2;
    return ofMap(a, 0, 1, _min, _max);
}
