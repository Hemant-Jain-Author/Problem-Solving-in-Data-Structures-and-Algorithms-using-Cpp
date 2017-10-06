#include "stdafx.h"
#include <string>
#include <vector>

#include "Introduction.h"


#include <iostream>

int main87878(int argc, char* argv[])
{
	//Single Line comment.

	/*
	Multiple line comments.
	*/

	std::cout << "Hello, world!" << std::endl;
	return 0;
}

void incrementPassByValue(int var)
{
	var++;
}

void incrementPassByReference(int& var)
{
	var++;
}

void incrementPassByPointer(int* ptr)
{
	(*ptr)++;
}

int main999()
{
	int i = 10;
	std::cout << "Value of i before increment is :  " << i << std::endl;
	incrementPassByPointer(&i);
	std::cout << "Value of i after increment is :  " << i << std::endl;
	return 0;
}

void printArray(int data[], int count)
{
	std::cout << "Values stored are : ";
	for (int i = 0; i < count; i++)
	{
		std::cout << " " << data[i];
	}
}

void arrayExample()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	printArray(arr, 10);
}


void vectorExample()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	printVector(vec);
}

void vectorExample()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	int count = vec.size();
	std::cout << "Values stored are : ";
	for (int i = 0; i < count; i++)
	{
		std::cout << " " << vec[i];
	}
}




void printVector(std::vector<int> &data)
{
	int count = data.size();
	std::cout << "Values stored are : ";
	for (int i = 0; i < count; i++)
	{
		std::cout << " " << data[i];
	}
}


void swap(std::vector<int> &data, int x, int y)
{
	int temp = data[x];
	data[x] = data[y];
	data[y] = temp;
	return;
}

void permutation(std::vector<int> &data, int i, int length)
{
	if (length == i)
	{
		printVector(data, length);
		return;
	}
	int j = i;
	for (j = i; j < length; j++)
	{
		swap(data, i, j);
		permutation(data, i + 1, length);
		swap(data, i, j);
	}
	return;
}

void main12()
{
	std::vector<int> data(5);
	for (int i = 0; i < 5; i++)
	{
		data[i] = i;
	}
	permutation(data, 0, 5);
}

void main13()
{
	std::vector<int> data(5);
	for (int i = 0; i < 5; i++)
	{
		data[i] = i;
	}
	permutation(data, 0, 5);
}

int GCD(int m, int n)
{
	if (m < n)
	{
		return (GCD(n, m));
	}
	if (m % n == 0)
	{
		return (n);
	}
	return (GCD(n, m % n));
}

void towerOfHanoi(int num, char src, char dst, char temp)
{
	if (num < 1)
	{
		return;
	}

	towerOfHanoi(num - 1, src, temp, dst);
	std::cout << "Move " << num << " disk  from peg " << src << " to peg " << dst << std::endl;
	towerOfHanoi(num - 1, temp, dst, src);
}

int main10()
{
	int num = 4;
	std::cout << "The sequence of moves involved in the Tower of Hanoi are :" << std::endl;
	towerOfHanoi(num, 'A', 'C', 'B');
	return 0;
}

void function2()
{
	std::cout << "fun2 line 1" << std::endl;
}

void function1()
{
	std::cout << "fun1 line 1" << std::endl;
	function2();
	std::cout << "fun1 line 2" << std::endl;
}

void main7()
{
	std::cout << "main line 1" << std::endl;
	function1();
	std::cout << "main line 2" << std::endl;
}

int maxSubArraySum(std::vector<int> &data)
{
	int size = data.size();
	int maxSoFar = 0, maxEndingHere = 0;

	for (int i = 0; i < size; i++)
	{
		maxEndingHere = maxEndingHere + data[i];
		if (maxEndingHere < 0)
			maxEndingHere = 0;
		if (maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	}
	return maxSoFar;
}

int main666() {
	std::vector<int> data = { 1,-2,3,4,-4,6,-14,8,2 };
	std::cout << "Max sub array sum :" << maxSubArraySum(data);
	return 0;
}


void variableExample()
{
	int var1, var2, var3;
	var1 = 100;
	var2 = 200;
	var3 = var1 + var2;
	std::cout << "Adding " << var1 << " and " << var2 << " will give " << var3 << std::endl;
}

void vectorExample()
{
	std::vector<int> data(10);
	for (int i = 0; i < 10; i++)
	{
		data[i] = i;
	}
	printArray1(data, 10);
}

void printArray1(std::vector<int> &data, int count)
{
	std::cout << "Values stored are : " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << " " << data[i] << std::endl;
	}
}

