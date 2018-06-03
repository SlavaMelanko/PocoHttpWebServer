#include "TimeRequestHandler.h"

#include <iostream>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Timestamp.h>
#include <Poco/Util/ServerApplication.h>

#include <utils/Chrono.h>

void TimeRequestHandler::handleRequest(
    Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    auto& app = Poco::Util::Application::instance();
    app.logger().information("Request from " + request.clientAddress().toString());

    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");

    std::ostream& ostr = response.send();
    ostr << "<html><head><title>HTTPTimeServer powered by POCO</title>";
    ostr << "<meta http-equiv=\"refresh\" content=\"1\"></head>";
    ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
    ostr << utils::chrono::GetCurrentDateTime();
    ostr << "</p></body></html>";
}
