#include "RequestRouter.h"
#include "HeartbeatRequestHandler.h"
#include "TimeRequestHandler.h"

#include <Poco/Net/HTTPServerRequest.h>

Poco::Net::HTTPRequestHandler* RequestRouter::createRequestHandler(
	const Poco::Net::HTTPServerRequest& request)
{
	if (request.getURI() == "/") {
		return new TimeRequestHandler{};
	} else if (request.getURI() == "/heartbeat") {
		return new HeartbeatRequestHandler{};
	} else {
		return nullptr;
	}
}
