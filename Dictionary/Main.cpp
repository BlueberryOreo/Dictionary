#include <iostream>
#include "Trie.h"
using namespace std;

int main() {
	
	Trie tree;
	tree.insert("apple", "Æ»¹û");
	tree.insert("pear", "Àæ");
	tree.insert("acquire", "»ñµÃ");

	cout << tree.search("apple") << endl;
	cout << tree.search("acquire") << endl;

	return 0;
}