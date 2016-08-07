#include "ofMain.h"
#include "CooperHewittAPI.h"

CooperHewittAPI::CooperHewittAPI() {

	apiEndpoint = "https://api.collection.cooperhewitt.org/rest/";
	requestMethod = "GET";

}

CooperHewittAPI::~CooperHewittAPI() {

}

string CooperHewittAPI::apiCall(string apiMethod, map<string, string> args) {

	string rsp;

	if (requestMethod == "GET") {
		rsp = apiGetCall(apiMethod, args);
	}

	return rsp;
}

string CooperHewittAPI::apiGetCall(string apiMethod, map<string, string> args)
{
	string url = buildRequestURL(apiMethod, args);
	ofHttpResponse resp = ofLoadURL(url);
	ofLog() << "apiGetCall response: " << resp.data << endl;

	return resp.data;
}

string CooperHewittAPI::buildRequestURL(string apiMethod, map<string, string> args)
{
	string url = apiEndpoint + "?" + "method=" + apiMethod;

	for (std::map<string, string>::iterator it = args.begin(); it != args.end(); ++it)
		url += "&" + it->first + "=" + it->second;

	return url;
}


