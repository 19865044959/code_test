#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：bfs(层序遍历)

说明：
    1. 注意层k与层k+1之间最后一个元素的判断：当i = n -1 时是层k的最后一个元素，此时取出的temp的next
        不应该指向任何值，应该为NULL，否则会指向下一层第一个元素而不符合题意
    2. 本题是原原版版的层序遍历模板，详见题104

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

***********************************************************************************************************/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                if (i != n - 1) {//当i不是层中最后一个元素时
                    temp->next = q.front();
                }
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};