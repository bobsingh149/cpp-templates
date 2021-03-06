#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	bool isword;
	vector<node *> next;

	node()
	{
		isword = false;
		next = vector<node *>(26, nullptr);
	}
};
class Trie
{

	node *root;

	node *ins(node *current, int pos, string &word)
	{
		if (current == nullptr)
			current = new node();

		if (pos >= word.size())
		{
			current->isword = true;
			return current;
		}
		char c = word[pos];
		int idx = c - 'a';
		current->next[idx] = ins(current->next[idx], pos + 1, word);

		return current;
	}

	bool sea(node *current, int pos, string &word)
	{
		if (current == nullptr)
			return false;

		if (pos == word.size())
		{
			if (current->isword == true)
				return true;
			else
				return false;
		}

		char c = word[pos];
		int idx = c - 'a';

		return sea(current->next[idx], pos + 1, word);
	}

	bool prefix(node *current, int pos, string &word)
	{
		if (current == nullptr)
		{

			//  cout<<" for "<<word[pos]<<endl;
			return false;
		}

		if (pos >= word.size())
		{
			// cout<<"true"<<endl;
			return true;
		}

		char c = word[pos];
		// cout<<"char "<<c<<endl;
		int idx = c - 'a';

		return prefix(current->next[idx], pos + 1, word);
	}

public:
	Trie()
	{

		root = new node();
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		this->ins(root, 0, word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		return this->sea(root, 0, word);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		return this->prefix(root, 0, prefix);
	}
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */