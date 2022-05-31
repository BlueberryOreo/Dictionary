#include <iostream>
#include "Trie.h"
using namespace std;

int main() {
	
	Trie tree;
	tree.insert("apple", "ƻ��");
	tree.insert("pear", "��");
	tree.insert("acquire", "���");

	cout << tree.search("apple") << endl;
	cout << tree.search("acquire") << endl;

	return 0;
}