#include "Trie.h"

Node::Node(char c, bool isEnd)
{
	this->c = c;
	this->isEnd = isEnd;
}

Trie::Trie()
{
}

void Trie::insert(const string& word, const string& meaning)
{
	int len = word.size();
	Node* now = &root;
	for (int i = 0; i < len; i ++) {
		bool flag = false;
		for (int j = 0; j < (*now).children.size(); j ++) {
			if ((*now).children[j].c == word[i]) {
				flag = true;
				now = &(*now).children[j];
				break;
			}
		}

		if (!flag) {
			//该节点没有存储这个字母
			(*now).children.push_back(Node(word[i]));
			now = &(*now).children.back();
		}
	}

	(*now).isEnd = true;
	(*now).word = word;
	(*now).meaning = meaning;
}

string Trie::search(const string& word)
{
	Node* now = &root;
	int len = word.size();
	for (int i = 0; i < len; i ++) {
		bool flag = false;
		for (int j = 0; j < (*now).children.size(); j ++) {
			if ((*now).children[j].c == word[i]) {
				flag = true;
				now = &(*now).children[j];
				break;
			}
		}
		if (!flag) return "";
	}
	
	if ((*now).isEnd) return (*now).meaning;
	else return "";
}
