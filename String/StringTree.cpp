#include "StringTree.h"

StringTree::Node::Node(std::string val)
{
    value = val;
    lChild = rChild = nullptr;
    count = 1;
}

void StringTree::print()
{
    print(root);
}

void StringTree::print(Node *curr)
{
    if (curr != nullptr)
    {
        std::cout << " value is ::" << curr->value;
        std::cout << " count is :: " << curr->count << std::endl;
        print(curr->lChild);
        print(curr->rChild);
    }
}

void StringTree::add(const std::string &value)
{
    root = add(value, root);
}

StringTree::Node *StringTree::add(const std::string &value, Node *curr)
{
    int compare;
    if (curr == nullptr)
        curr = new Node(value);
    else
    {
        compare = curr->value.compare(value);
        if (compare == 0)
            curr->count++;
        else if (compare == 1)
            curr->lChild = add(value, curr->lChild);
        else
            curr->rChild = add(value, curr->rChild);
    }
    return curr;
}

void StringTree::freeTree()
{
    freeTree(root);
    root = nullptr;
}

void StringTree::freeTree(Node* node)
{
    if (node)
    {
        freeTree(node->lChild);
        freeTree(node->rChild);
        delete(node);
    }
}

bool StringTree::find(const std::string &value)
{
    bool ret = find(root, value);
    return ret;
}

bool StringTree::find(Node *curr, const std::string &value)
{
    int compare;
    if (curr == nullptr)
        return false;

    compare = curr->value.compare(value);
    if (compare == 0)
        return true;
    else
    {
        if (compare == 1)
            return find(curr->lChild, value);
        else
            return find(curr->rChild, value);
    }
}

int StringTree::frequency(const std::string &value)
{
    return frequency(root, value);

}

int StringTree::frequency(Node *curr, const std::string &value)
{
    int compare;
    if (curr == nullptr)
        return 0;

    compare = curr->value.compare(value);
    if (compare == 0)
        return curr->count;
    else
    {
        if (compare > 0)
            return frequency(curr->lChild, value);
        else
            return frequency(curr->rChild, value);
    }
}

int main()
{
    StringTree *tt = new StringTree();
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