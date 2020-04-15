//
//  ofxBPMSender.cpp
//  bpm_sender
//
//  Created by kyo imai on 2020/04/06.
//

#include "ofxBPMSender.hpp"

ofEvent<bool> ofxBPMSender::attack = ofEvent<bool>();

ofxBPMSender::ofxBPMSender(){}
ofxBPMSender::~ofxBPMSender(){}


//--------------------------------------------------------------
void ofxBPMSender::setButton(ofVec2f position, ofVec2f size){
    this->position = position;
    this->size = size;
    bpm = 0.0;
    ofRegisterMouseEvents(this); //イベントの許可
    ofRegisterKeyEvents(this);
}

void ofxBPMSender::updateBPM(){
    noticeBPM();
}

void ofxBPMSender::drawButton(){
    noticeBPM();
    if(is_attack == true){
        ofSetColor(255);
        ofDrawRectangle(position.x-100, position.y, size.x, size.y);
        ofNoFill();
        ofSetColor(0, 0, 0);
        ofDrawRectangle(position.x-100, position.y, size.x, size.y);
        ofFill();
    }
    if(is_attack == false){
        ofSetColor(0);
        ofDrawRectangle(position.x-100, position.y, size.x, size.y);
    }
    
    ofSetColor(255, 0, 0);
    ofDrawRectangle(position.x, position.y, size.x, size.y);
    ofSetColor(255);
    ofDrawBitmapString("tap!!!", position.x + 20, position.y + 40);
    
    ofSetColor(255);
}

//--------------------------------------------------------------
float ofxBPMSender::getBPM(){
    return bpm;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------

void ofxBPMSender::noticeBPM(){
    if(second_time_data + time_distance < ofGetElapsedTimef()){
        second_time_data += time_distance;
        ofNotifyEvent(attack, is_attack);
        is_attack = true;
    }else{
        is_attack = false;
    }
}

void ofxBPMSender::calculateBPM(float time_distance){
    float _bpm = 60.f / time_distance;
    bpm = _bpm;
}

//--------------------------------------------------------------
void ofxBPMSender::mouseReleased(ofMouseEventArgs & args){
    if(position.x < args.x && args.x < position.x + size.x){
        if(position.y < args.y && args.y < position.y < args.y){
            is_on = true;
            if(tap_count % 2 == 0){
                cout << "first_tap" << endl;
                first_time = ofGetElapsedTimef();
            }
            if(tap_count % 2 == 1){
                cout << "second_tap" << endl;
                second_time = ofGetElapsedTimef();
                second_time_data = second_time;
                time_distance = second_time - first_time;
                calculateBPM(time_distance);
            }
            tap_count++;
        }
    }
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
void ofxBPMSender::mousePressed(ofMouseEventArgs & args){}
void ofxBPMSender::mouseMoved(ofMouseEventArgs & args){}
void ofxBPMSender::mouseDragged(ofMouseEventArgs & args){}
void ofxBPMSender::mouseScrolled(ofMouseEventArgs & args){}
void ofxBPMSender::mouseEntered(ofMouseEventArgs & args){}
void ofxBPMSender::mouseExited(ofMouseEventArgs & args){}


void ofxBPMSender::keyPressed(ofKeyEventArgs &args){}
void ofxBPMSender::keyReleased(ofKeyEventArgs &args){}
