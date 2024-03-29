#include <string>
#include <map>
#include <vector>
#include <iostream>

template<typename T>
class CountMap {
public:
	std::map<T, int> hm;

	void add(T key) {
		if (hm.find(key) != hm.end()) {
			int count = hm[key];
			hm[key] = count + 1;
		} else {
			hm[key] = 1;
		}
	}

	void remove(T key) {
		if (hm.find(key) != hm.end()) {
			if (hm[key] == 1) {
				hm.erase(key);
			} else {
				hm[key] = hm[key] - 1;
			}
		}
	}

	int get(T key) {
		if (hm.find(key) != hm.end()) {
			return hm[key];
		}
		return 0;
	}

	bool containsKey(T key) {
		return hm.find(key) != hm.end();
	}

	int size() {
		return hm.size();
	}
};

int main() {
	CountMap<int> cm;
	cm.add(2);
	cm.add(2);
	std::cout << "count is : " << cm.get(2) << std::endl;
	cm.remove(2);
	std::cout << "count is : " << cm.get(2) << std::endl;
	std::cout << "count is : " << cm.get(3) << std::endl;
	return 0;
}

/*
count is : 2
count is : 1
count is : 0
 */
