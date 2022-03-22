#include <string>
#include <vector>
#include <iostream>

int fastestWayBU2(std::vector<std::vector<int>> &a,
		std::vector<std::vector<int>> &t, std::vector<int> &e,
		std::vector<int> &x, int n) {
	std::vector<int> f1(n);
	std::vector<int> f2(n);

	// Time taken to leave first station.
	f1[0] = e[0] + a[0][0];
	f2[0] = e[1] + a[1][0];

	// Fill the tables f1[] and f2[] using bottom up approach.
	for (int i = 1; i < n; ++i) {
		f1[i] = std::min(f1[i - 1] + a[0][i],
				f2[i - 1] + t[1][i - 1] + a[0][i]);
		f2[i] = std::min(f2[i - 1] + a[1][i],
				f1[i - 1] + t[0][i - 1] + a[1][i]);
	}

	// Consider exit times and return minimum.
	return std::min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
}

int fastestWayBU(std::vector<std::vector<int>> &a,
		std::vector<std::vector<int>> &t, std::vector<int> &e,
		std::vector<int> &x, int n) {
	std::vector<std::vector<int>> f = std::vector<std::vector<int>>(2,
			std::vector<int>(n, 0));
	// Time taken to leave first station.
	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];

	// Fill the tables f1[] and f2[] using bottom up approach.
	for (int i = 1; i < n; ++i) {
		f[0][i] = std::min(f[0][i - 1] + a[0][i],
				f[1][i - 1] + t[1][i - 1] + a[0][i]);
		f[1][i] = std::min(f[1][i - 1] + a[1][i],
				f[0][i - 1] + t[0][i - 1] + a[1][i]);
	}

	// Consider exit times and return minimum.
	return std::min(f[0][n - 1] + x[0], f[1][n - 1] + x[1]);
}

void fastestWayTDUtil(std::vector<std::vector<int>> &f,
		std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &t,
		int i) {
	if (i == 0) {
		return;
	}
	fastestWayTDUtil(f, a, t, i - 1);
	// Fill the tables f1[] and f2[] using top-down approach.
	f[0][i] = std::min(f[0][i - 1] + a[0][i],
			f[1][i - 1] + t[1][i - 1] + a[0][i]);
	f[1][i] = std::min(f[1][i - 1] + a[1][i],
			f[0][i - 1] + t[0][i - 1] + a[1][i]);
}

int fastestWayTD(std::vector<std::vector<int>> &a,
		std::vector<std::vector<int>> &t, std::vector<int> &e,
		std::vector<int> &x, int n) {
	std::vector<std::vector<int>> f = std::vector<std::vector<int>>(2,
			std::vector<int>(n, 0));
	// Time taken to leave first station.
	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];

	fastestWayTDUtil(f, a, t, n - 1);
	return std::min(f[0][n - 1] + x[0], f[1][n - 1] + x[1]);
}

// Testing code.
int main() {
	std::vector<std::vector<int>> a = { { 7, 9, 3, 4, 8, 4 },
			{ 8, 5, 6, 4, 5, 7 } };
	std::vector<std::vector<int>> t = { { 2, 3, 1, 3, 4 }, { 2, 1, 2, 2, 1 } };
	std::vector<int> e = { 2, 4 };
	std::vector<int> x = { 3, 2 };
	int n = 6;
	std::cout << "fastestWay : " << fastestWayBU2(a, t, e, x, n) << std::endl;
	std::cout << "fastestWay : " << fastestWayBU(a, t, e, x, n) << std::endl;
	std::cout << "fastestWay : " << fastestWayTD(a, t, e, x, n) << std::endl;
}

/*
 fastestWay : 38
 fastestWay : 38
 fastestWay : 38
 */
