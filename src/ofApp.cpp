#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLog() << "Hello World!" << endl;

	ofFile apiSettings;

	apiSettings.open(ofToDataPath("api_settings.txt"), ofFile::ReadWrite, false);
	ofBuffer buff = apiSettings.readToBuffer();
	
	string token = buff;

	string endpoint = "https://api.collection.cooperhewitt.org/rest/";
	string method = "cooperhewitt.labs.whatWouldMicahSay";

	string url = endpoint + "?" + "method=" + method + "&access_token=" + token;

	ofHttpResponse resp = ofLoadURL(url);
	ofLog() << resp.data << endl;

	apiResponse = resp.data;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofClear(0);
	ofDrawBitmapString("Hello World!", 100, 100);

	ofDrawBitmapString(apiResponse, 100, 120);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
