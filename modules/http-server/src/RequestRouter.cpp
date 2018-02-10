#include "RequestRouter.h"
#include "TimeRequestHandler.h"

Poco::Net::HTTPRequestHandler* RequestRouter::createRequestHandler(
	const Poco::Net::HTTPServerRequest& request)
{
	if (request.getURI() == "/") {
		return new TimeRequestHandler{};
	} else {
		return nullptr;
	}
}
