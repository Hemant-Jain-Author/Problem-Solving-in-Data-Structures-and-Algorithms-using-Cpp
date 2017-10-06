#include "stdafx.h"
#include "NQueen.h"

int main()
{
	std::vector<int> Q(8);
	//NQueens(Q,0,8);
	TowersOfHanoi(3);
	return 0;
}

void print(std::vector<int> &Q, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << " " << Q[i];
	}
	std::cout << " " << std::endl;
}

bool Feasible(std::vector<int> &Q, int k)
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

void NQueens(std::vector<int> &Q, int k, int n)
{
	if (k == n)
	{
		print(Q, n);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		Q[k] = i;
		if (Feasible(Q, k))
		{
			NQueens(Q, k + 1, n);
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