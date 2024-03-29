#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>

template<class T>
void printStackUtil(std::stack<T> &stk) {
	T temp = stk.top();
	stk.pop();
	if (stk.size() > 0)
		printStackUtil(stk);
	std::cout << temp << " ";
	stk.push(temp);
}

template<class T>
void printStack(std::stack<T> &stk) {
	std::cout << "[ ";
	printStackUtil(stk);
	std::cout << "]" << std::endl;
}

// Testing code.
int mainA() {
	std::stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	printStack(stk);
    std::cout << "top : " << stk.top() << std::endl;
	std::cout << "size : " << stk.size() << std::endl;
	std::cout << "empty : " << stk.empty() << std::endl;
    stk.pop();
	printStack(stk);
	return 0;
}

/*
[ 1 2 3 ]
top : 3
size : 3
empty : 0
[ 1 2 ]
*/

template<class T>
void printQueue(std::queue<T> &que) {
	int size = que.size();
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		T temp = que.front();
		que.pop();
		std::cout << temp << " ";
		que.push(temp);
	}
	std::cout << "]" << std::endl;
}

void function2() {
	std::cout << "fun2 line 1" << std::endl;
}

void function1() {
	std::cout << "fun1 line 1" << std::endl;
	function2();
	std::cout << "fun1 line 2" << std::endl;
}

// Testing code.
int main1()
{
    std::cout << "main line 1" << std::endl;
    function1();
    std::cout << "main line 2" << std::endl;
    return 0;
}

/*
 main line 1
 fun1 line 1
 fun2 line 1
 fun1 line 2
 main line 2
 */

void sortedInsert(std::stack<int> &stk, int element)
{
    if (stk.empty() || element > stk.top())
        stk.push(element);
    else
    {
        int temp = stk.top();
        stk.pop();
        sortedInsert(stk, element);
        stk.push(temp);
    }
}

// Testing code.
int main2()
{
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(4);
    stk.push(5);
    printStack(stk);
    sortedInsert(stk, 3);
    printStack(stk);
    return 0;
}

/*
 [ 1 2 4 5 ]
 [ 1 2 3 4 5 ]
 */

void sortStack(std::stack<int> &stk)
{
    int temp;
    if (stk.empty() == false)
    {
        temp = stk.top();
        stk.pop();
        sortStack(stk);
        sortedInsert(stk, temp);
    }
}

void sortStack2(std::stack<int> &stk)
{
    int temp;
    std::stack<int> stk2;
    while (stk.empty() == false)
    {
        temp = stk.top();
        stk.pop();
        while ((stk2.empty() == false) && (stk2.top() < temp))
        {
            int temp2 = stk2.top();
            stk2.pop();
            stk.push(temp2);
        }
        stk2.push(temp);
    }
    while (stk2.empty() == false)
    {
        int temp2 = stk2.top();
        stk2.pop();
        stk.push(temp2);
    }
}

// Testing code.
int main3()
{
    std::stack<int> stk1;
    stk1.push(1);
    stk1.push(5);
    stk1.push(4);
    stk1.push(3);
    printStack(stk1);
    sortStack(stk1);
    printStack(stk1);

    std::stack<int> stk2;
    stk2.push(1);
    stk2.push(5);
    stk2.push(4);
    stk2.push(3);
    printStack(stk2);
    sortStack2(stk2);
    printStack(stk2);
    return 0;
}

/*
 [ 1 5 4 3 ]
 [ 1 3 4 5 ]

 [ 1 5 4 3 ]
 [ 1 3 4 5 ]
 */

void insertAtBottom(std::stack<int> &stk, int value)
{
    if (stk.empty())
        stk.push(value);
    else
    {
        int out = stk.top();
        stk.pop();
        insertAtBottom(stk, value);
        stk.push(out);
    }
}

// Testing code.
int main4() {
	std::stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	printStack(stk);
	insertAtBottom(stk, 4);
	printStack(stk);
	return 0;
}

/*
[ 1 2 3 ]
[ 4 1 2 3 ]
 */

void reverseStack(std::stack<int> &stk)
{
    if (stk.empty())
        return;

    int value = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk, value);
}

