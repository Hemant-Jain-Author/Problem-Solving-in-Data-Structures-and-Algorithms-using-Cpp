#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Trie
{
private:
    struct Node
    {
        bool isLastChar = false;
        std::vector<Node*> child;
        Node();
    };

    static const int CharCount = 26;
    Node *root = nullptr;
    virtual Node *add(Node *curr, const std::string &str, int index);
    virtual void remove(Node *curr, const std::string &str, int index);
    virtual bool find(Node *curr, const std::string &str, int index);

public:
    Trie();
    virtual void add(const std::string &str);
    virtual void remove(const std::string &str);
    virtual bool find(const std::string &str);
};
