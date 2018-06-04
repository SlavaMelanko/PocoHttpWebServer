#include "HeartbeatRequestHandler.h"

#include <iostream>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>

#include "Version.h"

void HeartbeatRequestHandler::handleRequest(
    Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    auto& app = Poco::Util::Application::instance();
    app.logger().information("Request from " + request.clientAddress().toString());

    response.setContentType("text/html");

    std::ostream& ostr = response.send();
    ostr << "v" << APP_VERSION;
}
