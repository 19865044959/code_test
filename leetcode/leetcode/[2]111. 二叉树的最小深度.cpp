#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：前序遍历模板

说明：
    本以为就像104题一样，只需要一行代码搞定，即：
        return 1 + min(minDepth(root->left), minDepth(root->right));
    但是却是错的，测试用例[1,2]的深度是2不是1！这是为何？因为最小深度是从根节点到最近叶子结点的最短路径上的节点数之和
    那么[1,2]，节点1是根节点，节点2是叶子结点，由于必须包含叶子结点，因此是2而不是1

    那么我可以设计这样的算法：
        1. 当根节点有左子树与右子树时，这时候返回的是 1 + min(minDepth(root->left), minDepth(root->right)); //即长度最短的子树
        2. 当根节点左子树 || 右子树不存在时，这时返回的是1 + max(minDepth(root->left), minDepth(root->right)) //即返回的是不为空的子树的长度

时间复杂度与空间复杂度：O(n)  O(logn) - O(n)

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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return (root->left && root->right) == NULL ? 1 + max(minDepth(root->left), minDepth(root->right)) : 1 + min(minDepth(root->left), minDepth(root->right));
    }
};