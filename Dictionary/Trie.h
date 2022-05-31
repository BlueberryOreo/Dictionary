#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node {
	char c;
	vector<Node> children;
	bool isEnd;
	pair<string, string> word; //word-meaning
	Node();
};

class Trie
{
	Node root;
public:
	Trie();
	void insert(string word);
	string search(string word);
};

