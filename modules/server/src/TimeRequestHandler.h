
#pragma once

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class TimeRequestHandler
	: public Poco::Net::HTTPRequestHandler
{
public:
	/// Return a HTML document with the current date and time.
	void handleRequest(Poco::Net::HTTPServerRequest& request,
		Poco::Net::HTTPServerResponse& response) override;
};
