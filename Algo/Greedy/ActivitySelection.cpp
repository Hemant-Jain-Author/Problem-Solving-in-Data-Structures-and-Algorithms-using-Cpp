#include <vector>
#include <iostream>
#include <algorithm>

struct Activity {
	int start = 0;
	int stop = 0;
	Activity(int s, int f) {
		start = s;
		stop = f;
	}
};

bool compare(Activity *s1, Activity *s2) {
	return (s1->stop < s2->stop);
}

void maxActivities(std::vector<int> &s, std::vector<int> &f, int n) {
	std::vector<Activity*> act(n);
	for (int i = 0; i < n; i++) {
		act[i] = new Activity(s[i], f[i]);
	}

	std::sort(act.begin(), act.end(), compare); // sort according to finish time.
	int i = 0; // The first activity at index 0 is always gets selected.
	std::cout << "Activities are : (" << act[i]->start << "," << act[i]->stop
			<< ")";

	for (int j = 1; j < n; j++) {
		// Find next activity whose start time is greater than or equal
		// to the finish time of previous activity.
		if (act[j]->start >= act[i]->stop) {
			std::cout << ", (" << act[j]->start << "," << act[j]->stop << ")";
			i = j;
		}
	}
}

// Testing code.
int main() {
	std::vector<int> s = { 1, 5, 0, 3, 5, 6, 8 };
	std::vector<int> f = { 2, 6, 5, 4, 9, 7, 9 };
	maxActivities(s, f, s.size());
	return 0;
}
