#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：dfs(前序遍历模板)

说明：在题112的基础上加上一个temp用于储存路径通过节点即可

时间复杂度与空间复杂度：O(n) O(logn) - O(n)

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        dfs(root, temp, sum);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int>& temp, int val) {
        if (root == NULL) return;
        temp.push_back(root->val); //将root->val压入数组之中
        if (root->left == NULL && root->right == NULL) {
            if (root->val == val) {
                ans.push_back(temp); //把符合要求的数组储存到ans之中
            }
        }
        //前序遍历模板
        dfs(root->left, temp, val - root->val);
        dfs(root->right, temp, val - root->val);
        /*
            注意这里，这句话容易漏！一般来说，我们传递数组、二维数组都是通过引用传递，这样有助于时间、空间的节省
            这里当遍历完左子树、右子树之后，该节点要回溯给上游，上游不应该有这个节点出现，因此需要pop
            当然你可以把temp类型改成
            vector<int> temp：
            这时通过值的传递是值的拷贝，因此不需要pop，但是试过后会发现时间与空间花费大大增加！
        */
        temp.pop_back(); 
    }
};