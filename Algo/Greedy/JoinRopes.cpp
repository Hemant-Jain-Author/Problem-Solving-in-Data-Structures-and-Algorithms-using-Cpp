#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

int joinRopes(std::vector<int> &ropes, int size) {
	std::sort(ropes.begin(), ropes.end(), [&](int a, int b) {
		return a > b;
	});
	int total = 0, value = 0, index, length = size;

	while (length >= 2) {
		value = ropes[length - 1] + ropes[length - 2];
		total += value;
		index = length - 2;
		while (index > 0 && ropes[index - 1] < value) {
			ropes[index] = ropes[index - 1];
			index -= 1;
		}
		ropes[index] = value;
		length--;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

int joinRopes2(std::vector<int> &ropes, int size) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < size; i++)
		pq.push(ropes[i]);

	int total = 0;
	int value = 0;
	while (pq.size() > 1) {
		value = pq.top();
		pq.pop();
		value += pq.top();
		pq.pop();
		pq.push(value);
		total += value;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

// Testing code.
int main() {
	std::vector<int> ropes = { 4, 3, 2, 6 };
	joinRopes(ropes, ropes.size());
	std::vector<int> rope2 = { 4, 3, 2, 6 };
	joinRopes2(rope2, rope2.size());
}

/*
 Total : 29
 Total : 29
 */
