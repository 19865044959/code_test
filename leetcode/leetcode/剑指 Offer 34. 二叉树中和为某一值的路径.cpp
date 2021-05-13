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
方法：前序遍历 + 记录路径

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        recur(root, sum);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> temp;
    void recur(TreeNode* root, int sum) {
        if (root == NULL) return;
        temp.push_back(root->val);
        sum -= root->val;
        if (root->left == NULL && root->right == NULL && sum == 0) {
            res.push_back(temp);
        }
        recur(root->left, sum);
        recur(root->right, sum);
        sum += root->val; //回溯
        temp.pop_back();  //回溯
        /*
            注：如果传值，即传的是拷贝，那么不需要回溯，但是一旦递归层数变多，新开辟的变量也会增多，会极其占用内存空间，对比如下代码：
        */
    }
};

//未用回溯，占用空间
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> dir;
        vector<vector<int>>ans;
        dfs(root, ans, dir, sum);
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int> dir, int sum) {
        if (root == NULL) return;
        dir.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                ans.push_back(dir);
            }
        }
        dfs(root->left, ans, dir, sum - root->val); //每次dfs，都会新开辟一个vector<int> dir与int sum
        dfs(root->right, ans, dir, sum - root->val);
    }
};