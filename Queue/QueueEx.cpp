#include <vector>
#include <queue>
#include <math.h>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>

int circularTour(std::vector<std::vector<int>> &arr, int n) {
	for (int i = 0; i < n; i++) {
		int total = 0;
		bool found = true;
		for (int j = 0; j < n; j++) {
			total += (arr[(i + j) % n][0] - arr[(i + j) % n][1]);
			if (total < 0) {
				found = false;
				break;
			}
		}
		if (found) {
			return i;
		}
	}
	return -1;
}

int circularTour2(std::vector<std::vector<int>> &arr, int n) {
	std::queue<int> que;
	int nextPump = 0, prevPump;
	int count = 0;
	int petrol = 0;
	int ret;

	while (que.size() != n) {
		while (petrol >= 0 && que.size() != n) {
			que.push(nextPump);
			petrol += (arr[nextPump][0] - arr[nextPump][1]);
			nextPump = (nextPump + 1) % n;
		}
		while (petrol < 0 && que.size() > 0) {
			prevPump = que.front();
			que.pop();
			petrol -= (arr[prevPump][0] - arr[prevPump][1]);
		}
		count += 1;
		if (count == n)
			return -1;
	}
	if (petrol >= 0) {
		ret = que.front();
		que.pop();
		return ret;
	} else
		return -1;
}

// Testing code.
int main1() {
	std::vector<std::vector<int>> tour = { { 8, 6 }, { 1, 4 }, { 7, 6 } };
	std::cout << "Circular Tour : " << circularTour(tour, 3) << std::endl;
	std::cout << "Circular Tour : " << circularTour2(tour, 3) << std::endl;
	return 0;
}

/*
 Circular Tour : 2
 */

int convertXY(int src, int dst) {
	std::queue<int> que;
	std::vector<int> arr(100);
	int steps = 0;
	int index = 0;
	int value;

	que.push(src);
	while (que.size() != 0) {
		value = que.front();
		que.pop();
		arr[index++] = value;

		if (value == dst) {
			std::cout << "Steps count :: " << steps << std::endl;
			return steps;
		}
		steps++;
		if (value < dst)
			que.push(value * 2);
		else
			que.push(value - 1);
	}
	return -1;
}

// Testing code.
int main2() {
	convertXY(2, 7);
	return 0;
}

/*
 Steps count :: 3
 */

#include <deque>

void maxSlidingWindows(std::vector<int> &arr, int size, int k) {
	for (int i = 0; i < size - k + 1; i++) {
		int max = arr[i];
		for (int j = 1; j < k; j++) {
			max = std::max(max, arr[i + j]);
		}
		std::cout << max << " ";
	}
	std::cout << std::endl;
}

void maxSlidingWindows2(std::vector<int> arr, int size, int k) {
	std::deque<int> que;
	for (int i = 0; i < size; i++) {
		// Remove out of range elements
		if (que.size() > 0 && que.front() <= i - k) {
			que.front();
			que.pop_front();
		} // Remove smaller values at left.

		while (que.size() > 0 && arr[que.back()] <= arr[i])
			que.pop_back();

		que.push_back(i);
		// Largest value in window of size k is at index que[0]
		// It is displayed to the screen.
		if (i >= (k - 1))
			std::cout << arr[que.front()] << " ";
	}
}

// Testing code.
int main3() {
	std::vector<int> arr = { 11, 2, 75, 92, 59, 90, 55 };
	int k = 3;
	maxSlidingWindows(arr, 7, 3);
	maxSlidingWindows2(arr, 7, 3);
	return 0;
}

/*
 75 92 92 92 90
 */

int minOfMaxSlidingWindows(std::vector<int> arr, int size, int k) {
	std::queue<int> que;
	int minVal = 999999;
	for (int i = 0; i < size; i++) {
		// Remove out of range elements
		if (que.size() > 0 && que.front() <= i - k) {
			que.front();
			que.pop();
		}

		// Remove smaller values at left.
		while (que.size() > 0 && arr[que.back()] <= arr[i]) {
			que.front();
			que.pop();
		}

		que.push(i);
		// window of size k
		if (i >= (k - 1) && minVal > arr[que.front()])
			minVal = arr[que.front()];
	}
	std::cout << "Min of max is :: " << minVal << std::endl;
	return minVal;
}

