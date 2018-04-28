
#include "utils/Chrono.h"

#include <Poco/DateTimeFormatter.h>

namespace utils
{
namespace chrono
{

char foo() {
	char* x = (char*)malloc(10 * sizeof(char));
	free(x);
	return x[5];
}

std::string GetCurrentDateTime(const std::string& format)
{
	// AddressSanitizer
	auto test = foo();

	// One more error
	int* array = new int[100];
	array[0] = 0;
	int res = array[111 + 100]; // BOOM
	delete [] array;

	// Create a timestamp with the current time.
	Poco::Timestamp now;

	return Poco::DateTimeFormatter::format(now, format);
}

} } // namespace utils::chrono
