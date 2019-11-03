#pragma once

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <ostream>
#include <math.h>

bool isBalancedParenthesis(const std::string &expn);
template<typename T>  void insertAtBottom(std::stack<T>& stk, T value);
template<typename T>  void reverseStack(std::stack<T>& stk);
int postfixEvaluate(const std::string &expn);
int precedence(char x);
std::string infixToPostfix(std::string &expn);
std::string infixToPrefix(std::string expn);
void replaceParanthesis(std::string &expn);
void reverseString(std::string &expn);
std::vector<int> StockSpanRange(std::vector<int> &arr);
std::vector<int> StockSpanRange2(std::vector<int> &arr);
int GetMaxArea(std::vector<int> &arr);
int GetMaxArea2(std::vector<int> &arr);