// Testing code.
int main4() {
	std::vector<int> arr = { 11, 2, 75, 92, 59, 90, 55 };
	int k = 3;
	minOfMaxSlidingWindows(arr, 7, 3);
	return 0;
}

/*
 Min of max is :: 75
 */

void maxOfMinSlidingWindows(std::vector<int> arr, int size, int k) {
	std::queue<int> que;
	int maxVal = -999999;
	for (int i = 0; i < size; i++) {
		// Remove out of range elements
		if (que.size() > 0 && que.front() <= i - k) {
			que.front();
			que.pop();
		}        // Remove smaller values at left.
		while (que.size() > 0 && arr[que.back()] >= arr[i]) {
			que.front();
			que.pop();
		}
		que.push(i);
		// window of size k
		if (i >= (k - 1) && maxVal < arr[que.front()])
			maxVal = arr[que.front()];
	}
	std::cout << "Max of min is :: " << maxVal << std::endl;
}

// Testing code.
int main5() {
	std::vector<int> arr = { 11, 2, 75, 92, 59, 90, 55 };
	int k = 3;
	maxOfMinSlidingWindows(arr, 7, 3);
	// Output 59, as minimum values in sliding windows are [2, 2, 59, 59, 55]
	return 0;
}

/*
 Max of min is :: 59
 */

void firstNegSlidingWindows(std::vector<int> arr, int size, int k) {
	std::queue<int> que;

	for (int i = 0; i < size; i++) {
		// Remove out of range elements
		if (que.size() > 0 && que.front() <= i - k) {
			que.front();
			que.pop();
		}

		if (arr[i] < 0)
			que.push(i);
		// window of size k
		if (i >= (k - 1)) {
			if (que.size() > 0)
				std::cout << arr[que.front()] << " ";
			else
				std::cout << "NAN" << " ";
		}
	}
}

// Testing code.
int main6() {
	std::vector<int> arr = { 3, -2, -6, 10, -14, 50, 14, 21 };
	int k = 3;
	firstNegSlidingWindows(arr, 8, 3);
	return 0;
}

/*
 -2 -2 -6 -14 -14 NAN
 */

int josephus(int n, int k) {
    std::queue<int> que;    

    for(int i=0;i<n;i++)
        que.push(i+1);
    
    while(que.size() > 1) {
        for(int i=0;i<k-1;i++) {
            int top = que.front();
			que.pop();
			que.push(top);
        }
        que.pop();// Kth person executed.
    }
    return que.front();
}

// Testing code.
int main7(){
    std::cout << "Position : " << josephus(11, 5) << std::endl;
	return 0;
}

/*
Position : 8
*/

void rottenFruitUtil(std::vector<std::vector<int>> &arr, int maxCol, int maxRow,
		int currCol, int currRow, std::vector<std::vector<int>> &traversed, int day) {
    int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<4; i++){ 
        int x = currCol + dir[i][0];
        int y = currRow + dir[i][1];
        if(x >= 0 && x < maxCol && y >= 0 && y < maxRow && 
        traversed[x][y] > day+1 && arr[x][y] == 1){
            traversed[x][y] = day+1;
            rottenFruitUtil(arr, maxCol, maxRow, x, y, traversed, day+1);
        }
    }
}

int rottenFruit(std::vector<std::vector<int>> &arr, int maxCol, int maxRow) {
	std::vector<std::vector<int>> traversed(maxCol);
	for (int i = 0; i < maxCol; i++) {
		traversed[i] = std::vector<int>(maxRow,	std::numeric_limits<int>::max());
	}

	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			if (arr[i][j] == 2) {
				traversed[i][j] = 0;
				rottenFruitUtil(arr, maxCol, maxRow, i, j, traversed, 0);
			}
		}
	}

	int maxDay = 0;
	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			if (arr[i][j] == 1) {
				if (traversed[i][j] == std::numeric_limits<int>::max())
					return -1;
				if (maxDay < traversed[i][j])
					maxDay = traversed[i][j];
			}
		}
	}
	return maxDay;
}

