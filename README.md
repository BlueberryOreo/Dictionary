Dictionary

## C++5月27日实践课

编码：GBK

源代码：

* Main.cpp - 程序入口
* Trie.h - 字典树类
* Trie.cpp
* Word.h - 单词类
* Word.cpp

查询效率提升方法：将词典存储为字典树

模糊搜索方法：通过字典树找出以某个字母开头的所有词，然后通过词向量之间的余弦相似度判断相似性
