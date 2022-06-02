#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Word.h"
using namespace std;

//字典树类

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
	void insert(Word& word); //存入
	Word search(const string& word); //精确查找
	vector<Word> rubSearch(const string& word); //查找子树
};
