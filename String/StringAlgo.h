#pragma once

#include <string>
#include <vector>
#include <iostream>

bool matchExpUtil(const std::string exp, const std::string str, int i, int j);

bool matchExp(const std::string exp, const std::string str);

int match(const std::string &source, const std::string &pattern);

bool isPrime(const int n);

int myAtoi(const std::string &str);

bool isUniqueChar(const std::string &str);

char ToUpper( const char s);

char ToLower(const char s);

char LowerUpper(const char s);

bool isPermutation(const std::string &s1, const std::string &s2);

bool isPalindrome(const std::string &str);

int pow(const int x, const int n);

int myStrcmp(const std::string &a, const std::string &b);

void reverseString(std::string &a);

void reverseString(std::string &a, int lower, int upper);

void reverseWords(std::string &a);

void printAnagram(const std::string  &a);

void printAnagram(std::string  &a, int max, int n);

void shuffle(std::string  &ar);

std::string addBinary(const std::string &first, const std::string &second);