void twoDArrayExample()
{
	int  data[4][2];
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] = count++;
		}
	}
	//print2DArray(data);
}

template<typename T, int R, int C>
void print2DArray(T(&data)[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			std::cout << " " << data[i][j] << std::endl;
		}
	}
}

int SumArray(std::vector<int> &data)
{
	int size = data.size();
	int total = 0;
	int index = 0;
	for (index = 0; index < size; index++)
	{
		total = total + data[index];
	}
	return total;
}
int main8888()
{
	std::vector<int> data = { 1,2,3,4,5,6,7,8,9 };
	std::cout << "sum of all the values in array:" << SumArray(data) << std::endl;
	return 0;
}

int SequentialSearch(std::vector<int> &data, int value)
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		if (value == data[i])
			return i;
	}
	return -1;
}

int BinarySearch(std::vector<int> &data, int value)
{
	int size = data.size();
	int mid;
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2; // To avoid the overflow
		if (data[mid] == value)
		{
			return mid;
		}
		else
		{
			if (data[mid] < value)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return -1;
}

void rotateArray(std::vector<int> &data, int k)
{
	int n = data.size();
	reverseArray(data, 0, k - 1);
	reverseArray(data, k, n - 1);
	reverseArray(data, 0, n - 1);
}

void reverseArray(std::vector<int> &data, int start, int end)
{
	for (int i = start, j = end; i < j; i++, j--)
	{
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

void reverseArray(std::vector<int> &data)
{
	int start = 0;
	int end = data.size() - 1;
	for (int i = start, j = end; i < j; i++, j--)
	{
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

coord::coord(int xval, int yval)
{
	x = xval;
	y = yval;
}

int main2()
{
	coord *point = new coord(10, 10);
	std::cout << "X axis coord value is  " << point->x << std::endl;
	std::cout << "Y axis coord value is  " << point->y << std::endl;
	return 0;
}

student::student(std::string first, std::string last, int no)
{
	firstName = first;
	lastName = last;
	rollNo = no;
}

std::string student::getFirstName()
{
	return firstName;
}

std::string student::getLastName()
{
	return lastName;
}

int student::getRollNo()
{
	return rollNo;
}

int main3()
{
	student *stud = new student("hemant", "jain", 1);
	student *ptrStud;
	ptrStud = stud;
	std::cout << "Roll No:   Student Name:  " << ptrStud->getFirstName() << ptrStud->getLastName() << ptrStud->getRollNo() << std::endl;

	student stud2("raj", "kashyap", 2);
	student &refStud = stud2;
	std::cout << "Roll No:   Student Name:  " << refStud.getFirstName() << refStud.getLastName() << refStud.getRollNo() << std::endl;

	return 0;
}

int main4()
{
	// local variable definition
	int x = 10;
	int y = 20;
	int result;
	// calling a function to find sum
	result = sum(x, y);
	std::cout << "Sum is : " << result << std::endl;
	return 0;
}

int sum(int num1, int num2)
{
	// local variable declaration
	int result;
	result = num1 + num2;
	return result;
}

int factorial(int i)
{
	// Termination Condition
	if (i <= 1)
	{
		return 1;
	}
	// Body, Recursive Expansion
	return i * factorial(i - 1);
}

void printInt1(int number)
{
	char digit = static_cast<char>(number % 10 + '0');
	number = number / 10;
	if (number != 0)
	{
		printInt1(number);
	}
	std::cout << digit;
}

void printInt2(int number, int const base)
{
	std::string conversion = "0123456789ABCDEF";
	char digit = static_cast<char>(number % base);
	number = number / base;
	if (number != 0)
	{
		printInt2(number, base);
	}
	std::cout << " " << conversion[digit];
}

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int BinarySearchRecursive(std::vector<int> &data, int low, int high, int value)
{
	int mid = low + (high - low) / 2; // To avoid the overflow
	if (data[mid] == value)
	{
		return mid;
	}
	else if (data[mid] < value)
	{
		return BinarySearchRecursive(data, mid + 1, high, value);
	}
	else
	{
		return BinarySearchRecursive(data, low, mid - 1, value);
	}
}