#include "ofMain.h"
#include "CooperHewittAPI.h"

CooperHewittAPI::CooperHewittAPI() {

	apiEndpoint = "https://api.collection.cooperhewitt.org/rest/";
	requestMethod = "GET";

}

CooperHewittAPI::~CooperHewittAPI() {

}

ofxJSONElement CooperHewittAPI::apiCall(string apiMethod, map<string, string> args) {

	ofxJSONElement rsp;

	if (requestMethod == "GET") {
		rsp = apiGetCall(apiMethod, args);
	}

	return rsp;
}

void CooperHewittAPI::setAPIEndpoint(string endpoint)
{
	apiEndpoint = endpoint;
}

void CooperHewittAPI::setAPIArgs(map<string, string> args)
{
	apiArgs = args;
}

ofxJSONElement CooperHewittAPI::apiGetCall(string apiMethod, map<string, string> args)
{
	string url = buildRequestURL(apiMethod, args);
	apiResponse.open(url);

	ofLog() << "apiGetCall response: " << apiResponse.getRawString();

	return apiResponse;
}

string CooperHewittAPI::buildRequestURL(string apiMethod, map<string, string> args)
{
	string url = apiEndpoint + "?" + "method=" + apiMethod;

	for (std::map<string, string>::iterator it = args.begin(); it != args.end(); ++it)
		url += "&" + it->first + "=" + it->second;

	return url;
}


