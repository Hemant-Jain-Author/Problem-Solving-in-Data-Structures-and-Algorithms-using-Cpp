#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <exception>
#include <set>
#include <map>

// buggy implementation.
//static int findkth(std::vector<int> &first, std::vector<int> &second, int k);
bool linearSearchUnsorted(std::vector<int> &data, int value);
bool linearSearchSorted(std::vector<int> &data, int value);
// Binary Search Algorithm - Iterative Way
bool binarysearch(std::vector<int> &data, int value);
// Binary Search Algorithm - Recursive Way
bool binarysearchRecursive(std::vector<int> &data, int low, int high, int value);
void printRepeating(std::vector<int> &data);
void printRepeating2(std::vector<int> &data);
void printRepeating3(std::vector<int> &data);
void printRepeating4(std::vector<int> &data);
int getMax(std::vector<int> &data);
int getMax2(std::vector<int> &data);
int getMax3(std::vector<int> &data, int range);
int getMajority(std::vector<int> &data);
int getMajority2(std::vector<int> &data);
int getMajority3(std::vector<int> &data);
int findMissingNumber(std::vector<int> &data);
int findMissingNumber2(std::vector<int> &data, int range);
int findMissingNumber3(std::vector<int> &data, int range);
bool findPair(std::vector<int> &data, int value);
bool findPair2(std::vector<int> &data, int value);
bool findPair3(std::vector<int> &data, int value);
void minabsSumPair(std::vector<int> &data);
void minabsSumPair2(std::vector<int> &data);
int searchBitonicArrayMax(std::vector<int> &data);
int searchBitonicArray(std::vector<int> &data, int key);
int findMaxBitonicArray(std::vector<int> &data);
int binarysearch(std::vector<int> &data, int start, int end, int key, bool isInc);
int findKeyCount(std::vector<int> &data, int key);
int findKeyCount2(std::vector<int> &data, int key);
int findFirstIndex(std::vector<int> &data, int start, int end, int key);
int findLastIndex(std::vector<int> &data, int start, int end, int key);
void swap(std::vector<int> &data, int first, int second);
void seperateEvenAndOdd(std::vector<int> &data);
int maxProfit(std::vector<int> &stocks);
int getMedian(std::vector<int> &data);
int findMedian(std::vector<int> &dataFirst, int sizeFirst, std::vector<int> &dataSecond, int sizeSecond);
static int min(int a, int b);
static int max(int a, int b);
int binarysearch01(std::vector<int> &data);
int binarysearch01Util(std::vector<int> &data, int start, int end);
int binarysearchRotateArrayUtil(std::vector<int> &data, int start, int end, int key);
int binarysearchRotateArray(std::vector<int> &data, int key);
int firstRepeated(std::vector<int> &data);
void transformArrayAB1(std::vector<int> &data);
bool checkPermutation(std::vector<int> &data1, std::vector<int> &data2);
bool checkPermutation2(std::vector<int> &data1, std::vector<int> &data2);
void removeDuplicates(std::vector<int> &data);
bool findElementIn2DArray(int** data, int r, int c, int value);