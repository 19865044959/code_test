#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**********************************************************************************************************
方法：从顶到底，前序遍历

说明：
    二叉树的深度已经会求了，那么只需要用两个递归，首先判断root的左右二叉树深度是否满足abs(depth1 - depth2) < 2，再以左、右子树为根节点继续递归
    从顶到底是设么意思：即先求出root是否满足平衡二叉树，然后在求root->left是否满足，再求root->right是否满足，而求depth的递归是从底到顶的！
时间复杂度与空间复杂度：
   时间复杂度：O(n*logn)
   空间复杂度：O(n)

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
        return 1 + max(depth(root->left), depth(root->right));
    }
};

/**********************************************************************************************************
方法：从底至顶 + 剪枝

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int leftTreeHeight = dfs(root->left);
        int rightTreeHeight = dfs(root->right);

        /*这个语句非常关键：
            如果某个根节点，其左子树或者右子树不满足平衡二叉树条件，那么它也肯定不是平衡二叉树；
            即使左子树与右子树是平衡二叉树，那么如果它们两个高度差大于2，那么根节点就不是平衡二叉树，整个树也就不是平衡二叉树了。
         */
        if (leftTreeHeight == -1 || rightTreeHeight == -1 || abs(leftTreeHeight - rightTreeHeight) > 1) return -1;

        return max(leftTreeHeight, rightTreeHeight) + 1; //注意看题目要求：平衡二叉树的意思是每个节点的左右子树'高度'绝对值不超过1，因此如果说根节点的左右子树均满足此关系，那么我们返回根节点的高度给上游，使得递归继续进行下去       
    }
};