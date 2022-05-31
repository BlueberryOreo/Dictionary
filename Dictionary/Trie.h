#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node {
	char c;
	vector<Node> children;
	bool isEnd;
	string word;
	string meaning;
	Node(char c='\0', bool isEnd=false);
};

class Trie
{
	Node root;
public:
	Trie();
	void insert(const string& word, const string& meaning);
	string search(const string& word);
};

