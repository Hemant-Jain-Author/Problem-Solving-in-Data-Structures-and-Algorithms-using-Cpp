#include <string>
#include <vector>
#include <iostream>
#include <queue>

int merge(std::vector<int> &lists, int size) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < size; i++) {
		pq.push(lists[i]);
	}

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
	std::vector<int> lists = { 4, 3, 2, 6 };
	merge(lists, lists.size());
}

/*
 Total : 29
 */
