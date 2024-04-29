#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	for (int x = -230; x <= 230; x += 230) {

		for (int y = -230; y <= 230; y += 230) {

			glm::vec3 noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
			for (int i = 0; i < 500; i++) {

				color.setHsb(ofMap(i, 0, 500, 0, 255), 180, 230);

				ofPushMatrix();
				ofTranslate(x, y);

				ofRotateZ(ofMap(ofNoise(noise_seed.z, i * 0.001 + ofGetFrameNum() * 0.025), 0, 1, -180, 180));
				ofRotateY(ofMap(ofNoise(noise_seed.y, i * 0.001 + ofGetFrameNum() * 0.025), 0, 1, -180, 180));
				ofRotateX(ofMap(ofNoise(noise_seed.x, i * 0.001 + ofGetFrameNum() * 0.025), 0, 1, -180, 180));

				ofSetColor(color);
				ofDrawSphere(-70, 0, 5);
				ofDrawSphere(70, 0, 5);

				ofPopMatrix();
			}
		}
	}

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}