#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������bfs(�������)

˵����
    1. ע���k���k+1֮�����һ��Ԫ�ص��жϣ���i = n -1 ʱ�ǲ�k�����һ��Ԫ�أ���ʱȡ����temp��next
        ��Ӧ��ָ���κ�ֵ��Ӧ��ΪNULL�������ָ����һ���һ��Ԫ�ض�����������
    2. ������ԭԭ���Ĳ������ģ�壬�����104

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

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
                if (i != n - 1) {//��i���ǲ������һ��Ԫ��ʱ
                    temp->next = q.front();
                }
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};