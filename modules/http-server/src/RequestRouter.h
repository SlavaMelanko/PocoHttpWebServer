
#pragma once

#include <Poco/Net/HTTPRequestHandlerFactory.h>

class RequestRouter
	: public Poco::Net::HTTPRequestHandlerFactory
{
public:
	Poco::Net::HTTPRequestHandler* createRequestHandler(
		const Poco::Net::HTTPServerRequest& request) override;
};
