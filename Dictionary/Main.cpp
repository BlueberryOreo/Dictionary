#include <iostream>
#include <fstream>
#include <cmath>
#include "Trie.h"

#define DEBUGn
using namespace std;

int importDict(const string &path, Trie &tree) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs) return 0;
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
	return 1;
}

/**
 * ��Ԥ��Ĵ�������
 * input:
 *	Word input: ���յ��Ĵ�
 *  vector<Word> words: Ԥ�⵽�Ĵ�
 *  priority_queue<Word> &q: ����+�洢�ô����
 *  int n: ֻ�������ƶ���ߵ�ǰn��
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
		
		// cout << words[i].getWord() << " " << words[i].getDis() << endl;
		// cout << words[i] << endl;
	}
}

int main() {

	/*
		���⣺sort�������������ռ���õ��ľ��벻׼ȷ
		�ѽ����ԭ�򣺳�ʼ��Word��ʱ��δ�����������ʼ��Ϊ0
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
	
	Trie dict;
	int res = importDict("Ӣ���ֵ�����.txt", dict);
	if (!res) {
		cout << "δ�ҵ��ʵ��ļ���" << endl;
		return 0;
	}

	cout << "������Ҫ��ѯ�Ĵ������###�˳���������";
	string query;
	getline(cin, query);
	while (query != "###") {
		Word res = dict.search(query);
		if (res.empty()) {
			cout << "δ���ҵ��ô���" << endl;
			Word wQuery(query);
			string start = wQuery.cut(0, 1);
			//�������ͷ�Ĵ�Сд����һ��
			if ('A' <= start[0] && start[0] <= 'Z') start[0] += 32;
			vector<Word> rub = dict.rubSearch(start);
			start[0] -= 32;
			vector<Word> rubhigh = dict.rubSearch(start);
			for (int i = 0; i < rubhigh.size(); i ++) {
				rub.push_back(rubhigh[i]);
			}

			priority_queue<Word> predict;
			sort(wQuery, rub, predict, 10);

			cout << "���������ѣ�" << endl;
			vector<Word> out;
			while (!predict.empty()) {
				out.push_back(predict.top());
				predict.pop();
			}
			for (int i = out.size() - 1; i >= 0; i --) {
				cout << "? " << out[i] << endl;
			}
		}
		else cout << res.getMeaning() << endl;

		cout << endl;
		cout << "������Ҫ��ѯ�Ĵ������###�˳���������";
		getline(cin, query);
	}
	

	return 0;
}