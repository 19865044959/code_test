#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：前序遍历模板

说明：

时间复杂度与空间复杂度：O(n)  O(n)

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        if (root == NULL) return ans;
        binaryTreePaths(root, ans, path);
        return ans;
    }
    //函数重载，这里我不知道为何，相比于再写一个dfs函数，重载后从8ms降低到了0ms，难道说函数重载会比新写一个函数效率要高?
    void binaryTreePaths(TreeNode* root, vector<string>& ans, string path) {
        if (root == NULL) return;
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        binaryTreePaths(root->left, ans, path + "->");
        binaryTreePaths(root->right, ans, path + "->");
    }
};