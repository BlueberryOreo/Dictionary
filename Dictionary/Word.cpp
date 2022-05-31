#include "Word.h"

Word::Word()
{
	word = "";
	meaning = "";
	memset(vect, 0, sizeof(vect));
	m_dis = 0;
}

Word::Word(string word)
{
	setWord(word);
	meaning = "";
	m_dis = 0;
}

Word::Word(string word, string meaning)
{
	setWord(word);
	setMeaning(meaning);
	m_dis = 0;
}

void Word::setWord(string word)
{
	this->word = word;
	for (int i = 0; i < word.size(); i ++) {
		if(word[i] >> 7 == 0) vect[word[i]] ++;
	}
}

void Word::setMeaning(string meaning)
{
	this->meaning = meaning;
}

string Word::getWord() const
{
	return word;
}

string Word::getMeaning() const
{
	return meaning;
}

int Word::getSize() const
{
	return word.size();
}

double Word::getDis() const
{
	return m_dis;
}

string Word::cut(int a, int b)
{
	string ret = "";
	for (int i = a; i < min(b, getSize()); i++) {
		ret.push_back(word[i]);
	}
	return ret;
}

bool Word::empty()
{
	return word.empty();
}

double Word::operator^(const Word& tmp)
{
	double dis = 0;
	for (int i = 0; i < 256; i++) {
		//cout << word1Arr[i] << " " << word2Arr[i] << endl;
		dis += abs(vect[i] - tmp.vect[i]) * abs(vect[i] - tmp.vect[i]);
	}
	m_dis = sqrt(dis);
	return m_dis;
}

int Word::operator|(const Word& tmp)
{
	int dis = 0;
	for (int i = 0; i < 256; i ++) {
		dis += abs(vect[i] - tmp.vect[i]);
	}
	m_dis = dis;
	return dis;
}

bool Word::operator<(const Word& tmp) const
{
	return m_dis < tmp.m_dis;
}

char& Word::operator[](int i)
{
	return word[i];
}
