#include "Trie.h"

Node::Node()
{
	isEnd = false;
}

Trie::Trie()
{
}

void Trie::insert(string word)
{
	int len = word.size();
	Node* now = &root;
	for (int i = 0; i < len; i ++) {
		for (int j = 0; j < (*now).children.size(); j ++) {
			if ((*now).children[j].c == word[i]) {
				now = &(*now).children[j];
				break;
			}
		}
	}
}