void reverseStack2(std::stack<int> &stk)
{
    std::queue<int> que;
    while (stk.empty() == false)
    {
        int temp = stk.top();
        stk.pop();
        que.push(temp);
    }

    while (que.empty() == false)
    {
        int temp = que.front();
        que.pop();
        stk.push(temp);
    }
}

// Testing code.
int main5()
{
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    printStack(stk);
    reverseStack(stk);
    printStack(stk);
    reverseStack2(stk);
    printStack(stk);
    return 0;
}
/*
 [ 1 2 3 4 ]
 [ 4 3 2 1 ]
 [ 1 2 3 4 ]
 */
void reverseKElementInStack(std::stack<int> &stk, int k)
{
    std::queue<int> que;
    int i = 0;
    while (stk.empty() == false && i < k)
    {
        int temp = stk.top();
        stk.pop();
        que.push(temp);
        i++;
    }
    while (que.empty() == false)
    {
        int temp = que.front();
        que.pop();
        stk.push(temp);
    }
}

// Testing code.
int main6()
{
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    printStack(stk);
    reverseKElementInStack(stk, 2);
    printStack(stk);
    return 0;
}
/*
 [ 1 2 3 4 ]
 [ 1 2 4 3 ]
 */
void reverseQueue(std::queue<int> &que)
{
    std::stack<int> stk;
    while (que.empty() == false)
    {
        int temp = que.front();
        que.pop();
        stk.push(temp);
    }

    while (stk.empty() == false)
    {
        int temp = stk.top();
        stk.pop();
        que.push(temp);
    }
}

// Testing code.
int main7()
{
    std::queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    printQueue(que);
    reverseQueue(que);
    printQueue(que);
    return 0;
}

/*
 [ 1 2 3 4 ]
 [ 4 3 2 1 ]
 */

void reverseKElementInQueue(std::queue<int> &que, int k)
{
    std::stack<int> stk;
    int i = 0, diff, temp;
    while (que.empty() == false && i < k)
    {
        int temp = que.front();
        que.pop();
        stk.push(temp);
        i++;
    }
    while (stk.empty() == false)
    {
        int temp = stk.top();
        stk.pop();
        que.push(temp);
    }
    diff = que.size() - k;
    while (diff > 0)
    {
        temp = que.front();
        que.pop();
        que.push(temp);
        diff -= 1;
    }
}

// Testing code.
int main8()
{
    std::queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    printQueue(que);
    reverseKElementInQueue(que, 2);
    printQueue(que);
    return 0;
}

/*
 [ 1 2 3 4 ]
 [ 2 1 3 4 ]
 */

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

// Testing code.
int main9()
{
    std::string expn = "{()}[]";
    bool value = isBalancedParenthesis(expn);
    std::cout << "Given Expn:" << expn << std::endl;
    std::cout << "Result aft1er isParenthesisMatched:" << value << std::endl;
    return 0;
}

/*
 Given Expn:{()}[]
 Result aft1er isParenthesisMatched:1
 */

int maxDepthParenthesis(const std::string &expn, int size)
{
    std::stack<char> stk;
    int maxDepth = 0;
    int depth = 0;
    char ch;

    for (int i = 0; i < size; i++)
    {
        ch = expn[i];

        if (ch == '(')
        {
            stk.push(ch);
            depth += 1;
        }
        else if (ch == ')')
        {
            stk.pop();
            depth -= 1;
        }
        if (depth > maxDepth)
            maxDepth = depth;
    }
    return maxDepth;
}

int maxDepthParenthesis2(const std::string &expn, int size)
{
    int maxDepth = 0;
    int depth = 0;
    char ch;
    for (int i = 0; i < size; i++)
    {
        ch = expn[i];
        if (ch == '(')
            depth += 1;
        else if (ch == ')')
            depth -= 1;

        if (depth > maxDepth)
            maxDepth = depth;
    }
    return maxDepth;
}

