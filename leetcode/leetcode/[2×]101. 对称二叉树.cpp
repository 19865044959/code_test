#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：dfs

说明：
	1. 判断一个二叉树是不是对称，那么就要从根节点开始：判断左右子树元素是否相等
	2. 可以建立一个函数，test判断是否相等，test输入的是左子树与右子树
		首先看指向左子树与右子树的指针是否均为空，如果均为空，那么一定是对称的（只有根节点的树一定对称）
		如果只有一个指针为空，另一个不为空，那一定是不对称
		如果均不为空，那么再看两个指针指向节点的值是否相等，不相等，一定不对称
		如果值相等，那么以这两个节点为根节点，重复左子树与右子树判断

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
    bool isSymmetric(TreeNode* root) {
        return test(root, root);
    }
private:
    bool test(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL) return false;
        return (t1->val == t2->val) && test(t1->left, t2->right) && test(t1->right, t2->left);
    }
};