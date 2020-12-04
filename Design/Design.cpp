// Design.cpp : Defines the entry point for the console application.
//

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibo(int n)
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
    return 0;
}

