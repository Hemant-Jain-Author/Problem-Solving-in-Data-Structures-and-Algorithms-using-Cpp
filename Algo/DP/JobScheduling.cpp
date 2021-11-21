#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Job
{
	int start = 0, stop = 0, value = 0;
	Job(int s, int f, int v);
};

Job::Job(int s, int f, int v)
{
	start = s;
	stop = f;
	value = v;
}

int comp(Job *j1, Job *j2) // for sorting.
{
	return j1->stop < j2->stop;
}

int maxValueJobUtil(std::vector<Job*> &arr, int n)
{
	// Base case
	if (n == 1)
		return arr[0]->value;

	// Find Value when current job is included
	int incl = arr[n - 1]->value;
	for (int j = n - 1; j >= 0; j--)
	{
		if (arr[j]->stop <= arr[n - 1]->start)
		{
			incl += maxValueJobUtil(arr, j + 1);
			break;
		}
	}

	// Find Value when current job is excluded
	int excl = maxValueJobUtil(arr, n - 1);

	return std::max(incl, excl);
}

int maxValueJobs(std::vector<int> &s, std::vector<int> &f, std::vector<int> &v, int n)
{
	std::vector<Job*> act(n);
	for (int i = 0;i < n;i++)
		act[i] = new Job(s[i], f[i], v[i]);

	std::sort(act.begin(), act.end(), comp); // sort according to finish time.
	return maxValueJobUtil(act, n);
}

int maxValueJobTDUtil(std::vector<int> &dp, std::vector<Job*> &arr, int n)
{
	// Base case
	if (n == 0)
		return 0;

	if (dp[n - 1] != 0)
		return dp[n - 1];

	// Find Value when current job is included
	int incl = arr[n - 1]->value;
	for (int j = n - 2; j >= 0; j--)
	{
		if (arr[j]->stop <= arr[n - 1]->start)
		{
			incl += maxValueJobTDUtil(dp, arr, j + 1);
			break;
		}
	}

	// Find Value when current job is excluded
	int excl = maxValueJobTDUtil(dp, arr, n - 1);
	dp[n - 1] = std::max(incl, excl);
	return dp[n - 1];
}

int maxValueJobsTD(std::vector<int> &s, std::vector<int> &f, std::vector<int> &v, int n)
{
	std::vector<Job*> act(n);
	for (int i = 0;i < n;i++)
		act[i] = new Job(s[i], f[i], v[i]);

	std::sort(act.begin(), act.end(), comp); // sort according to finish time.
	std::vector<int> dp(n);
	return maxValueJobTDUtil(dp, act, n);
}

int maxValueJobsBU(std::vector<int> &s, std::vector<int> &f, std::vector<int> &v, int n)
{
	std::vector<Job*> act(n);
	for (int i = 0;i < n;i++)
		act[i] = new Job(s[i], f[i], v[i]);

	std::sort(act.begin(), act.end(), comp); // sort according to finish time.
	std::vector<int> dp(n);
	dp[0] = act[0]->value;

	for (int i = 1; i < n; i++)
	{
		int incl = act[i]->value;
		for (int j = i - 1; j >= 0; j--)
		{
			if (act[j]->stop <= act[i]->start)
			{
				incl += dp[j];
				break;
			}
		}
		dp[i] = std::max(incl, dp[i - 1]);
	}
	return dp[n - 1];
}

int main()
{
	std::vector<int> start = {1, 5, 0, 3, 5, 6, 8};
	std::vector<int> finish = {2, 6, 5, 4, 9, 7, 9};
	std::vector<int> value = {2, 2, 4, 3, 10, 2, 8};
	int n = start.size();
	std::cout << maxValueJobs(start, finish, value, n) << std::endl;
	std::cout << maxValueJobsTD(start, finish, value, n) << std::endl;
	std::cout << maxValueJobsBU(start, finish, value, n) << std::endl;
}

/*
17
17
17
*/