#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1��bfs������� + ����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int maxNum = INT_MIN; //��ÿ�ν��в������ǰ����maxNum��ʼ��
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                maxNum = max(maxNum, temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans.push_back(maxNum); //����forѭ����maxNum��ֵ�Ѿ����
        }
        return ans;
    }
};

/**********************************************************************************************************
����2��dfs�������

˵����
    ��ÿ����б�ţ�������ֵ��Ϊ������ʵ�Σ����ź������е���
    ��һ�㣬���Ϊ1��ע�⣺��һ���Ӧ�������±�Ϊ0������1�����Ҫ��1

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
        //ǰ�����ǰ��Ҫ���Ķ���
        if (root == NULL) return;
        if (level == ans.size() + 1) { //ע�⣺ÿ�ζ�����level���ӣ���ans�ĳ������ӣ����ʼ��level��ֵ���ڸս���dfsʱ��ans����1
            ans.push_back(root->val);
        }
        else {
            ans[level - 1] = max(ans[level - 1], root->val);
        }
        //�����ֱ����ģ�壬����Ҫ��
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
};