#include <string>
#include <vector>
#include <iostream>

bool matchExpUtil(const std::string exp, const std::string str, int i, int j)
{
    if (i == exp.size() && j == str.size())
        return true;

    if ((i == exp.size() && j != str.size()) || (i != exp.size() && j == str.size()))
        return false;
    
    if (exp[i] == '?' || exp[i] == str[j])
        return matchExpUtil(exp, str, i + 1, j + 1);
    
    if (exp[i] == '*')
        return matchExpUtil(exp, str, i + 1, j) || matchExpUtil(exp, str, i, j + 1) || matchExpUtil(exp, str, i + 1, j + 1);
    
    return false;
}

bool matchExp(const std::string exp, const std::string str)
{
    return matchExpUtil(exp, str, 0, 0);
}

void main1()
{
    std::cout << matchExp("*llo,?World?", "Hello, World!") << std::endl;
}
/*
1
*/

bool match(const std::string &source, const std::string &pattern)
{
    int iSource = 0;
    int iPattern = 0;
    int sourceLen = source.size();
    int patternLen = pattern.size();
    for (iSource = 0; iSource < sourceLen; iSource++)
    {
        if (source[iSource] == pattern[iPattern])
            iPattern++;

        if (iPattern == patternLen)
            return true;

    }
    return false;
}

void main2()
{
    std::cout << match("harrypottermustnotgotoschool", "pottergo") << std::endl;
}

/*
1
*/

bool isPrime(const int n)
{
    bool answer = (n > 1) ? true : false;

    for (int i = 2; i * i < n; ++i)
    {
        if (n % i == 0)
        {
            answer = false;
            break;
        }
    }
    return answer;
}

void main3()
{
    std::cout << "Prime numbers under 100 :: ";
    for (int i = 0; i < 20; i++)
        if (isPrime(i))
            std::cout << i << " ";
    std::cout << std::endl;
}

/*
Prime numbers under 100 :: 2 3 4 5 7 9 11 13 17 19 
*/

int myAtoi(const std::string &str)
{
    int value = 0;

    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        char ch = str[i];
        value = (value << 3) + (value << 1) + (ch - '0');
    }
    return value;
}

void main4()
{
    std::cout << myAtoi("1000") << std::endl;
}
/*
1000
*/

bool isUniqueChar(const std::string &str)
{
    std::vector<int> bitarr(26, 0);
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        char c = str[i];
        if ('A' <= c && 'Z' >= c)
            c = static_cast<char>(c - 'A');
        else if ('a' <= c && 'z' >= c)
            c = static_cast<char>(c - 'a');
        else
        {
            std::cout << "Unknown Char!" << std::endl;
            return false;
        }

        if (bitarr[c] != 0)
        {
            std::cout << "Duplicate detected!" << std::endl;
            return false;
        }
        bitarr[c] = 1;
    }
    std::cout << "No duplicate detected!" << std::endl;
    return true;
}

void main5()
{
    std::cout << isUniqueChar("aple") << std::endl;
    std::cout << isUniqueChar("apple") << std::endl;
}

/*
No duplicate detected!
1
Duplicate detected!
0
*/

char toUpper(const char s)
{
    char t;
    if (s >= 97 && s <= (97 + 25))
        t = static_cast<char>(s - 32);
    
    return t;
}

char toLower(const char s)
{
    char t;
    if (s >= 65 && s <= (65 + 25))
        t = static_cast<char>(s + 32);
    
    return t;
}

char lowerUpper(const char s)
{
    char t;
    if (s >= 97 && s <= (97 + 25))
        t = static_cast<char>(s - 32);
    else if (s >= 65 && s <= (65 + 25))
        t = static_cast<char>(s + 32);
    
    return t;
}

void main6()
{
    std::cout << toLower('A') << std::endl;
    std::cout << toUpper('a') << std::endl;
    std::cout << lowerUpper('s') << std::endl;
    std::cout << lowerUpper('S') << std::endl;
}

/*
a
A
S
s
*/

bool isPermutation(const std::string &s1, const std::string &s2)
{
    std::vector<int> count(256);
    int length = s1.length();
    if (s2.length() != length)
    {
        std::cout << "is permutation return false" << std::endl;
        return false;
    }
    
    for (int i = 0; i < 256; i++)
        count[i] = 0;
    
    for (int i = 0; i < length; i++)
    {
        char ch = s1[i];
        count[ch]++;
        ch = s2[i];
        count[ch]--;
    }
    for (int i = 0; i < length; i++)
    {
        if (count[i] != 0)
        {
            std::cout << "is permutation return false" << std::endl;
            return false;
        }
    }
    std::cout << "is permutation return true" << std::endl;
    return true;
}

void main7()
{
    std::cout << isPermutation("apple", "plepa");
}

/*
is permutation return true
1
*/

bool isPalindrome(const std::string &str)
{
    int i = 0, j = str.length() - 1;
    while (i < j && str[i] == str[j])
    {
        i++;
        j--;
    }
    if (i < j)
    {
        std::cout << "String is not a Palindrome" << std::endl;
        return false;
    }
    else
    {
        std::cout << "String is a Palindrome" << std::endl;
        return true;
    }
}

