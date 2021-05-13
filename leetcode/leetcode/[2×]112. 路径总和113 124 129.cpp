#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

/**********************************************************************************************************
方法：dfs(前序遍历模板)

说明：

时间复杂度与空间复杂度：O(n) O(logn) - O(n)

涉及到的知识点：

***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
private:
    bool dfs(TreeNode* root, int val) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            return root->val == val;
        }
        return dfs(root->left, val - root->val) || dfs(root->right, val - root->val);
    }
};

/**********************************************************************************************************
方法：bfs

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        deque<TreeNode*> que_node;
        deque<int> que_val;
        que_node.push_back(root);
        que_val.push_back(root->val);
        while (que_node.size()) {
            TreeNode* temp_node = que_node.front();
            int temp_val = que_val.front();
            que_node.pop_front();
            que_val.pop_front();
            if (temp_node->left == NULL && temp_node->right == NULL) {
                if (temp_val == sum) return true;
            }
            if (temp_node->right != NULL) {
                que_node.push_back(temp_node->right);
                que_val.push_back(temp_val + temp_node->right->val);
            }
            if (temp_node->left != NULL) {
                que_node.push_back(temp_node->left);
                que_val.push_back(temp_val + temp_node->left->val);
            }
        }
        return false;
    }
};