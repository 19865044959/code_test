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

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：
    1. 前序遍历： root | 左子树 | 右子树
       中序遍历： 左子树 | root | 右子树
       后序遍历： 左子树 | 右子树 | root
    2. 传递参数：preorder inorder preorder_left preorder_right inorder_left inorder_right
    3. 前序遍历第一个元素就是根节点对应元素，根据该元素，找到对应中序遍历该元素对应的下标，
    求解得到左子树长度，从而确定前序遍历左子树、右子树的下标，递归即可

***********************************************************************************************************/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        //构造哈希表，一次构造，以后寻找中序遍历的根节点下标时就不用再花O(n)时间，而是只用O(1)时间即可
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildBST(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int, int> index; //记录中序遍历值对应的索引

    //输入：前序遍历数组、中序遍历数组、前序遍历数组下标范围、中序遍历数组下标范围
    TreeNode* buildBST(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {

        //返回条件，如果不加这一句，堆栈溢出
        if (preorder_left > preorder_right || inorder_left > inorder_right) return NULL;

        int preorder_root = preorder_left; //前序遍历的根节点下标就是第一个下标
        int inorder_root = index[preorder[preorder_root]]; //利用哈希表寻找中序遍历根节点对应下标
        int left_tree_len = inorder_root - inorder_left; //求解出左子树长度，为下面的下表运算做准备

        TreeNode* root = new TreeNode(preorder[preorder_root]); //构造新根节点，记为root

        //递归，扩展root的左子树与右子树，最重要的下标范围请自己列方程等方法求出
        root->left = buildBST(preorder, inorder, preorder_left + 1, preorder_left + left_tree_len, inorder_left, inorder_root - 1);
        root->right = buildBST(preorder, inorder, preorder_left + left_tree_len + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;//返回根节点
    }
};