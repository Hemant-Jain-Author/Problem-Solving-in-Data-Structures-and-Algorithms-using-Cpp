#include "HeapMedian.h"

void MedianHeap::insert(int value) {
	if (maxHeap.size() == 0 || maxHeap.top() >= value)
		maxHeap.push(value);
	else
		minHeap.push(value);

	// size balancing
	if (maxHeap.size() > minHeap.size() + 1) {
		value = maxHeap.top();
		maxHeap.pop();
		minHeap.push(value);
	}

	if (minHeap.size() > maxHeap.size() + 1) {
		value = minHeap.top();
		minHeap.pop();
		maxHeap.push(value);
	}
}

int MedianHeap::getMedian() {
	if (maxHeap.size() == 0 && minHeap.size() == 0)
		throw "HeapEmptyException";

	if (maxHeap.size() == minHeap.size())
		return (maxHeap.top() + minHeap.top()) / 2;
	else if (maxHeap.size() > minHeap.size())
		return maxHeap.top();
	else
		return minHeap.top();
}

// Testing code.
int main() {
	std::vector<int> arr = { 1, 9, 2, 8, 3, 7 };
	MedianHeap hp;

	for (int i = 0; i < 6; i++) {
		hp.insert(arr[i]);
		std::cout << "Median after insertion of " << arr[i] << " is "
				<< hp.getMedian() << std::endl;
	}
}

/*
 Median after insertion of 1 is 1
 Median after insertion of 9 is 5
 Median after insertion of 2 is 2
 Median after insertion of 8 is 5
 Median after insertion of 3 is 3
 Median after insertion of 7 is 5
 */
