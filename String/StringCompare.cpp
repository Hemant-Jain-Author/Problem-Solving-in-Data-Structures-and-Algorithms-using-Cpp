#include <string>
#include <vector>
#include <iostream>

int bruteForceSearch(std::vector<char> &text, std::vector<char> &pattern)
{
    int i = 0, j = 0;
    const int n = text.size();
    const int m = pattern.size();
    while (i <= n - m)
    {
        j = 0;
        while (j < m && pattern[j] == text[i + j])
        {
            j++;
        }
        if (j == m)
        {
            return (i);
        }
        i++;
    }
    return -1;
}

int bruteForceSearch(const std::string &text, const std::string &pattern)
{
    std::vector<char> txt(text.begin(), text.end());
    std::vector<char> ptn(pattern.begin(), pattern.end());
    return bruteForceSearch(txt, ptn);
}

int robinKarp(std::vector<char> &text, std::vector<char> &pattern)
{
    int n = text.size();
    int m = pattern.size();
    int i, j;
    int prime = 101;
    int powm = 1;
    int TextHash = 0, PatternHash = 0;
    if (m == 0 || m > n)
    {
        return -1;
    }

    for (i = 0; i < m - 1; i++)
    {
        powm = (powm << 1) % prime;
    }

    for (i = 0; i < m; i++)
    {
        PatternHash = ((PatternHash << 1) + pattern[i]) % prime;
        TextHash = ((TextHash << 1) + text[i]) % prime;
    }

    for (i = 0; i <= (n - m); i++)
    {
        if (TextHash == PatternHash)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                return i;
            }
        }
        TextHash = (((TextHash - text[i] * powm) << 1) + text[i + m]) % prime;
        if (TextHash < 0)
        {
            TextHash = (TextHash + prime);
        }
    }
    return -1;
}

int robinKarp(const std::string &text, const std::string &pattern)
{
    std::vector<char> txt(text.begin(), text.end());
    std::vector<char> ptn(pattern.begin(), pattern.end());
    return robinKarp(txt, ptn);
}


void kmpPreprocess(std::vector<char> &pattern, std::vector<int> &ShiftArr)
{
    const int m = pattern.size();
    int i = 0, j = -1;
    ShiftArr[i] = -1;
    while (i < m)
    {
        while (j >= 0 && pattern[i] != pattern[j])
        {
            j = ShiftArr[j];
        }
        i++;
        j++;
        ShiftArr[i] = j;
    }
}

int kmp(std::vector<char> &text, std::vector<char> &pattern)
{
    int i = 0, j = 0;
    const int n = text.size();
    const int m = pattern.size();
    std::vector<int> ShiftArr(m + 1);
    kmpPreprocess(pattern, ShiftArr);
    while (i < n)
    {
        while (j >= 0 && text[i] != pattern[j])
        {
            j = ShiftArr[j];
        }
        i++;
        j++;
        if (j == m)
        {
            return (i - m);
        }
    }
    return -1;
}

int kmp(const std::string &text, const std::string &pattern)
{
    std::vector<char> txt(text.begin(), text.end());
    std::vector<char> ptn(pattern.begin(), pattern.end());
    return kmp(txt, ptn);
}


int main1()
{
    std::string st1 = "hello, world!";
    std::string st2 = "world";
    std::cout << "Using BruteForceSearch pattern found at index : " << bruteForceSearch(st1, st2) << std::endl;
    std::cout << "Using RobinKarp pattern found at index : " << robinKarp(st1, st2) << std::endl;
    std::cout << "Using KMP pattern found at index : " << kmp(st1, st2) << std::endl;
    return 0;
}

/*
Using BruteForceSearch pattern found at index : 7
Using RobinKarp pattern found at index : 7
Using KMP pattern found at index : 7
*/

int kmpFindCount(std::vector<char> &text, std::vector<char> &pattern)
{
    int i = 0, j = 0, count = 0;
    const int n = text.size();
    const int m = pattern.size();
    std::vector<int> ShiftArr(m + 1);
    kmpPreprocess(pattern, ShiftArr);
    while (i < n)
    {
        while (j >= 0 && text[i] != pattern[j])
        {
            j = ShiftArr[j];
        }
        i++;
        j++;
        if (j == m)
        {
            count++;
            j = ShiftArr[j];
        }
    }
    return count;
}

int kmpFindCount(const std::string &text, const std::string &pattern)
{
    std::vector<char> txt(text.begin(), text.end());
    std::vector<char> ptn(pattern.begin(), pattern.end());
    return kmpFindCount(txt, ptn);
}

int main()
{
    std::string str = "Only time will tell if we stand the test of time";
    std::cout << "Frequency of 'time' is : " << kmpFindCount(str, "time") << std::endl;
    return 0;
}

/*
Frequency of 'time' is : 2
*/