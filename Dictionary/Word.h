#pragma once
#include <string>
using namespace std;
class Word
{
	string word;
	string meaning;
	int vect[256];
	double m_dis;
public:
	Word();
	Word(string word);
	Word(string word, string meaning);
	//Word(Word& tmp);
	void setWord(string word);
	void setMeaning(string meaning);
	string getWord() const;
	string getMeaning() const;
	int getSize() const;
	double getDis() const;
	string cut(int a, int b); //ÇĞ¸î´ÊÓï£¬×ó¿ªÓÒ±Õ
	bool empty();
	double operator^(const Word &tmp); //Å·ÊÏ¾àÀë
	int operator|(const Word &tmp); //Âü¹ş¶Ù¾àÀë
	bool operator<(const Word &tmp) const;
	char& operator[](int i);
};

