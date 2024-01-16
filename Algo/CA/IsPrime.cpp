#include <string>
#include <vector>
#include <iostream>

bool isPrime(int n) {
	bool answer = (n > 1) ? true : false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			answer = false;
			break;
		}
	}
	return answer;
}

// Testing code.
int main() {
	std::cout << isPrime(7) << std::endl;
	return 0;
}

/*
 1
 */
