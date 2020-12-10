// Design.cpp : Defines the entry point for the console application.
//

#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci2(int n)
{
    int first = 0, second = 1;
    int temp = 0, i;

    if (n == 0)
        return first;
    else if (n == 1)
        return second;

    for (i = 2; i <= n; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }
    return temp;
}

int main()
{
    std::cout << "fibonacci(6) is :: " << fibonacci(6) << std::endl;
    std::cout << "fibonacci(6) is :: " << fibonacci2(6) << std::endl;
    return 0;
}

/*
fibonacci(6) is :: 8
fibonacci(6) is :: 8
*/