// Testing code.
int main10() {
	std::string expn = "((((A)))((((BBB()))))()()()())";
	int size = expn.size();
	int value = maxDepthParenthesis(expn, size);
	int value2 = maxDepthParenthesis2(expn, size);
	std::cout << "Max depth parenthesis is " << value << std::endl;
	std::cout << "Max depth parenthesis is " << value2 << std::endl;
	return 0;
}

/*
 Max depth parenthesis is 6
 Max depth parenthesis is 6
 */

int longestContBalParen(const std::string &expn, int size) {
	std::stack<int> stk;
	stk.push(-1);
	int length = 0;

	for (int i = 0; i < size; i++) {

		if (expn[i] == '(')
			stk.push(i);
		else { // expn[i] == ')'
			stk.pop();
			if (stk.size() != 0)
				length = std::max(length, i - stk.top());
			else
				stk.push(i);
		}
	}
	return length;
}

// Testing code.
int main11()
{
    std::string expn = "())((()))(())()(()";
    int size = expn.size();
    int value = longestContBalParen(expn, size);
    std::cout << "longestContBalParen " << value << std::endl;
    return 0;
}

/*
 longestContBalParen 12
 */

int reverseParenthesis(const std::string &expn, int size)
{
    std::stack<char> stk;
    int openCount = 0;
    int closeCount = 0;
    char ch;

    if (size % 2 == 1)
    {
        std::cout << "Invalid odd length " << size << std::endl;
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        ch = expn[i];
        if (ch == '(')
            stk.push(ch);
        else if (ch == ')')
            if (stk.size() != 0 && stk.top() == '(')
                stk.pop();
            else
                stk.push(')');
    }
    while (stk.size() != 0)
    {
        char temp = stk.top();
        stk.pop();
        if (temp == '(')
            openCount += 1;
        else
            closeCount += 1;
    }
    int reversal = (int)std::ceil(openCount / 2.0) + (int)std::ceil(closeCount / 2.0);
    return reversal;
}

// Testing code.
int main12() {
	std::string expn2 = ")(())(((";
	int size = expn2.size();
	int value = reverseParenthesis(expn2, size);
	std::cout << "reverse Parenthesis is : " << value << std::endl;
	return 0;
}

/*
 reverse Parenthesis is : 3
 */

bool findDuplicateParenthesis(const std::string &expn, int size)
{
    std::stack<char> stk;
    char ch;
    int count;

    for (int i = 0; i < size; i++)
    {
        ch = expn[i];
        if (ch == ')')
        {
            count = 0;
            while (stk.size() != 0 && stk.top() != '(')
            {
                stk.pop();
                count += 1;
            }
            if (count <= 1)
                return true;
        }
        else
            stk.push(ch);
    }
    return false;
}

// Testing code.
int main13() {
	// expn = "(((a+(b))+(c+d)))"
	// expn = "(b)"
	std::string expn = "(((a+b))+c)";
	int size = expn.size();
	bool value = findDuplicateParenthesis(expn, size);
	std::cout << "Duplicate Found : " << value << std::endl;
	return 0;
}

/*
 Duplicate Found : 1
 */

void printParenthesisNumber(const std::string &expn, int size)
{
    char ch;
    std::stack<int> stk;
    std::string output;
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        ch = expn[i];
        if (ch == '(')
        {
            stk.push(count);
            output += std::to_string(count);
            count += 1;
        }
        else if (ch == ')')
        {
            output += std::to_string(stk.top());
            stk.pop();
        }
    }
    std::cout << "Parenthesis Count ::";
    std::cout << output << std::endl;
}

// Testing code.
int main14()
{
    std::string expn1 = "(((a+(b))+(c+d)))";
    std::string expn2 = "(((a+b))+c)(((";
    int size = expn1.size();
    std::cout << "Given expn " << expn1 << std::endl;
    printParenthesisNumber(expn1, size);
    size = expn2.size();
    std::cout << "Given expn " + expn2 << std::endl;
    printParenthesisNumber(expn2, size);
    return 0;
}

/*
 Given expn (((a+(b))+(c+d)))
 Parenthesis Count ::1234435521
 Given expn (((a+b))+c)(((
 Parenthesis Count ::123321456
 */

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
                    out = stk.top();
                    stk.pop();
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
                if (stk.empty() == false && (out = stk.top()) == '(')
                    stk.pop();
                break;
            }
        }
    }

    while (stk.empty() == false)
    {
        out = stk.top();
        stk.pop();
        output = output + out + " ";
    }
    return output;
}

