#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
bfs <=> ������� <=> ʹ�ö���
�������ģ�壺102�⣬���������ÿһ��Ľڵ�ֵ
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            vector<int> tempval;
            for (int i = 0; i < sz; i++) { //������Ϊ�˷ֲ㣬�������Ҫ�ֲ㣬����˵�Ͳ������һ����һ��vector<int>ȫд�꣬��ô�Ͳ���Ҫ�����ѭ��
                TreeNode* temp = que.front();
                que.pop();
                tempval.push_back(temp->val);
                if (temp->left) que.push(temp->left); //�����ǰ����зǿսڵ�ȫ��ѹ���ջ
                if (temp->right) que.push(temp->right);
                //��Ȼ��������������������Ҷ�ӽ�����滹��null��Ϊ������־����ô���Բο���ָoffer37��
            }
            res.push_back(tempval);
        }
        return res;
    }
};