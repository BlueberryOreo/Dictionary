#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Word.h"
using namespace std;

struct Node {
	char c;
	vector<Node> children;
	bool isEnd;
	Word word;
	Node(char c='\0', bool isEnd=false);
};

class Trie
{
	Node root;
public:
	Trie();
	void insert(Word& word);
	Word search(const string& word);
	vector<Word> rubSearch(const string& word);
};