// Testing code.
int main15()
{
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPostfix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Postfix Expn: " << value << std::endl;
    return 0;
}

/*
 Infix Expn: 10+((3))*5/(16-4)
 Postfix Expn: 10 3 5 * 16 4 - / +
 */

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
std::string infixToPrefix(std::string expn)
{
    reverseString(expn);
    replaceParanthesis(expn);
    expn = infixToPostfix(expn);
    reverseString(expn);
    return expn;
}

// Testing code.
int main16()
{
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPrefix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Prefix Expn: " << value << std::endl;
    return 0;
}

/*
 Infix Expn: 10+((3))*5/(16-4)
 Prefix Expn:  +10 * 3 / 5  - 16 4
 */

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
    int val = stk.top();
    stk.pop();
    return val;
}

// Testing code.
int main17()
{
    std::string expn = "6 5 2 3 + 8 * + 3 + *";
    int value = postfixEvaluate(expn);
    std::cout << "Given Postfix Expn: " << expn << std::endl;
    std::cout << "Result after Evaluation: " << value << std::endl;
    return 0;
}

/*
 Given Postfix Expn: 6 5 2 3 + 8 * + 3 + *
 Result after Evaluation: 288
 */

std::vector<int> stockSpanRange(std::vector<int> &arr) {
	std::vector<int> SR(arr.size());
	SR[0] = 1;
	for (int i = 1; i < arr.size(); i++) {
		SR[i] = 1;
		for (int j = i - 1; (j >= 0) && (arr[i] >= arr[j]); j--) {
			SR[i]++;
		}
	}
	return SR;
}

std::vector<int> stockSpanRange2(std::vector<int> &arr) {
	std::stack<int> stk;
	std::vector<int> SR(arr.size());
	stk.push(0);
	SR[0] = 1;
	for (int i = 1; i < arr.size(); i++) {
		while (!stk.empty() && arr[stk.top()] <= arr[i]) {
			stk.pop();
		}
		SR[i] = (stk.empty()) ? (i + 1) : (i - stk.top());
		stk.push(i);
	}
	return SR;
}

// Testing code.
int main18()
{
    std::vector<int> arr = {6, 5, 4, 3, 2, 4, 5, 7, 9};
    int size = arr.size();
    std::vector<int> value = stockSpanRange(arr);
    std::cout << "StockSpanRange : ";
    for (int val : value)
        std::cout << " " << val;
    std::cout << std::endl;

    value = stockSpanRange2(arr);
    std::cout << "StockSpanRange : ";
    for (int val : value)
        std::cout << " " << val;
    std::cout << std::endl;
    return 0;
}

/*
 StockSpanRange :  1 1 1 1 1 4 6 8 9
 StockSpanRange :  1 1 1 1 1 4 6 8 9
 */

int getMaxArea(std::vector<int> &arr)
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

int getMaxArea2(std::vector<int> &arr)
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

// Testing code.
int main19()
{
    std::vector<int> arr = {7, 6, 5, 4, 4, 1, 6, 3, 1};
    int value = getMaxArea(arr);
    std::cout << "getMaxArea :: " << value << std::endl;
    value = getMaxArea2(arr);
    std::cout << "getMaxArea :: " << value << std::endl;
    return 0;
}

/*
 getMaxArea :: 20
 getMaxArea :: 20
 */

void nextLargerElement(std::vector<int> &arr)
{
    int size = arr.size();
    std::vector<int> output(size);
    int outIndex = 0;
    int next;

    for (int i = 0; i < size; i++)
    {
        next = -1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        output[outIndex++] = next;
    }
    for (int val : output)
        std::cout << val << " ";
}

