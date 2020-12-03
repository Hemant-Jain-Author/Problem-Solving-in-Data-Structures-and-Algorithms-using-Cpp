#include <string>
#include <vector>
#include <iostream>
#include <cmath>

void print(std::vector<int> &Q, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << " " << Q[i];
	}
	std::cout << " " << std::endl;
}

bool feasible(std::vector<int> &Q, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (Q[k] == Q[i] || std::abs(Q[i] - Q[k]) == std::abs(i - k))
		{
			return false;
		}
	}
	return true;
}

void nQueens(std::vector<int> &Q, int k, int n)
{
	if (k == n)
	{
		print(Q, n);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		Q[k] = i;
		if (feasible(Q, k))
		{
			nQueens(Q, k + 1, n);
		}
	}
}

void TOHUtil(int num, char from, char to, char temp)
{
	if (num < 1)
		return;

	TOHUtil(num - 1, from, temp, to);
	std::cout << "Move disk " << num << " from peg " << from << " to peg " << to << std::endl;
	TOHUtil(num - 1, temp, to, from);
}

void TowersOfHanoi(int num)
{
	std::cout << "The sequence of moves involved in the Tower of Hanoi are :" << std::endl;
	TOHUtil(num, 'A', 'C', 'B');
}

int isPrime(int n) {
    int answer = (n > 1) ? 1 : 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            answer = 1;
            break;
        }
    }
    return answer;
}

int main()
{
	std::vector<int> Q(8);
	nQueens(Q,0,8);
	TowersOfHanoi(3);
	return 0;
}

/*
 0 4 7 5 2 6 1 3 
 0 5 7 2 6 3 1 4 
 0 6 3 5 7 1 4 2 
 0 6 4 7 1 3 5 2 
 1 3 5 7 2 0 6 4 
 1 4 6 0 2 7 5 3 
 1 4 6 3 0 7 5 2 
 1 5 0 6 3 7 2 4 
 1 5 7 2 0 3 6 4 
 1 6 2 5 7 4 0 3 
 1 6 4 7 0 3 5 2 
 1 7 5 0 2 4 6 3 
 2 0 6 4 7 1 3 5 
 2 4 1 7 0 6 3 5 
 2 4 1 7 5 3 6 0 
 2 4 6 0 3 1 7 5 
 2 4 7 3 0 6 1 5 
 2 5 1 4 7 0 6 3 
 2 5 1 6 0 3 7 4 
 2 5 1 6 4 0 7 3 
 2 5 3 0 7 4 6 1 
 2 5 3 1 7 4 6 0 
 2 5 7 0 3 6 4 1 
 2 5 7 0 4 6 1 3 
 2 5 7 1 3 0 6 4 
 2 6 1 7 4 0 3 5 
 2 6 1 7 5 3 0 4 
 2 7 3 6 0 5 1 4 
 3 0 4 7 1 6 2 5 
 3 0 4 7 5 2 6 1 
 3 1 4 7 5 0 2 6 
 3 1 6 2 5 7 0 4 
 3 1 6 2 5 7 4 0 
 3 1 6 4 0 7 5 2 
 3 1 7 4 6 0 2 5 
 3 1 7 5 0 2 4 6 
 3 5 0 4 1 7 2 6 
 3 5 7 1 6 0 2 4 
 3 5 7 2 0 6 4 1 
 3 6 0 7 4 1 5 2 
 3 6 2 7 1 4 0 5 
 3 6 4 1 5 0 2 7 
 3 6 4 2 0 5 7 1 
 3 7 0 2 5 1 6 4 
 3 7 0 4 6 1 5 2 
 3 7 4 2 0 6 1 5 
 4 0 3 5 7 1 6 2 
 4 0 7 3 1 6 2 5 
 4 0 7 5 2 6 1 3 
 4 1 3 5 7 2 0 6 
 4 1 3 6 2 7 5 0 
 4 1 5 0 6 3 7 2 
 4 1 7 0 3 6 2 5 
 4 2 0 5 7 1 3 6 
 4 2 0 6 1 7 5 3 
 4 2 7 3 6 0 5 1 
 4 6 0 2 7 5 3 1 
 4 6 0 3 1 7 5 2 
 4 6 1 3 7 0 2 5 
 4 6 1 5 2 0 3 7 
 4 6 1 5 2 0 7 3 
 4 6 3 0 2 7 5 1 
 4 7 3 0 2 5 1 6 
 4 7 3 0 6 1 5 2 
 5 0 4 1 7 2 6 3 
 5 1 6 0 2 4 7 3 
 5 1 6 0 3 7 4 2 
 5 2 0 6 4 7 1 3 
 5 2 0 7 3 1 6 4 
 5 2 0 7 4 1 3 6 
 5 2 4 6 0 3 1 7 
 5 2 4 7 0 3 1 6 
 5 2 6 1 3 7 0 4 
 5 2 6 1 7 4 0 3 
 5 2 6 3 0 7 1 4 
 5 3 0 4 7 1 6 2 
 5 3 1 7 4 6 0 2 
 5 3 6 0 2 4 1 7 
 5 3 6 0 7 1 4 2 
 5 7 1 3 0 6 4 2 
 6 0 2 7 5 3 1 4 
 6 1 3 0 7 4 2 5 
 6 1 5 2 0 3 7 4 
 6 2 0 5 7 4 1 3 
 6 2 7 1 4 0 5 3 
 6 3 1 4 7 0 2 5 
 6 3 1 7 5 0 2 4 
 6 4 2 0 5 7 1 3 
 7 1 3 0 6 4 2 5 
 7 1 4 2 0 6 3 5 
 7 2 0 5 1 4 6 3 
 7 3 0 2 5 1 6 4 
The sequence of moves involved in the Tower of Hanoi are :
Move disk 1 from peg A to peg C
Move disk 2 from peg A to peg B
Move disk 1 from peg C to peg B
Move disk 3 from peg A to peg C
Move disk 1 from peg B to peg A
Move disk 2 from peg B to peg C
Move disk 1 from peg A to peg C
*/