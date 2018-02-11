
#pragma once

#include <string>

#include <Poco/DateTimeFormat.h>

namespace utils
{
namespace chrono
{

/// Returns the current date and time according to the given format.
std::string GetCurrentDateTime(const std::string& format =
	Poco::DateTimeFormat::SORTABLE_FORMAT);

} } // namespace utils::chrono
