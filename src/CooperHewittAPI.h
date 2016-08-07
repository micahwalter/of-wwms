#pragma once

#include "ofMain.h"

class CooperHewittAPI {

public:

	CooperHewittAPI();
	~CooperHewittAPI();

	string apiCall(string apiMethod, map<string, string> args);

protected:

	string requestMethod;
	string apiEndpoint;

	string apiGetCall(string apiMethod, map<string, string> args);
	string buildRequestURL(string apiMethod, map<string, string> args);

};