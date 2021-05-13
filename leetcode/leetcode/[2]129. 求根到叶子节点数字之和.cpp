#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：dfs

说明：
    三个dfs函数任君选择，其中dfs与dfs2是void返回值，用到了private的sum作为储存，dfs3更加简洁，
    连sum都不用了

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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        dfs2(0, root);
        return sum;
    }

private:
    int sum = 0;
    void dfs(int preVal, TreeNode* root) {
        preVal = 10 * preVal + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += preVal;
            return;
        }
        else if (root->left == NULL && root->right != NULL) {
            dfs(preVal, root->right);
        }
        else if (root->left != NULL && root->right == NULL) {
            dfs(preVal, root->left);
        }
        else {
            dfs(preVal, root->left);
            dfs(preVal, root->right);
        }
    }

    //注意：这里最初想的是把root == NULL作为储存于sum之中的条件，但是这样明显有问题！因为一个叶子结点值被储存的2次(因为左右子树均为NULL)
    void dfs2(int preVal, TreeNode* root) {
        if (root == NULL) return;
        preVal = 10 * preVal + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += preVal;
        }
        dfs2(preVal, root->left);
        dfs2(preVal, root->right);
    }

    int dfs3(int preVal, TreeNode* root) {
        if (root == NULL) return 0;
        preVal = 10 * preVal + root->val;
        if (root->left == NULL && root->right == NULL) {
            return preVal;
        }
        return dfs3(preVal, root->left) + dfs3(preVal, root->right);
    }
};