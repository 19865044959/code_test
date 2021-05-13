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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**********************************************************************************************************
������dfs

˵�������104���еĵ�һ�ַ�����dfs

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int maxD = 0;
        for (auto k : root->children) {
            maxD = max(maxD, maxDepth(k));
        }
        return maxD + 1;
    }
};


/**********************************************************************************************************
������bfs

˵�������104���еĵڶ��ַ�����bfs

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0; //ע���п�ָ����������
        queue<Node*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            int n = q.size();
            cnt++;
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                for (auto k : temp->children) {
                    if (k != NULL) q.push(k);
                }
            }
        }
        return cnt;
    }
};