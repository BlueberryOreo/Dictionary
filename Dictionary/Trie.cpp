#include "Trie.h"

Node::Node(char c, bool isEnd)
{
	this->c = c;
	this->isEnd = isEnd;
}

Trie::Trie()
{
}

void Trie::insert(Word &word)
{
	int len = word.getSize();
	Node* now = &root;
	for (int i = 0; i < len; i ++) {
		bool flag = false;
		for (int j = 0; j < (*now).children.size(); j ++) {
			if ((*now).children[j].c == word[i]) {
				//�ýڵ��Ѿ��洢�������ĸ
				flag = true;
				now = &(*now).children[j];
				break;
			}
		}

		if (!flag) {
			//�ýڵ�û�д洢�����ĸ
			(*now).children.push_back(Node(word[i]));
			now = &(*now).children.back();
		}
	}

	(*now).isEnd = true;
	(*now).word = word;
}

Word Trie::search(const string& word)
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
		//�ýڵ�û�д洢�������ĸ��ֱ��ֹͣ����
		if (!flag) return Word();
	}
	
	if ((*now).isEnd) return (*now).word;
	else return Word();
}

vector<Word> Trie::rubSearch(const string& word)
{
	vector<Word> ret;
	int len = word.size();
	Node* p = &root;
	for (int i = 0; i < len; i ++) {
		bool flag = false;
		for (int j = 0; j < (*p).children.size(); j ++) {
			if ((*p).children[j].c == word[i]) {
				p = &((*p).children[j]);
				flag = true;
				break;
			}
		}
		if (!flag) break;
	}

	queue<Node*> q;
	q.push(p);
	while (!q.empty()) {
		Node* now = q.front();
		q.pop();
		if ((*now).isEnd) ret.push_back((*now).word);
		for (int i = 0; i < (*now).children.size(); i ++) {
			q.push(&(*now).children[i]);
		}
	}
	return ret;
}