void nextLargerElement2(std::vector<int> &arr)
{
    std::stack<int> stk;
    int size = arr.size();
    // output = [-1] * size;
    std::vector<int> output(size);
    int index = 0;
    int curr;

    for (int i = 0; i < size; i++)
    {
        curr = arr[i];
        // stack always have values in decreasing order.
        while (stk.empty() == false && arr[stk.top()] <= curr)
        {
            index = stk.top();
            stk.pop();
            output[index] = curr;
        }
        stk.push(i);
    }
    // index which dont have any next Larger.
    while (stk.empty() == false)
    {
        index = stk.top();
        stk.pop();
        output[index] = -1;
    }
    for (int val : output)
        std::cout << val << " ";
}

// Testing code.
int main20()
{
    std::vector<int> arr = {13, 21, 3, 6, 20, 3};
    nextLargerElement(arr);
    std::cout << std::endl;
    nextLargerElement2(arr);
    std::cout << std::endl;
    return 0;
}

/*
 21 -1 6 20 -1 -1
 21 -1 6 20 -1 -1
 */

void nextSmallerElement(std::vector<int> &arr) {
    int size = arr.size();
	std::vector<int> output(size);
	for (int i = 0; i < size; i++) {
        output[i] = -1;
        for(int j = i+1;j<size;j++){
            if(arr[j] < arr[i]){
                output[i] = arr[j];
                break;
            }
        }
    }
    for (int val : output)
		std::cout << val << " ";
}

void nextSmallerElement2(std::vector<int> &arr) {
	std::stack<int> stk;
	int size = arr.size();
	std::vector<int> output(size);
	int curr, index;
	for (int i = 0; i < size; i++) {
		curr = arr[i];
		// stack always have values in increasing order.
		while (stk.empty() == false && arr[stk.top()] > curr) {
			index = stk.top();
			stk.pop();
			output[index] = curr;
		}
		stk.push(i);
	}
	// index which dont have any next Smaller.
	while (stk.empty() == false) {
		index = stk.top();
		stk.pop();
		output[index] = -1;
	}
	for (int val : output)
		std::cout << val << " ";
}

// Testing code.
int main21() {
	std::vector<int> arr = { 13, 21, 3, 6, 20, 3 };
	nextSmallerElement(arr);
	std::cout << std::endl;
	nextSmallerElement2(arr);
	std::cout << std::endl;
	return 0;
}

/*
3 3 -1 3 3 -1 
3 3 -1 3 3 -1 
 */

void nextLargerElementCircular(std::vector<int> &arr)
{
    std::stack<int> stk;
    int curr, index;
    int size = arr.size();
    std::vector<int> output(size);
    for (int i = 0; i < (2 * size - 1); i++)
    {
        curr = arr[i % size];
        // stack always have values in decreasing order.
        while (stk.empty() == false && arr[stk.top()] <= curr)
        {
            index = stk.top();
            stk.pop();
            output[index] = curr;
        }
        stk.push(i % size);
    }
    // index which dont have any next Larger.
    while (stk.empty() == false)
    {
        index = stk.top();
        stk.pop();
        output[index] = -1;
    }
    for (int val : output)
        std::cout << val << " ";
}

// Testing code.
int main22()
{
    std::vector<int> arr = {6, 3, 9, 8, 10, 2, 1, 15, 7};
    nextLargerElementCircular(arr);
    std::cout << std::endl;
    return 0;
}

/*
 9 9 10 10 15 15 15 -1 9
 */

bool isKnown(std::vector<std::vector<int>> &relation, int a, int b) {
	if (relation[a][b] == 1)
		return true;
	return false;
}


int findCelebrity(std::vector<std::vector<int>> &relation, int count) {
    for (int i = 0; i < count; i++) {
        int cel = 1;
        for (int j = 0; j < count; j++) {
            if (i != j &&  (!isKnown(relation, j, i) || isKnown(relation, i, j))) {
                cel = 0;
                break;
            }
        }
        if(cel == 1)
            return i;
    }
    return -1;
}

int findCelebrity2(std::vector<std::vector<int>> &relation, int count) {
	std::stack<int> stk;
	int first = 0, second = 0;
	for (int i = 0; i < count; i++) {
		stk.push(i);
	}
	first = stk.top();
	stk.pop();
	while (stk.size() != 0) {
		second = stk.top();
		stk.pop();
		if (isKnown(relation, first, second))
			first = second;
	}
	for (int i = 0; i < count; i++) {
		if (first != i && isKnown(relation, first, i))
			return -1;
		if (first != i && isKnown(relation, i, first) == false)
			return -1;
	}
	return first;
}

