#include <vector>

class BucketSort
{
private:
	std::vector<int>& data;
	int range = 0;
	int lowerRange = 0;
public:
	BucketSort(std::vector<int> &arr, int lowerRange, int upperRange);
	virtual void sort();
};
