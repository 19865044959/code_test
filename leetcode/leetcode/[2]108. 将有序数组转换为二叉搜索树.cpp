#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：前序遍历模板

说明：
    与题108作比较
    二叉搜索树进行中序遍历之后，输出节点会是一个升序排列的有序数组，因此将有序数组转换为二叉搜索树，
    是其反向操作，注意到中序遍历，其结构为： 
    左子树  根节点  右子树
    因此如果每次取中间元素作为根节点，递归左子树与右子树，那么返回的一定是棵平衡二叉搜索树

时间复杂度与空间复杂度：O(n) O(logn)

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* dfs(vector<int>& nums, int lower, int upper) {
        if (lower > upper) return NULL;
        int medium = lower + (upper - lower) / 2;
        TreeNode* root = new TreeNode(nums[medium]);
        root->left = dfs(nums, lower, medium - 1);
        root->right = dfs(nums, medium + 1, upper);
        return root;
    }
};