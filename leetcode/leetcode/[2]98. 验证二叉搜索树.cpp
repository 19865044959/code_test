#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：dfs + 二叉搜索树性质 + 递归

说明：

时间复杂度与空间复杂度： O(n)  O(logn) - O(n)

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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool dfs(TreeNode* ptr, long long lower, long long upper) {
        if (ptr == NULL) return true;
        if (ptr->val >= upper || ptr->val <= lower) return false;
        return dfs(ptr->left, lower, ptr->val) && dfs(ptr->right, ptr->val, upper);
    }
};

/**********************************************************************************************************
方法：利用二叉树中序遍历时，输出一定是升序数列这一性质

说明：好像还是不太了解

时间复杂度与空间复杂度： O(n)  O(logn) - O(n)

涉及到的知识点：
    1. 中序遍历：先左子树，再根节点，最后右子树

***********************************************************************************************************/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        // 1. 访问左子树，如果左子树里面存在不满足中序遍历的，那么根节点应该也不满足中序遍历，也不是二叉搜索树了
        if (!isValidBST(root->left)) {
            return false;
        }
        // 2. 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历
        if (root->val <= pre) {
            return false;
        }
        pre = root->val; //由于我们下面要访问右子树，因此需要将pre更新成根节点的值
        // 3. 访问右子树 
        return isValidBST(root->right);
    }
private:
    long long pre = LLONG_MIN;
};