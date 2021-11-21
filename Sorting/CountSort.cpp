#include <vector>
#include <iostream>

void countSort(std::vector<int> &arr, int lowerRange, int upperRange)
{
	int i, j;
	int size = arr.size();
	int range = upperRange - lowerRange;
	std::vector<int> count(range);

	for (i = 0; i < size; i++)
	{
		count[arr[i] - lowerRange]++;
	}

	j = 0;
	for (i = 0; i < range; i++)
	{
		for (; count[i] > 0; count[i]--)
		{
			arr[j++] = i + lowerRange;
		}
	}
}

int main()
{
	std::vector<int> array = {23, 24, 22, 21, 26, 25, 27, 28, 21, 21};
	countSort(array, 20, 30);
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
}

/*
21 21 21 22 23 24 25 26 27 28
*/
