#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Items 
{
	int wt = 0;
	int cost = 0;
	double density = 0;

	Items(int w, int v)
	{
		wt = w;
		cost = v;
		density = static_cast<double>(cost) / wt;
	}
};

bool compare(Items* a, Items* b){
	return a->density > b->density;
}

double getMaxCostFractional(std::vector<int> &wt, std::vector<int> &cost, int capacity)
{
	double totalCost = 0;
	int n = wt.size();
	std::vector<Items*> itemList(n);
	for (int i = 0; i < n; i++)
	{
		itemList[i] = new Items(wt[i], cost[i]);
	}

	std::sort(itemList.begin(), itemList.end(), &compare); // decreasing order.
	for (int i = 0; i < n; i++)
	{
		if (capacity - itemList[i]->wt >= 0)
		{
			capacity -= itemList[i]->wt;
			totalCost += itemList[i]->cost;
		}
		else
		{
			totalCost += (itemList[i]->density * capacity);
			break;
		}
	}
	return totalCost;
}

int main()
{
	std::vector<int> wt = {10, 40, 20, 30};
	std::vector<int> cost = {60, 40, 90, 120};
	int capacity = 50;
	double maxCost = getMaxCostFractional(wt, cost, capacity);
	std::cout << "Maximum cost obtained = " << maxCost << std::endl;
}

/*
Maximum cost obtained = 230
*/