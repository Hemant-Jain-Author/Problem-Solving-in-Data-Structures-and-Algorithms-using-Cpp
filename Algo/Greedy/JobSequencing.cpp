#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Job
{
	char id = '\u0000';
	int deadline = 0;
	int profit = 0;
	Job(char id, int deadline, int profit)
	{
		this->id = id;
		this->deadline = deadline;
		this->profit = profit;
	}
};

int JobSequencing(std::vector<char> &ids, std::vector<int> &deadlines, std::vector<int> &profits, int n)
{
	std::vector<Job*> jobs = std::vector<Job*>(n);
	int maxDL = deadlines[0];
	for (int i = 1; i < n; i++)
		maxDL = std::max(maxDL, deadlines[i]);

	for (int i = 0;i < n;i++)
		jobs[i] = new Job(ids[i], deadlines[i], profits[i]);

	std::sort(jobs.begin(), jobs.end(), [&](Job* a, Job* b) {return a->profit > b->profit;});
	std::vector<bool> result(maxDL);
	std::vector<char> job(maxDL);
	int profit = 0;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++)
	{
		for (int j = jobs[i]->deadline - 1; j >= 0; j--)
		{
			if (result[j] == false)
			{
				result[j] = true;
				job[j] = jobs[i]->id;
				profit += jobs[i]->profit;
				break;
			}
		}
	}
	std::cout << "Profit is :: " << profit << std::endl;
	std::cout << "Jobs selected are::";
	for (int i = 0;i < maxDL;i++)
	{
		if (job[i] != '\u0000')
		{
			std::cout << " " << job[i];
		}
	}
	return profit;
}

int main()
{
	std::vector<char> id = {'a', 'b', 'c', 'd', 'e'};
	std::vector<int> deadline = {3, 1, 2, 4, 4};
	std::vector<int> profit = {50, 40, 27, 31, 30};
	JobSequencing(id, deadline, profit, 5);
}

/*
Profit is :: 151
Jobs selected are:: b e a d
*/