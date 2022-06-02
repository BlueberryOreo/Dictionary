#pragma once
#include <string>
#include <iostream>
using namespace std;

//������

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
	void setWord(string word);
	void setMeaning(string meaning);
	void setDis(double dis);
	string getWord() const;
	string getMeaning() const;
	int getSize() const;
	double getDis() const;
	string cut(int a, int b); //�и������ұ�
	bool empty();
	double operator^(const Word &tmp); //ŷ�Ͼ���
	int operator|(const Word &tmp); //�����پ��루���Ƚ��ã�
	bool operator<(const Word &tmp) const;
	char& operator[](int i);
	friend ostream& operator<<(ostream& out, Word& w);
};

