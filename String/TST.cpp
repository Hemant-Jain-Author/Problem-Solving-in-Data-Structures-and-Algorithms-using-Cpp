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
	{
		curr = new Node(this, word[wordIndex]);
	}
	if (word[wordIndex] < curr->data)
	{
		curr->left = add(curr->left, word, wordIndex);
	}
	else if (word[wordIndex] > curr->data)
	{
		curr->right = add(curr->right, word, wordIndex);
	}
	else
	{
		if (wordIndex < word.length() - 1)
		{
			curr->equal = add(curr->equal, word, wordIndex + 1);
		}
		else
		{
			curr->isLastChar = true;
		}
	}
	return curr;
}

bool TST::find(Node *curr, const std::string &word, int wordIndex)
{
	if (curr == nullptr)
	{
		return false;
	}
	if (word[wordIndex] < curr->data)
	{
		return find(curr->left, word, wordIndex);
	}
	else if (word[wordIndex] > curr->data)
	{
		return find(curr->right, word, wordIndex);
	}
	else
	{
		if (wordIndex == word.length() - 1)
		{
			return curr->isLastChar;
		}
		return find(curr->equal, word, wordIndex + 1);
	}
}

bool TST::find(const std::string &word)
{
	bool ret = find(root, word, 0);
	std::cout << word << " :: ";
	if (ret)
	{
		std::cout << " Found " << std::endl;
	}
	else
	{
		std::cout << "Not Found " << std::endl;
	}
	return ret;
}

int main()
{

	TST *tt = new TST();
	tt->add("banana");
	tt->add("apple");
	tt->add("mango");
	std::cout << "Search results for apple, banana, grapes and mango :" << std::endl;
	tt->find("apple");
	tt->find("banana");
	tt->find("mango");
	tt->find("grapes");
	return 0;
}
