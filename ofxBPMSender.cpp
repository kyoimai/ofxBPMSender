//
//  ofxBPMSender.cpp
//  ofxBPMSender
//
//  Created by 今井亨 on 2020/04/18.
//

#include "ofxBPMSender.hpp"

//絶対に書くやつ----------------------------------------

void ofxBPMSender::update(){
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



