#pragma once

#include <Poco/Net/HTTPRequestHandler.h>

class HeartbeatRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    /// Returns server version and verifies service health.
    void handleRequest(
        Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};
