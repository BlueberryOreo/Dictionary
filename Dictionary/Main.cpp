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
 * 给预测的词语排序
 * input:
 *	Word input: 接收到的词
 *  vector<Word> words: 预测到的词
 *  priority_queue<Word> &q: 排序+存储用大根堆
 *  int n: 只保留从小到大的前n个
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
		问题：sort函数中排序最终计算得到的距离不准确
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
	tree.insert("apple", "苹果");
	tree.insert("pear", "梨");
	tree.insert("acquire", "获得");

	cout << tree.search("apple") << endl;
	cout << tree.search("acquire") << endl;
	*/

	
	Trie dict;
	importDict("..\\..\\英汉字典数据.txt", dict);

	cout << "请输入要查询的词语（输入###退出交互）：";
	string query;
	getline(cin, query);
	while (query != "###") {
		Word res = dict.search(query);
		if (res.empty()) {
			cout << "未查找到该词语" << endl;
			Word wQuery(query);
			vector<Word> rub = dict.rubSearch(wQuery.cut(0, 1));
			priority_queue<Word> predict;
			sort(wQuery, rub, predict, 10);
			cout << "您可能想搜：" << endl;
			while (!predict.empty()) {
				cout << predict.top().getWord() << " 释义：" << predict.top().getMeaning() << " " << predict.top().getDis() << endl;
				predict.pop();
			}
		}
		else cout << res.getMeaning() << endl;

		cout << endl;
		cout << "请输入要查询的词语（输入###退出交互）：";
		getline(cin, query);
	}
	

	return 0;
}