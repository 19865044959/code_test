#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        if (mp.count(node)) return mp[node];
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for (const auto& k : node->neighbors) {
            mp[node]->neighbors.push_back(cloneGraph(k));
        }
        return mp[node];
    }
private:
    unordered_map<Node*, Node*> mp;
};
