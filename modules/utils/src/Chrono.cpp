
#include "utils/Chrono.h"

#include <Poco/DateTimeFormatter.h>

namespace utils
{
namespace chrono
{

int Global;

void* Thread1(void* x)
{
	Global++;
	return NULL;
}

void* Thread2(void* x)
{
	Global--;
	return NULL;
}

std::string GetCurrentDateTime(const std::string& format)
{
	// AddressSanitizer
	auto test = []() {
		int *array = new int[100];
		delete [] array;
		return array[3]; // BOOM
	}();

	// ThreadSanitizer
	[]() {
		pthread_t t[2];
		pthread_create(&t[0], NULL, Thread1, NULL);
		pthread_create(&t[1], NULL, Thread2, NULL);
		pthread_join(t[0], NULL);
		pthread_join(t[1], NULL);
	}();

	// MemorySanitizer
	[]() {
		int* a = new int[10];
		a[5] = 0;
		if (a[2]) {
			printf("xx\n");
		}
	}();
	// Create a timestamp with the current time.
	Poco::Timestamp now;

	return Poco::DateTimeFormatter::format(now, format);
}

} } // namespace utils::chrono
