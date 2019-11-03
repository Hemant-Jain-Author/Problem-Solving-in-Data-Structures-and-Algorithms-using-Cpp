#include "Trie.h"
#include <algorithm>


Trie::Node::Node()
{
	for (int i = 0; i < CharCount; i++)
		child.push_back(nullptr);
	isLastChar = false;
}

Trie::Trie()
{
	root = new Node(); // first node with dummy value.
}

void Trie::add(const std::string &s)
{
	if (s == "")
		return;
	std::string str = s;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	add(root, str, 0);
}

Trie::Node *Trie::add(Node *curr, const std::string &str, int index)
{
	if (curr == nullptr)
	{
		curr = new Node();
	}

	if (str.length() == index)
	{
		curr->isLastChar = true;
	}
	else
	{
		curr->child[str[index] - 'a'] = add(curr->child[str[index] - 'a'], str, index + 1);
	}

	return curr;
}

void Trie::remove(const std::string &s)
{
	if (s == "")
		return;
	std::string str = s;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	remove(root, str, 0);
}

void Trie::remove(Node *curr, const std::string &str, int index)
{
	if (curr == nullptr)		
		return;

	if (str.length() == index)
	{
		if (curr->isLastChar)
		{
			curr->isLastChar = false;
		}
		return;
	}

	remove(curr->child[str[index] - 'a'], str, index + 1);
}

bool Trie::find(const std::string &s)
{
	if (s == "")
		return false;

	std::string str = s;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return find(root, str, 0);
}

bool Trie::find(Node *curr, const std::string &str, int index)
{
	if (curr == nullptr)
	{
		return false;
	}
	if (str.length() == index)
	{
		return curr->isLastChar;
	}
	return find(curr->child[str[index] - 'a'], str, index + 1);
}

int main()
{
	Trie *t = new Trie();
	std::string a = "hemant";
	std::string b = "heman";
	std::string c = "hemantjain";
	std::string d = "jain";
	t->add(a);
	t->add(d);
	std::cout << t->find(a) << std::endl;
	t->remove(a);
	t->remove(d);
	std::cout << t->find(a) << std::endl;
	std::cout << t->find(c) << std::endl;
	std::cout << t->find(d) << std::endl;
	return 0;
}