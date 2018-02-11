
#include <regex>

#include <catch/catch.hpp>

#include <utils/Chrono.h>

TEST_CASE("Chrono: Check SORTABLE_FORMAT")
{
	const auto now = utils::chrono::GetCurrentDateTime();
	// 2018-01-01 00:00:01
	std::regex pattern{ "\\d{4}[-]\\d{2}[-]\\d{2} \\d{2}[:]\\d{2}[:]\\d{2}" };
	std::smatch match;
	REQUIRE(std::regex_search(now, match, pattern));
}
