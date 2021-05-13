#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：中序遍历

说明：
    利用二叉树中序遍历是递增数列这一性质来完成解题
    1. 首先先将二叉树中的节点中序遍历，取出值，放入value数组之中
    2. 接着对value数组进行操作，找到两个不符合递增顺序的元素a,b
    3. 接着就继续在二叉树中进行中序遍历，找到元素a，换为元素b；找到元素b，换为元素a，完成恢复

时间复杂度与空间复杂度：
    O(n)
        1. 从二叉树进行中序遍历得到节点值，并储存到数组中：O(n)
        2. 从数组中找到两个不满足升序的元素：O(n)
        3. 从二叉树中找到这两个不满足剩余的元素，并互换：O(n)

    O(n)
        1. 数组value： O(n)
        2. 一次中序、一次前序遍历：O(n)

涉及到的知识点：
    1. 二叉树中序遍历，升序排列
    2. 有序数列，仅有两个元素互换，标准代码findTwoSwap
    3. 二叉树框架
***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*

 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        vector<int> a = findTwoSwap(value);
        recover(root, a[0], a[1]);
    }

private:
    vector<int> value;
    int cnt = 2;

    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        inOrder(root->left);
        value.push_back(root->val);
        inOrder(root->right);
    }

    vector<int> findTwoSwap(vector<int>& value) {
        int n = value.size();
        int x = -1, y = -1;
        for (int i = 0; i < n - 1; i++) {
            if (value[i + 1] < value[i]) {
                y = value[i + 1];
                if (x == -1) x = value[i];
                else break;
            }
        }
        return { x, y };
    }

    void recover(TreeNode* root, int x, int y) {
        if (root == NULL) return;
        //这里前序、中序、后序遍历均无所谓，都可
        if (root->val == x || root->val == y) {
            root->val = root -> val == x ? y : x; //如果root->val == x，那么我赋给它y，如果==y，我赋给它x
            cnt--;
        }
        if (!cnt) return;
        recover(root->left, x, y);
        recover(root->right, x, y);
    }
};