int findCelebrity3(std::vector<std::vector<int>> &relation, int count) {
	int first = 0;
	int second = 1;

	for (int i = 0; i < (count - 1); i++) {
		if (isKnown(relation, first, second))
			first = second;
		second = second + 1;
	}
	for (int i = 0; i < count; i++) {
		if (first != i && isKnown(relation, first, i))
			return -1;
		if (first != i && isKnown(relation, i, first) == false)
			return -1;
	}
	return first;
}

// Testing code.
int main23() {
	std::vector<std::vector<int>> arr = { { 1, 0, 1, 1, 0 }, { 1, 0, 0, 1, 0 },
			{ 0, 0, 1, 1, 1 }, { 0, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1 } };

	std::cout << "Celebrity : " << findCelebrity(arr, 5) << std::endl;
	std::cout << "Celebrity : " << findCelebrity2(arr, 5) << std::endl;
	std::cout << "Celebrity : " << findCelebrity3(arr, 5) << std::endl;
	return 0;
}

/*
 Celebrity : 3
 Celebrity : 3
 */


void stockAnalystAdd(std::stack<int> &stk, int value){
    while(!stk.empty() && stk.top() <= value)
        stk.pop();
    stk.push(value);
}

// Testing code.
int main24() {
    int arr[] = { 20, 19, 10, 21, 40, 35, 39, 50, 45, 42 };
    std::stack<int> stk;
    for(int i = 9; i>=0; i--)
        stockAnalystAdd(stk, arr[i]);
    printStack(stk);
	return 0;
}

/*
[ 50 40 21 20 ]
*/


int findLargestIslandUtil(std::vector<std::vector<int>> &arr, int maxCol, int maxRow, 
						int currCol, int currRow, std::vector<std::vector<int>> &traversed) {
    int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, 
                    {1, -1}, {1, 0}, {1, 1}};
    int x, y, sum = 1;
    for(int i=0; i<8; i++) {
        x = currCol + dir[i][0];
        y = currRow + dir[i][1];
        if(x >= 0 && x < maxCol && y >= 0 && y < maxRow && traversed[x][y] == 0 && arr[x][y] == 1){
            traversed[x][y] = 1;
            sum += findLargestIslandUtil(arr, maxCol, maxRow, x, y, traversed);
        }
    }
    return sum;
}

int findLargestIsland(std::vector<std::vector<int>> &arr, int maxCol,
		int maxRow) {
	int maxVal = 0, currVal = 0;
	std::vector<std::vector<int>> traversed(maxCol);
	for (int i = 0; i < maxCol; i++) {
		traversed[i] = std::vector<int>(maxRow, 0);
	}

	for (int i = 0; i < maxCol; i++) {
		for (int j = 0; j < maxRow; j++) {
			if (traversed[i][j] == 0 && arr[i][j] == 1) {
				traversed[i][j] = 1;
				currVal = findLargestIslandUtil(arr, maxCol, maxRow, i, j, traversed);
				if (currVal > maxVal)
					maxVal = currVal;
			}
		}
	}
	return maxVal;
}

// Testing code.
int main25() {
	std::vector<std::vector<int>> arr = { { 1, 0, 1, 1, 0 }, { 1, 0, 0, 1, 0 },
			{ 0, 1, 1, 1, 1 }, { 0, 1, 0, 0, 0 }, { 1, 1, 0, 0, 1 } };
	std::cout << "Largest Island : " << findLargestIsland(arr, 5, 5) << std::endl;
	return 0;
}

/*
 Largest Island : 12
 */


// Testing code.
int main() {
	mainA();
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	main8();
	main9();
	main10();
	main11();
	main12();
	main13();
	main14();
	main15();
	main16();
	main17();
	main18();
	main19();
	main20();
	main21();
	main22();
	main23();
	main24();
	main25();
	return 0;
}
