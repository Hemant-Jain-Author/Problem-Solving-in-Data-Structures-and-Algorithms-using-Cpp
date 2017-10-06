#include "stdafx.h"
#include "StackExercise.h"
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>

bool isBalancedParenthesis(const std::string &expn)
{
	std::stack<char> stk;
	char val;
	for (auto ch : expn)
	{
		switch (ch)
		{
		case '{':
		case '[':
		case '(':
			stk.push(ch);
			break;
		case '}':
			val = stk.top();
			stk.pop();
			if (val != '{')
			{
				return false;
			}
			break;
		case ']':
			val = stk.top();
			stk.pop();
			if (val != '[')
			{
				return false;
			}
			break;
		case ')':
			val = stk.top();
			stk.pop();
			if (val != '(')
			{
				return false;
			}
			break;
		}
	}
	return stk.empty();
}

int main1()
{
	std::string expn = "{()}[]";
	bool value = isBalancedParenthesis(expn);
	std::cout << "Given Expn:" << expn << std::endl;
	std::cout << "Result aft1er isParenthesisMatched:" << value << std::endl;
	return 0;
}

template<typename T>
void insertAtBottom(stack<T>& stk, T value)
{
	if (stk.empty())
	{
		stk.push(value);
	}
	else
	{
		T out = stk.pop();
		insertAtBottom(stk, value);
		stk.push(out);
	}
}

template<typename T>
void reverseStack(stack<T>& stk)
{
	if (stk.empty())
	{
		return;
	}
	else
	{
		T value = stk.pop();
		reverseStack(stk);
		insertAtBottom(stk, value);
	}
}

int postfixEvaluate(const std::string &expn)
{
	std::stack<int> stk;	
	int digit = 0;
	int value = 0;

	for (auto ch : expn)
	{
		if (isdigit(ch))
		{
			digit = 1;
			value = value * 10 + (ch - '0');
		}
		else if (ch == ' ')
		{
			if (digit == 1)
			{
				stk.push(value); /* Push the operand */
				digit = 0;
				value = 0;
			}
		}
		else
		{
			int num1 = stk.top(); 
			stk.pop();
			int num2 = stk.top(); 
			stk.pop();
			
			switch (ch)
			{
			case '+':
				stk.push(num1 + num2);
				break;
			case '-':
				stk.push(num1 - num2);
				break;
			case '*':
				stk.push(num1 * num2);
				break;
			case '/':
				stk.push(num1 / num2);
				break;
			}
		}
	}
	int val = stk.top(); stk.pop();
	return val;
}

int main2()
{
	std::string expn = "6 5 2 3 + 8 * + 3 + *";
	int value = postfixEvaluate(expn);
	std::cout << "Given Postfix Expn: " << expn << std::endl;
	std::cout << "Result after Evaluation: " << value << std::endl;
	return 0;
}

int precedence(char x)
{
	if (x == '(')
	{
		return (0);
	}
	if (x == '+' || x == '-')
	{
		return (1);
	}
	if (x == '*' || x == '/' || x == '%')
	{
		return (2);
	}
	if (x == '^')
	{
		return (3);
	}
	return (4);
}



std::string infixToPostfix(std::string &expn)
{
	std::stack<char> stk;
	std::string output = "";
	char out;

	for (auto ch : expn)
	{
		if (ch <= '9' && ch >= '0')
		{
			output = output + ch;
		}
		else
		{
			switch (ch)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while (stk.empty() == false && precedence(ch) <= precedence(stk.top()))
				{
					out = stk.top(); stk.pop();
					output = output + " " + out;
				}
				stk.push(ch);
				output = output + " ";
				break;
			case '(':
				stk.push(ch);
				break;
			case ')':
				while (stk.empty() == false && (out = stk.top()) != '(')
				{
					stk.pop();
					output = output + " " + out + " ";
				}
				if(stk.empty() == false && (out = stk.top()) == '(')
					stk.pop();
				break;
			}
		}
	}

	while (stk.empty() == false)
	{
		out = stk.top(); stk.pop();
		output = output + out + " ";
	}
	return output;
}

int main3()
{
	std::string expn = "10+((3))*5/(16-4)";
	std::string value = infixToPostfix(expn);
	std::cout << "Infix Expn: " << expn << std::endl;
	std::cout << "Postfix Expn: " << value << std::endl;
	return 0;
}

std::string infixToPrefix( std::string expn)
{
	reverseString(expn);
	replaceParanthesis(expn);
	expn = infixToPostfix(expn);
	reverseString(expn);
	return expn;
}

void replaceParanthesis(std::string &a)
{
	int lower = 0;
	int upper = a.size() - 1;
	while (lower <= upper)
	{
		if (a[lower] == '(')
		{
			a[lower] = ')';
		}
		else if (a[lower] == ')')
		{
			a[lower] = '(';
		}
		lower++;
	}
}

void reverseString(std::string &expn)
{
	int lower = 0;
	int upper = expn.size() - 1;
	char tempChar;
	while (lower < upper)
	{
		tempChar = expn[lower];
		expn[lower] = expn[upper];
		expn[upper] = tempChar;
		lower++;
		upper--;
	}
}

int main()
{
	std::string expn = "10+((3))*5/(16-4)";
	std::string value = infixToPrefix(expn);
	std::cout << "Infix Expn: " << expn << std::endl;
	std::cout << "Prefix Expn: " << value << std::endl;
	return 0;
}

std::vector<int> StockSpanRange(std::vector<int> &arr)
{
	std::vector<int> SR(arr.size());
	SR[0] = 1;
	for (int i = 1; i < arr.size(); i++)
	{
		SR[i] = 1;
		for (int j = i - 1; (j >= 0) && (arr[i] >= arr[j]); j--)
		{
			SR[i]++;
		}
	}
	return SR;
}

std::vector<int> StockSpanRange2(std::vector<int> &arr)
{
	std::stack<int> stk;

	std::vector<int> SR(arr.size());
	stk.push(0);
	SR[0] = 1;
	for (int i = 1; i < arr.size(); i++)
	{
		while (!stk.empty() && arr[stk.top()] <= arr[i])
		{
			stk.pop();
		}
		SR[i] = (stk.empty()) ? (i + 1) : (i - stk.top());
		stk.push(i);
	}
	return SR;
}

int GetMaxArea(std::vector<int> &arr)
{
	int size = arr.size();
	int maxArea = -1;
	int currArea;
	int minHeight = 0;
	for (int i = 1; i < size; i++)
	{
		minHeight = arr[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (minHeight > arr[j])
			{
				minHeight = arr[j];
			}
			currArea = minHeight * (i - j + 1);
			if (maxArea < currArea)
			{
				maxArea = currArea;
			}
		}
	}
	return maxArea;
}

int GetMaxArea2(std::vector<int> &arr)
{
	int size = arr.size();
	std::stack<int> stk;
	int maxArea = 0;
	int top;
	int topArea;
	int i = 0;
	while (i < size)
	{
		while ((i < size) && (stk.empty() || arr[stk.top()] <= arr[i]))
		{
			stk.push(i);
			i++;
		}
		while (!stk.empty() && (i == size || arr[stk.top()] > arr[i]))
		{
			top = stk.top();
			stk.pop();
			topArea = arr[top] * (stk.empty() ? i : i - stk.top() - 1);
			if (maxArea < topArea)
			{
				maxArea = topArea;
			}
		}
	}
	return maxArea;
}