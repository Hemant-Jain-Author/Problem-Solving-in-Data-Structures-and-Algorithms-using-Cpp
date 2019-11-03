#include <string>
#include <vector>
#include <iostream>
#include <limits>

int main()
{
	char maxByte = std::numeric_limits<char>::max();
	char minByte = std::numeric_limits<char>::min();

	short maxShort = std::numeric_limits<short>::max();
	short minShort = std::numeric_limits<short>::min();

	int maxInteger = std::numeric_limits<int>::max();
	int minInteger = std::numeric_limits<int>::min();

	long long maxLong = std::numeric_limits<long long>::max();
	long long minLong = std::numeric_limits<long long>::min();

	float maxFloat = std::numeric_limits<float>::max();
	float minFloat = std::numeric_limits<float>::min();

	double maxDouble = std::numeric_limits<double>::max();
	double minDouble = std::numeric_limits<double>::min();

	std::cout << "Range of byte :: " << (int)minByte << " to " << (int)maxByte <<  std::endl;
	std::cout << "Range of short :: " << minShort << " to " << maxShort <<  std::endl;
	std::cout << "Range of integer :: " << minInteger << " to " << maxInteger <<  std::endl;
	std::cout << "Range of long :: " << minLong << " to " << maxLong <<  std::endl;
	std::cout << "Range of float :: " << minFloat << " to " << maxFloat <<  std::endl;
	std::cout << "Range of double :: " << minDouble << " to " << maxDouble <<  std::endl;
	
	return 0;
}
