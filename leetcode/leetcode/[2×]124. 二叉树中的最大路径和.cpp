#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：后序遍历

说明：
    以root作为根节点进行递归，最大值出现在三种情况：
    1. root->left, root-val, root->right 是最大值
    2. root递归上游, root->val, root->left 是较大值向上返回
    3. root递归上游, root->val, root->right 是较大值向上返回
    
    因此，我们既需要将 root->val + left + right记录起来，与maxSum进行比较
                     也需要将max(left, right) + root->val作为返回值，返回其递归上游

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
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0; //不能说recur里面有返回就不用了，因为这些函数可以进行拓展，如果换了个recur，里面又没有判断条件，那么就容易出问题
        dfs(root); //第一次见到一个有返回值但是在主函数中不需要用到的
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + left + right);
        return max(left, right) + root->val;
    }
};