int rottenFruit2(std::vector<std::vector<int>> &arr, int maxCol, int maxRow) {
	std::vector<std::vector<int>> traversed(maxCol);
	for (int i = 0; i < maxCol; i++) {
		traversed[i] = std::vector<int>(maxRow,	std::numeric_limits<int>::max());
	}    
	std::queue<int> que;

    for (int i = 0; i < maxCol; i++) {
        for (int j = 0; j < maxRow; j++) {
            traversed[i][j] = 0;
            if (arr[i][j] == 2) {    
                que.push(i);
                que.push(j);
                que.push(0);
                traversed[i][j] = 1;
            }
        }
    }
    
    int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxVal = 0, x, y, day;
    int tempX, tempY, tempDay;
    while(!que.empty()){
        tempX = que.front();	que.pop();
        tempY = que.front();	que.pop();
        tempDay = que.front();	que.pop();
        for(int i=0;i<4;i++){
            x = tempX + dir[i][0];
            y = tempY + dir[i][1];
            day = tempDay + 1;
            if(x >= 0 && x < maxCol && y >= 0 && y < maxRow && 
                arr[x][y] != 0 && traversed[x][y] == 0) {
                que.push(x);
                que.push(y);
                que.push(day);
                maxVal = std::max(maxVal, day);
                traversed[x][y] = 1;
            }
        }
    }
    for (int i = 0; i < maxCol; i++) {
        for (int j = 0; j < maxRow; j++) {
            if (arr[i][j] == 1 && traversed[i][j] == 0) {
                return -1;
            }
        }
    }
    return maxVal;
}

// Testing code.
int main8() {
	std::vector<std::vector<int>> arr = { { 1, 0, 1, 1, 0 }, { 2, 1, 0, 1, 0 },
			{ 0, 0, 0, 2, 1 }, { 0, 2, 0, 0, 1 }, { 1, 1, 0, 0, 1 } };
	std::cout << "rottenFruit :" << rottenFruit(arr, 5, 5) << std::endl;
	std::cout << "rottenFruit :" << rottenFruit2(arr, 5, 5) << std::endl;
	return 0;
}

/*
 rottenFruit :3
 */

