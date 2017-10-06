#pragma once

#include <string>
#include <vector>
#include <iostream>

class MyInt
{
public:
	int value = 0;
};

void printArray(int data[], int count);
void printVector(std::vector<int> &data, int count);

void swap(std::vector<int> &data, int x, int y);

void permutation(std::vector<int> &data, int i, int length);

int GCD(int m, int n);

void towerOfHanoi(int num, char src, char dst, char temp);

void function2();

void function1();

int maxSubArraySum(std::vector<int> &data);

void variableExample();

void arrayExample();

void printArray1(std::vector<int> &data, int count);

void twoDArrayExample();

int SumArray(std::vector<int> &data);

int SequentialSearch(std::vector<int> &data, int value);

int BinarySearch(std::vector<int> &data, int value);

void rotateArray(std::vector<int> &data, int k);

void reverseArray(std::vector<int> &data, int start, int end);

void reverseArray(std::vector<int> &data);

struct coord
{

	coord(int xval, int yval);
	int x = 0;
	int y = 0;
};

class student
{
private:
	int rollNo = 0;
	std::string firstName;
	std::string lastName;

public:
	student(std::string first, std::string last, int no);
	std::string getFirstName();
	std::string getLastName();
	int getRollNo();
};

// function returning the sum of two numbers
int sum(int num1, int num2);

int factorial(int i);

void printInt1(int number);

void printInt2(int number, int const base);

int fibonacci(int n);

// Binary Search Algorithm - Recursive
int BinarySearchRecursive(std::vector<int> &data, int low, int high, int value);
