#include <string>
#include <vector>
#include <iostream>
#include <cmath>

void print(std::vector<int> &Q, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << Q[i] << " ";
    std::cout << std::endl;
}

bool feasible(std::vector<int> &Q, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (Q[k] == Q[i] || std::abs(Q[i] - Q[k]) == std::abs(i - k))
            return false;
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
            nQueens(Q, k + 1, n);
    }
}

int main1()
{
    std::vector<int> Q(8);
    nQueens(Q,0,8);
    return 0;
}

/*
0 4 7 5 2 6 1 3
0 5 7 2 6 3 1 4
.......
.......
7 2 0 5 1 4 6 3
7 3 0 2 5 1 6 4
*/

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

int main2()
{
    TowersOfHanoi(3);
    return 0;
}

/*
The sequence of moves involved in the Tower of Hanoi are :
Move disk 1 from peg A to peg C
Move disk 2 from peg A to peg B
Move disk 1 from peg C to peg B
Move disk 3 from peg A to peg C
Move disk 1 from peg B to peg A
Move disk 2 from peg B to peg C
Move disk 1 from peg A to peg C
*/

int fibonacci(int n)
{
    if (n == 1)
        return 0;
    else if(n == 2)
        return 1; 

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci2(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;

    int first = 0, second = 1;
    int temp = 0;

    for (int i = 2; i < n; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }
    return temp;
}

int main3()
{
    std::cout << "fibonacci(6) is :: " << fibonacci(6) << std::endl;
    std::cout << "fibonacci(6) is :: " << fibonacci2(6) << std::endl;
    return 0;
}

/*
fibonacci(6) is :: 5
fibonacci(6) is :: 5
*/


int isPrime(int n)
{
    if( n < 1) 
        return false;
    
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main4()
{
    std::cout << "Prime numbers between 1 and 20 are :: ";
    for(int i = 0; i < 20; i++)
    {
        if(isPrime(i))
            std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*
Prime numbers between 1 and 20 are :: 1 2 3 5 7 11 13 17 19 
*/

int main()
{
    main1();
    main2();
    main3();
    main4();
    return 0;
}