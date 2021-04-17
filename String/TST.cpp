#include "TST.h"

TST::Node::Node(TST *outerInstance, char d)
{
    data = d;
    isLastChar = false;
    left = equal = right = nullptr;
}

void TST::add(const std::string &word)
{
    root = add(root, word, 0);
}

TST::Node *TST::add(Node *curr, const std::string &word, int wordIndex)
{
    if (curr == nullptr)
        curr = new Node(this, word[wordIndex]);
    
    if (word[wordIndex] < curr->data)
        curr->left = add(curr->left, word, wordIndex);
    else if (word[wordIndex] > curr->data)
        curr->right = add(curr->right, word, wordIndex);
    else
    {
        if (wordIndex < word.length() - 1)
            curr->equal = add(curr->equal, word, wordIndex + 1);
        else
            curr->isLastChar = true;
    }
    return curr;
}

bool TST::find(Node *curr, const std::string &word, int wordIndex)
{
    if (curr == nullptr)
        return false;

    if (word[wordIndex] < curr->data)
        return find(curr->left, word, wordIndex);
    else if (word[wordIndex] > curr->data)
        return find(curr->right, word, wordIndex);
    else
    {
        if (wordIndex == word.length() - 1)
            return curr->isLastChar;
        
        return find(curr->equal, word, wordIndex + 1);
    }
}

bool TST::find(const std::string &word)
{
    bool ret = find(root, word, 0);
    return ret;
}

int main()
{

    TST *tt = new TST();
    tt->add("banana");
    tt->add("apple");
    tt->add("mango");

    std::cout << "find apple : "  << tt->find("apple") << std::endl;
    std::cout << "find banana : "  << tt->find("banana") << std::endl;
    std::cout << "find grapes : "  << tt->find("grapes") << std::endl;
    std::cout << "find mango : "  << tt->find("mango") << std::endl;
    return 0;
}

/*
find apple : 1
find banana : 1
find grapes : 0
find mango : 1
*/