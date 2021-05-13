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
bfs <=> 层序遍历 <=> 使用队列
层序遍历模板：102题，输出二叉树每一层的节点值
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
            for (int i = 0; i < sz; i++) { //这里是为了分层，如果不需要分层，比如说就层序遍历一口气一个vector<int>全写完，那么就不需要加这个循环
                TreeNode* temp = que.front();
                que.pop();
                tempval.push_back(temp->val);
                if (temp->left) que.push(temp->left); //这里是把所有非空节点全部压入堆栈
                if (temp->right) que.push(temp->right);
                //当然完整二叉搜索树，所有叶子结点下面还有null作为结束标志，那么可以参考剑指offer37题
            }
            res.push_back(tempval);
        }
        return res;
    }
};