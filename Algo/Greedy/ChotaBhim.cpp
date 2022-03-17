#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

int chotaBhim(std::vector<int> &cups) {
	int size = cups.size();
	int time = 60;
	std::sort(cups.begin(), cups.end(), std::greater<int>()); // decreasing order.
	int total = 0;
	int index, temp;
	while (time > 0) {
		total += cups[0];
		cups[0] = std::ceil(cups[0] / 2.0);
		index = 0;
		temp = cups[0];
		while (index < size - 1 && temp < cups[index + 1]) {
			cups[index] = cups[index + 1];
			index += 1;
		}
		cups[index] = temp;
		time -= 1;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

int chotaBhim2(std::vector<int> &cups) {
	int size = cups.size();
	int time = 60;
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;
	for (int i = 0; i < size; i++) {
		pq.push(cups[i]);
	}
	int total = 0;
	int value;
	while (time > 0) {
		value = pq.top();
		pq.pop();
		total += value;
		value = std::ceil(value / 2.0);
		pq.push(value);
		time -= 1;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

// Testing code.
int main() {
	std::vector<int> cups = { 2, 1, 7, 4, 2 };
	chotaBhim(cups);
	std::vector<int> cups2 = { 2, 1, 7, 4, 2 };
	chotaBhim2(cups2);
}

/*
 Total : 76
 Total : 76
 */
