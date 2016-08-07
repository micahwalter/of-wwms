#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class CooperHewittAPI {

public:

	CooperHewittAPI();
	~CooperHewittAPI();

	ofxJSONElement apiCall(string apiMethod, map<string, string> args);
	void setAPIEndpoint(string endpoint);
	void setAPIArgs(map<string, string> args);

protected:

	string requestMethod;
	string apiEndpoint;
	map<string, string> apiArgs;

	ofxJSONElement apiResponse;

	ofxJSONElement apiGetCall(string apiMethod, map<string, string> args);
	string buildRequestURL(string apiMethod, map<string, string> args);

};