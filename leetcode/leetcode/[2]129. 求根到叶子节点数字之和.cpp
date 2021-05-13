#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������dfs

˵����
    ����dfs�����ξ�ѡ������dfs��dfs2��void����ֵ���õ���private��sum��Ϊ���棬dfs3���Ӽ�࣬
    ��sum��������

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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        dfs2(0, root);
        return sum;
    }

private:
    int sum = 0;
    void dfs(int preVal, TreeNode* root) {
        preVal = 10 * preVal + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += preVal;
            return;
        }
        else if (root->left == NULL && root->right != NULL) {
            dfs(preVal, root->right);
        }
        else if (root->left != NULL && root->right == NULL) {
            dfs(preVal, root->left);
        }
        else {
            dfs(preVal, root->left);
            dfs(preVal, root->right);
        }
    }

    //ע�⣺�����������ǰ�root == NULL��Ϊ������sum֮�е������������������������⣡��Ϊһ��Ҷ�ӽ��ֵ�������2��(��Ϊ����������ΪNULL)
    void dfs2(int preVal, TreeNode* root) {
        if (root == NULL) return;
        preVal = 10 * preVal + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += preVal;
        }
        dfs2(preVal, root->left);
        dfs2(preVal, root->right);
    }

    int dfs3(int preVal, TreeNode* root) {
        if (root == NULL) return 0;
        preVal = 10 * preVal + root->val;
        if (root->left == NULL && root->right == NULL) {
            return preVal;
        }
        return dfs3(preVal, root->left) + dfs3(preVal, root->right);
    }
};