void main8()
{
    std::cout << isPalindrome("hello") << std::endl;
    std::cout << isPalindrome("eoloe") << std::endl;
}

/*
String is not a Palindrome
0
String is a Palindrome
1
*/

int pow(const int x, const int n)
{
    int value;
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        value = pow(x, n / 2);
        return (value * value);
    }
    else
    {
        value = pow(x, n / 2);
        return (x * value * value);
    }
}

void main9()
{
    std::cout << pow(5, 2) << std::endl;
}

/*
25
*/


int myStrcmp(const std::string &a, const std::string &b)
{
    int index = 0;
    int len1 = a.length();
    int len2 = b.length();
    int minlen = len1;
    if (len1 > len2)
        minlen = len2;

    while (index < minlen && a[index] == b[index])
        index++;

    if (index == len1 && index == len2)
        return 0;
    else if (len1 == index)
        return -1;
    else if (len2 == index)
        return 1;
    else
        return a[index] - b[index];
}

void main10()
{
    std::cout << myStrcmp("abs", "abs") << std::endl;
}

/*
0
*/

void reverseString(std::string &a)
{
    int lower = 0;
    int upper = a.size() - 1;
    char tempChar;
    while (lower < upper)
    {
        tempChar = a[lower];
        a[lower] = a[upper];
        a[upper] = tempChar;
        lower++;
        upper--;
    }
}

void reverseString(std::string &a, int lower, int upper)
{
    char tempChar;
    while (lower < upper)
    {
        tempChar = a[lower];
        a[lower] = a[upper];
        a[upper] = tempChar;
        lower++;
        upper--;
    }
}

void reverseWords(std::string &a)
{
    int length = a.size();
    int lower, upper = -1;
    lower = 0;
    for (int i = 0; i <= length; i++)
    {
        if (a[i] == ' ' || a[i] == '\0')
        {
            reverseString(a, lower, upper);
            lower = i + 1;
            upper = i;
        }
        else
        {
            upper++;
        }
    }
    reverseString(a, 0, length - 1);
}

void main11()
{
    std::string first = "apple";
    reverseString(first);
    std::cout << first << std::endl;
    std::string second = "hello world";
    reverseWords(second);
    std::cout << second << std::endl;
}

/*
elppa
world hello
*/

void printAnagram(std::string &a, int max, int n)
{
    if (max == 1)
    {
        for(auto ch : a)
            std::cout << ch;
        std::cout << std::endl;
    }
    char temp;
    for (int i = -1; i < max - 1; i++)
    {
        if (i != -1)
        {
            temp = a[i];
            a[i] = a[max - 1]; 
            a[max - 1] = temp;
        }
        printAnagram(a, max - 1, n);
        if (i != -1)
        {
            temp = a[i];
            a[i] = a[max - 1]; 
            a[max - 1] = temp;        
        }
    }
}

void printAnagram(std::string  &a)
{
    int n = a.size();
    printAnagram(a, n, n);
}

void main12()
{
    std::string first = "123";
    printAnagram(first);
}

/* 
123
213
321
231
132
312
*/

void shuffle(std::string &ar)
{
    int n = ar.size() / 2;
    int count = 0;
    int k = 1;
    char temp = '\0';
    for (int i = 1; i < n; i = i + 2)
    {
        temp = ar[i];
        k = i;
        do
        {
            k = (2 * k) % (2 * n - 1);
            temp ^= ar[k] ^= temp ^= ar[k];
            count++;
        }
        while (i != k);
        if (count == (2 * n - 2))
        {
            break;
        }
    }
}

void main13()
{
    std::string first = "ABCDE12345";
    shuffle(first);
    std::cout << first << std::endl;
}

/*
A1B2C3D4E5
*/

std::string addBinary(const std::string &first, const std::string &second)
{
    int size1 = first.size();
    int size2 = second.size();
    int totalIndex;
    std::string total;
    if (size1 > size2)
    {
        total = std::string('0',size1 + 1);
        totalIndex = size1;
    }
    else
    {
        total = std::string('0', size2 + 1);
        totalIndex = size2;
    }
    total[totalIndex + 1] = '\0';
    int carry = 0;
    size1--;
    size2--;
    while (size1 >= 0 || size2 >= 0)
    {
        int firstValue = (size1 < 0) ? 0 : first[size1] - '0';
        int secondValue = (size2 < 0) ? 0 : second[size2] - '0';
        int sum = firstValue + secondValue + carry;
        carry = sum >> 1;
        sum = sum & 1;
        total[totalIndex] = (sum == 0) ? '0' : '1';
        totalIndex--;
        size1--;
        size2--;
    }
    total[totalIndex] = (carry == 0) ? '0' : '1';
    return total;
}

void main14()
{
    std::string first = "1000", second = "11111111";
    std::cout << addBinary(first, second);
}

/*
100000111
*/

int main()
{
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
}
