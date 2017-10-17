#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDarknet.h"
#include "ofxGui.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void resetVideoInterface();
	void updateGuiParamters();
	void update();
	void send_OSC_Data_AllInBlobs();
	void draw();

	ofxDarknet darknet;

	ofVideoGrabber videoGrabber;
	int totalNumDevices = 0;
	ofVideoPlayer videoPlayer;
	bool bNewFrameToProcess = false;
	ofPixels cropedArea;
	std::vector< detected_object > detections;

	//Blob Tracking
	vector<ofxCvBlob> blobsYolo;

	/////////////////////////////////////
	//Tracker	
	void drawTracking();
	cv::Vec2f getVelocity(unsigned int i) const;
	unsigned int getLabel(unsigned int i) const;
	ofxCv::RectTracker & getTracker();
	ofxCv::RectTracker tracker;
	std::vector<cv::Rect> boundingRects;

	///////////////
	//GUI
	ofxPanel gui;
	//Croping camera
	ofParameter<float> cropSizeX;
	ofParameter<float> cropSizeY;
	ofParameter<float> cropSizeW;
	ofParameter<float> cropSizeH;
	//yolo gui
	ofParameter<float> maxRectAreaDetection;
	ofParameter<float> percentPersonDetected;
	ofParameter<float> maxOverlap;
	ofParameter<bool> bVideoPlayer;
	ofParameter<int> idVideoGrabber;

	ofParameter<bool> bSwapX;
	ofParameter<bool> bSwapY;
	ofParameter<bool> bDrawYoloInfo;
	//tracker gui
	ofParameter<float> trackerPersistence;
	float last_trackerPersistence;
	ofParameter<float> trackerMaximimDistance;
	float last_trackerMaximimDistance;
	ofParameter<float> trackerSmoothingRate;
	float last_trackerSmoothingRate;

	//
	void keyPressed(int key);

	///////////////////////////////
	//OSC filterd data
	ofxOscSender sender;

	//OSC CONFIG
	bool bResetHostIp = false;
	int PORT = 12345;
	string HOST = "127.0.0.1";//MLP: "192.168.2.254";
};
