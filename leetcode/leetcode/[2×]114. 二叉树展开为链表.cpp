#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：后序遍历

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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = NULL;
        last = root;
    }
private:
    TreeNode* last = NULL;
};