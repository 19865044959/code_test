#include<iostream>
#include<vector>

using namespace std;

class Trie {
private:
	vector<Trie*> next;
	bool isEnd; //还可以换成string型，这样在找到end时就能够找到以该end结尾的字符串

public:
	Trie() : next(26), isEnd(false){}

	void insert(string word) {
		Trie* node = this; //注：这里是让node指向成员函数所作用的对象，也就是this，有点儿类似TreeNode * node = root;
		for (auto c : word) {
			if (node->next[c - 'a'] == NULL) { //注：插入时，不能先node = node->next[c - 'a']，再进行node = new Trie()，因为这样没有修改node->next[c - 'a']的值
				node->next[c - 'a'] = new Trie(); 
			}
			node = node->next[c - 'a'];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie* node = this;
		for (auto c : word) {
			if (node->next[c - 'a'] == NULL) return false;
			node = node->next[c - 'a'];
		}
		return node->isEnd;
	}

	bool startsWith(string word) {
		Trie* node = this;
		for (auto c : word) {
			if (node->next[c - 'a'] == NULL) return false;
			node = node->next[c - 'a'];
		}
		return true;
	}
};