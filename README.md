# ofxBPMSender

### Feature
* This is an addon that keeps sending the tempo that you tap.
* It can be received by either button or keystroke.

### How to
```
ofApp.h
ofxBPMSender bpm;

//If you type with the button-----------------------------------------------------
ofApp.cpp
void ofApp::setup(){
  bpm.setButton(glm::vec2 position, float size);
}

void ofApp::update(){
  bpm.update();
  if(bpm.getBPM() > 1 && bpm.getAttack()){
    ofLogNotice() << "bpm : " << bpm.getBPM() << " bool : " << bpm.getAttack();
  }
}

void ofApp::draw(){
  bpm.drawButton();
}


//If you are typing with key------------------------------------------------------
ofApp.cpp
void ofApp::update(){
bpm.update();
  if(bpm.getBPM() > 1 && bpm.getAttack()){
    ofLogNotice() << "bpm : " << bpm.getBPM() << " bool : " << bpm.getAttack();
  }
}

void ofApp::keyReleased(int x, int y, int button){
  bpm.mouseReleased(x, y);
}
