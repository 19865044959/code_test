#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������ǰ�����ģ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        if (root == NULL) return ans;
        binaryTreePaths(root, ans, path);
        return ans;
    }
    //�������أ������Ҳ�֪��Ϊ�Σ��������дһ��dfs���������غ��8ms���͵���0ms���ѵ�˵�������ػ����дһ������Ч��Ҫ��?
    void binaryTreePaths(TreeNode* root, vector<string>& ans, string path) {
        if (root == NULL) return;
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        binaryTreePaths(root->left, ans, path + "->");
        binaryTreePaths(root->right, ans, path + "->");
    }
};