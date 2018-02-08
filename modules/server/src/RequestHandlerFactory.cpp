#include "RequestHandlerFactory.h"
#include "TimeRequestHandler.h"

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(
	const Poco::Net::HTTPServerRequest& request)
{
	if (request.getURI() == "/") {
		return new TimeRequestHandler{};
	} else {
		return nullptr;
	}
}
