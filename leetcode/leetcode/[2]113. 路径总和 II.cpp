#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������dfs(ǰ�����ģ��)

˵��������112�Ļ����ϼ���һ��temp���ڴ���·��ͨ���ڵ㼴��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(logn) - O(n)

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        dfs(root, temp, sum);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int>& temp, int val) {
        if (root == NULL) return;
        temp.push_back(root->val); //��root->valѹ������֮��
        if (root->left == NULL && root->right == NULL) {
            if (root->val == val) {
                ans.push_back(temp); //�ѷ���Ҫ������鴢�浽ans֮��
            }
        }
        //ǰ�����ģ��
        dfs(root->left, temp, val - root->val);
        dfs(root->right, temp, val - root->val);
        /*
            ע�������仰����©��һ����˵�����Ǵ������顢��ά���鶼��ͨ�����ô��ݣ�����������ʱ�䡢�ռ�Ľ�ʡ
            ���ﵱ��������������������֮�󣬸ýڵ�Ҫ���ݸ����Σ����β�Ӧ��������ڵ���֣������Ҫpop
            ��Ȼ����԰�temp���͸ĳ�
            vector<int> temp��
            ��ʱͨ��ֵ�Ĵ�����ֵ�Ŀ�������˲���Ҫpop�������Թ���ᷢ��ʱ����ռ仨�Ѵ�����ӣ�
        */
        temp.pop_back(); 
    }
};