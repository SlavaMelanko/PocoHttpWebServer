
#include "utils/Chrono.h"

#include <Poco/DateTimeFormatter.h>

namespace utils {
namespace chrono {
std::string GetCurrentDateTime(const std::string& format)
{
    // Create a timestamp with the current time.
    Poco::Timestamp now;

    return Poco::DateTimeFormatter::format(now, format);
}

}    // namespace chrono
}    // namespace utils
