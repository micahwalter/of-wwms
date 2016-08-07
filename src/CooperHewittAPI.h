#pragma once

#include "ofMain.h"

class CooperHewittAPI {

public:

	CooperHewittAPI();
	~CooperHewittAPI();

	string apiCall(string apiToken, string apiMethod, map<string, string> args);

protected:

	string apiEndpoint;
	string apiToken;

	string apiMethod;

	map<string, string> args;
};