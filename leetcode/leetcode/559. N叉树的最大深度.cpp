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
方法：dfs

说明：详见104题中的第一种方法：dfs

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

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
方法：bfs

说明：详见104题中的第二种方法：bfs

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0; //注意有空指针的情况出现
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