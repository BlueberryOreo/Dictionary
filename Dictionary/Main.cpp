#include <iostream>
#include <fstream>
#include <cmath>
#include "Trie.h"

#define DEBUG
using namespace std;

void importDict(const string &path, Trie &tree) {
	ifstream ifs;
	ifs.open(path);
	string line;
	while (getline(ifs, line)) {
		string word, meaning;
		int i = 0;
		while (line[i] != '[') word.push_back(line[i++]);
		while (line[i] != ']') i++;
		i++;
		while (line[i]) meaning.push_back(line[i++]);
		Word tmp(word, meaning);
		//cout << "Word:" << tmp.getWord() << " " << tmp.getMeaning() << endl;
		tree.insert(tmp);
		//cout << "here" << endl;
	}
	
	ifs.close();
}

double wordDistance(const string &word1, const string &word2) {
	int word1Arr[256] = {}, word2Arr[256] = {};
	int len1 = word1.size(), len2 = word2.size();
	for (int i = 0; i < len1 || i < len2; i++) {
		i < len1 ? word1Arr[word1[i]] ++ : 1;
		i < len2 ? word2Arr[word2[i]] ++ : 2;
	}
	double dis = 0;
	for (int i = 0; i < 256; i ++) {
		//cout << word1Arr[i] << " " << word2Arr[i] << endl;
		dis += abs(word1Arr[i] - word2Arr[i]) * abs(word1Arr[i] - word2Arr[i]);
	}
	return sqrt(dis);
}

/**
 * ��Ԥ��Ĵ�������
 * input:
 *	Word input: ���յ��Ĵ�
 *  vector<Word> words: Ԥ�⵽�Ĵ�
 *  priority_queue<Word> &q: ����+�洢�ô����
 *  int n: ֻ������С�����ǰn��
 * 
*/
void sort(Word input, vector<Word> words, priority_queue<Word> &q, int n) {
	int len = words.size();
	for (int i = 0; i < len; i ++) {
		if (q.size() < n) {
			words[i] ^ input;
			q.push(words[i]);
		}
		else {
			if ((words[i] ^ input) < (input ^ q.top())) {
				//cout << (input ^ words[i]) << " " << (input ^ q.top()) << endl;
				q.pop();
				q.push(words[i]);
			}
		}
	}
}

int main() {

	/*
		���⣺sort�������������ռ���õ��ľ��벻׼ȷ
	*/

#ifdef DEBUG
	priority_queue<Word> q;
	Word w1("query");
	Word w2("quary");
	Word w3("quaff");
	cout << (w1 ^ w2) << endl;
	cout << (w3 ^ w1) << endl;
	q.push(w1);
	q.push(w3);
	cout << q.top().getDis() << endl;
	q.pop();
	cout << q.top().getDis() << endl;
#endif
	
	/*
	Trie tree;
	tree.insert("apple", "ƻ��");
	tree.insert("pear", "��");
	tree.insert("acquire", "���");

	cout << tree.search("apple") << endl;
	cout << tree.search("acquire") << endl;
	*/

	
	Trie dict;
	importDict("..\\..\\Ӣ���ֵ�����.txt", dict);

	cout << "������Ҫ��ѯ�Ĵ������###�˳���������";
	string query;
	getline(cin, query);
	while (query != "###") {
		Word res = dict.search(query);
		if (res.empty()) {
			cout << "δ���ҵ��ô���" << endl;
			Word wQuery(query);
			vector<Word> rub = dict.rubSearch(wQuery.cut(0, 1));
			priority_queue<Word> predict;
			sort(wQuery, rub, predict, 10);
			cout << "���������ѣ�" << endl;
			while (!predict.empty()) {
				cout << predict.top().getWord() << " ���壺" << predict.top().getMeaning() << " " << predict.top().getDis() << endl;
				predict.pop();
			}
		}
		else cout << res.getMeaning() << endl;

		cout << endl;
		cout << "������Ҫ��ѯ�Ĵ������###�˳���������";
		getline(cin, query);
	}
	

	return 0;
}