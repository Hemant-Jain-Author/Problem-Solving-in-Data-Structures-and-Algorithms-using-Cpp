#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

struct Point {
	int x = 0;
	int y = 0;

	Point(int a, int b) {
		x = a;
		y = b;
	}
};

double closestPairBF(std::vector<std::vector<int>> &arr) {
	int n = arr.size();
	double dmin = std::numeric_limits<double>::max();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			dmin = std::min(dmin,
					std::sqrt(
							(arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])
									+ (arr[i][1] - arr[j][1])
											* (arr[i][1] - arr[j][1])));
		}
	}
	return dmin;
}

double distance(Point *a, Point *b) {
	return std::sqrt(
			(a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

bool xCompare(Point *s1, Point *s2) {
	return (s1->x < s2->x);
}

bool yCompare(Point *s1, Point *s2) {
	return (s1->y < s2->y);
}

double stripMin(std::vector<Point*> &q, int n, double d) {
	double min = d;

	// Find the distance between all the points in the strip. 
	// Array q is sorted according to the y axis coordinate.
	// The inner loop will run at most 6 times for each point.
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n && (q[j]->y - q[i]->y) < min; ++j) {
			min = std::min(min, distance(q[i], q[j]));
		}
	}
	return min;
}

double closestPairUtil(std::vector<Point*> &p, int start, int stop,
		std::vector<Point*> &q, int n) {
	if (stop - start < 1) {
		return std::numeric_limits<double>::max();
	}

	if (stop - start == 1) {
		return distance(p[start], p[stop]);
	}

	// Find the middle point
	int mid = (start + stop) / 2;
	double dl = closestPairUtil(p, start, mid, q, n);
	double dr = closestPairUtil(p, mid + 1, stop, q, n);
	double d = std::min(dl, dr);

	// Build an array strip[] that contains points whose x axis coordinate
	// in the range p[mid]-d and p[mid]+d
	// Points are already sorted according to y axis.
	std::vector<Point*> strip(n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (std::abs(q[i]->x - p[mid]->x) < d) {
			strip[j] = q[i];
			j++;
		}
	}
	// Find the closest points in strip and compare with d.
	return std::min(d, stripMin(strip, j, d));
}

double closestPairDC(std::vector<std::vector<int>> &arr) {
	int n = arr.size();
	std::vector<Point*> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = new Point(arr[i][0], arr[i][1]);
	}
	// Sort according to x axis.
	std::sort(p.begin(), p.end(), &xCompare);

	std::vector<Point*> q(p); //clone
	// Sort according to y axis.
	std::sort(q.begin(), q.end(), &yCompare);
	return closestPairUtil(p, 0, n - 1, q, n);
}

int main() {
	std::vector<std::vector<int>> arr = { { 648, 896 }, { 269, 879 },
			{ 250, 922 }, { 453, 347 }, { 213, 17 } };
	std::cout << "Smallest distance is:" << closestPairBF(arr) << std::endl;
	std::cout << "Smallest distance is:" << closestPairDC(arr) << std::endl;
	return 0;
}

/*
 Smallest distance is:47.0106
 Smallest distance is:47.0106
 */
