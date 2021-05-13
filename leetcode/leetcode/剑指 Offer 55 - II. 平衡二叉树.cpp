#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**********************************************************************************************************
方法：自底向顶的dfs

说明：

时间复杂度与空间复杂度：O(n)    O(n)
 
涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     bool isBalanced(TreeNode* root) {
         return dfs(root) != -1;
     }
 private:
     int dfs(TreeNode* root) {
         if (root == NULL) return 0;
         int left = dfs(root->left);
         if (left == -1) return -1;
         int right = dfs(root->right);
         if (right == -1) return -1;
         return abs(left - right) < 2 ? max(left, right) + 1 : -1;
     }
 };

 /**********************************************************************************************************
方法：自顶向底dfs

说明：较为容易想到的思路：先判断根节点是否满足左子树右子树的深度差 < 2，再递归根节点左子树、根节点右子树
          注意这里用到了求一棵树的深度的代码

时间复杂度与空间复杂度：O(nlogn)    O(n)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     bool isBalanced(TreeNode* root) {
         if (root == NULL) return true;
         return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
     }
 private:
     int depth(TreeNode* root) {
         if (root == NULL) return 0;
         return max(depth(root->left), depth(root->right)) + 1;
     }
 };