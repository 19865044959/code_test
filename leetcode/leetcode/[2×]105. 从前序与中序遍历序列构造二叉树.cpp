#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>

using namespace std;

/**********************************************************************************************************
方法：实质是前序遍历模板

说明：
    1. 前序遍历： 根节点  左子树  右子树
        中序遍历： 左子树  根节点  右子树
    2. 利用前序遍历的第一个元素是根节点性质，利用中序遍历的根节点将数组分成左子树与右子树两大部分
        最后利用前序遍历、中序遍历的根节点、左子树、右子树均相同，可以求出根节点值、左子树节点值（索引范围）、右子树节点值（索引范围）
    3. 利用前序遍历，递归左子树、右子树，最终完成二叉树的实现
    4. 最主要的任务是求出左子树、右子树的索引范围

时间复杂度与空间复杂度：
    O(n)：表示绘制二叉树，需要绘制n个根节点
    O(n)：
        1. 哈希表O(n)空间
        2. 返回答案需要O(n)空间
        3. 构造二叉树需要h空间用于递归时栈空间，其中h表示二叉树高度

涉及到的知识点：
    1. 前序遍历模板
    2. 利用前序遍历与中序遍历反求二叉树（实际上3个任意知道2个就可以反求二叉树）

***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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