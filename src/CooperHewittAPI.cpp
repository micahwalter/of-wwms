#include "ofMain.h"
#include "CooperHewittAPI.h"

CooperHewittAPI::CooperHewittAPI() {

}

CooperHewittAPI::~CooperHewittAPI() {

}

string CooperHewittAPI::apiCall(string apiToken, string apiMethod, map<string, string> args) {

	string endpoint = "https://api.collection.cooperhewitt.org/rest/";

	string url = endpoint + "?" + "method=" + apiMethod + "&access_token=" +apiToken;

	ofHttpResponse resp = ofLoadURL(url);
	ofLog() << "From the class: " << resp.data << endl;

	return resp.data;
}