void stepsOfKnightUtil(int size, int currCol, int currRow,
		std::vector<std::vector<int>> &traversed, int dist) {
    int dir[][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
                    {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    for(int i=0;i<8;i++){
        int x = currCol + dir[i][0];
        int y = currRow + dir[i][1];
        if(x >= 0 && x < size && y >= 0 && y < size 
					&& traversed[x][y] > dist+1) {
            traversed[x][y] = dist+1;
            stepsOfKnightUtil(size, x, y, traversed, dist + 1);
        }
    }
}

int stepsOfKnight(int size, int srcX, int srcY, int dstX, int dstY) {
	std::vector<std::vector<int>> traversed(size);
	for (int i = 0; i < size; i++) {
		traversed[i] = std::vector<int>(size, std::numeric_limits<int>::max());
	}
	traversed[srcX - 1][srcY - 1] = 0;
	stepsOfKnightUtil(size, srcX - 1, srcY - 1, traversed, 0);
	return traversed[dstX - 1][dstY - 1];
}

int stepsOfKnight2(int size, int srcX, int srcY, int dstX, int dstY) {
	std::vector<std::vector<int>> traversed(size);
	for (int i = 0; i < size; i++) {
		traversed[i] = std::vector<int>(size, std::numeric_limits<int>::max());
	}

    int dir[][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, 
                    {1, 2}};
    std::queue<int> que;
    traversed[srcX-1][srcY-1] = 0;
    que.push(srcX-1);
    que.push(srcY-1);
    que.push(0);
    
    int x, y, cost, tempX, tempY, tempCost;

    while(!que.empty()){
        tempX = que.front(); que.pop();
        tempY = que.front(); que.pop();
        tempCost = que.front(); que.pop();

        for(int i=0;i<8;i++){
            x = tempX + dir[i][0];
            y = tempY + dir[i][1];
            cost = tempCost + 1;

            if(x >= 0 && x < size && y >= 0 && y < size && 
                    traversed[x][y] > cost){
                traversed[x][y] = cost;
                que.push(x);
                que.push(y);
                que.push(cost);
            }
        }
    }
    int retval = traversed[dstX-1][dstY-1]; 
    return retval;
}

// Testing code.
int main9() {
	std::cout << "stepsOfKnight :: " << stepsOfKnight(20, 10, 10, 20, 20)
			<< std::endl;
	std::cout << "stepsOfKnight :: " << stepsOfKnight2(20, 10, 10, 20, 20)
			<< std::endl;
	return 0;
}

/*
 stepsOfKnight :: 8
 */


void distNearestFillUtil(std::vector<std::vector<int>> &arr, int maxCol,
		int maxRow, int currCol, int currRow, std::vector<std::vector<int>> &traversed, int dist) { 
    int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0;i<4;i++){
        int x = currCol + dir[i][0];
        int y = currRow + dir[i][1];
        if(x >= 0 && x < maxCol && y >= 0 && y < maxRow && 
        traversed[x][y] > dist+1){
            traversed[x][y] = dist+1;
            distNearestFillUtil(arr, maxCol, maxRow, x, y, traversed, dist+1);
        }
    }
}

void distNearestFill(std::vector<std::vector<int>> &arr, int maxCol,
		int maxRow) {
	std::vector<std::vector<int>> traversed(maxCol);
	for (int i = 0; i < maxCol; i++) {
		traversed[i] = std::vector<int>(maxRow, std::numeric_limits<int>::max());
	}

	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			if (arr[i][j] == 1){
				traversed[i][j] = 0;
				distNearestFillUtil(arr, maxCol, maxRow, i, j, traversed, 0);
			}
		}
	}

	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			std::cout << traversed[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void distNearestFill2(std::vector<std::vector<int>> &arr, int maxCol, int maxRow) {
	std::vector<std::vector<int>> traversed(maxCol);
	for (int i = 0; i < maxCol; i++) {
		traversed[i] = std::vector<int>(maxRow,
				std::numeric_limits<int>::max());
	}
	
	std::queue<int> que;
	for (int i = 0; i < maxCol; i++) {
        for (int j = 0; j < maxRow; j++) {
			if (arr[i][j] == 1) {    
				que.push(i);
				que.push(j);
				que.push(0);
				traversed[i][j] = 0;
			}
        }
    }
	
	int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int x, y, dist;
	int tempX, tempY, tempDist;
	while(!que.empty()){
		tempX = que.front(); que.pop();
		tempY = que.front(); que.pop();
		tempDist = que.front(); que.pop();

		for(int i=0;i<4;i++){
			x = tempX + dir[i][0];
			y = tempY + dir[i][1];
			dist = tempDist + 1;
			if(x >= 0 && x < maxCol && y >= 0 && y < maxRow && traversed[x][y] > dist) {
				que.push(x);
				que.push(y);
				que.push(dist);
				traversed[x][y] = dist;
			}
		}
	}
	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			std::cout << traversed[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Testing code.
int main10() {
	std::vector<std::vector<int>> arr = { { 1, 0, 1, 1, 0 }, { 1, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 1 } };

	distNearestFill(arr, 5, 5);
	distNearestFill2(arr, 5, 5);
	return 0;
}
/*
 0 1 0 0 1
 0 0 1 0 1
 1 1 2 1 0
 2 2 2 1 0
 3 3 2 1 0
 */

int main(){
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	main8();
	main9();
	main10();
	return 0;
}
