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
������ǰ����� + ��¼·��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
        sum += root->val; //����
        temp.pop_back();  //����
        /*
            ע�������ֵ���������ǿ�������ô����Ҫ���ݣ�����һ���ݹ������࣬�¿��ٵı���Ҳ�����࣬�Ἣ��ռ���ڴ�ռ䣬�Ա����´��룺
        */
    }
};

//δ�û��ݣ�ռ�ÿռ�
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
        dfs(root->left, ans, dir, sum - root->val); //ÿ��dfs�������¿���һ��vector<int> dir��int sum
        dfs(root->right, ans, dir, sum - root->val);
    }
};