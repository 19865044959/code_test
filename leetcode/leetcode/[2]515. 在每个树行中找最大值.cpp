#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：bfs层序遍历 + 队列

说明：

时间复杂度与空间复杂度：O(n) O(n)

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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int maxNum = INT_MIN; //在每次进行层序遍历前，将maxNum初始化
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                maxNum = max(maxNum, temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans.push_back(maxNum); //经过for循环后，maxNum的值已经求出
        }
        return ans;
    }
};

/**********************************************************************************************************
方法2：dfs层序遍历

说明：
    给每层进行标号，这个标号值作为函数的实参，跟着函数进行迭代
    第一层，标号为1，注意：第一层对应的数组下标为0而不是1，因此要减1

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 1);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int>& ans, int level) {
        //前序遍历前面要填充的东西
        if (root == NULL) return;
        if (level == ans.size() + 1) { //注意：每次都是先level增加，再ans的长度增加，因此始终level的值会在刚进入dfs时大ans长度1
            ans.push_back(root->val);
        }
        else {
            ans[level - 1] = max(ans[level - 1], root->val);
        }
        //这后面直接是模板，不需要变
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
};