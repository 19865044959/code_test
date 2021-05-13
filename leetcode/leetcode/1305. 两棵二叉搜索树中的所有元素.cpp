#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������������� + ������������ϳ�Ϊһ���������鷽��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n + m)   O(n + m)

�漰����֪ʶ�㣺

***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2, ans;
        dfs(root1, ans1);
        dfs(root2, ans2);
        int n = ans1.size();
        int m = ans2.size();
        int i, j;
        for (i = 0, j = 0; i < n && j < m;) {
            if (ans1[i] > ans2[j]) {
                ans.push_back(ans2[j]);
                j++;
            }
            else {
                ans.push_back(ans1[i]);
                i++;
            }
        }
        if (i == n) {
            for (; j < m; j++) {
                ans.push_back(ans2[j]);
            }
        }
        else {
            for (; i < n; i++) {
                ans.push_back(ans1[i]);
            }
        }
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
};