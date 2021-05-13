#include<iostream>
#include<vector>

using namespace std;

class Trie {
private:
	vector<Trie*> next;
	bool isEnd; //�����Ի���string�ͣ��������ҵ�endʱ���ܹ��ҵ��Ը�end��β���ַ���

public:
	Trie() : next(26), isEnd(false){}

	void insert(string word) {
		Trie* node = this; //ע����������nodeָ���Ա���������õĶ���Ҳ����this���е������TreeNode * node = root;
		for (auto c : word) {
			if (node->next[c - 'a'] == NULL) { //ע������ʱ��������node = node->next[c - 'a']���ٽ���node = new Trie()����Ϊ����û���޸�node->next[c - 'a']��ֵ
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