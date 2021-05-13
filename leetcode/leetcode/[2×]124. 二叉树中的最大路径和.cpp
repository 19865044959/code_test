#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
�������������

˵����
    ��root��Ϊ���ڵ���еݹ飬���ֵ���������������
    1. root->left, root-val, root->right �����ֵ
    2. root�ݹ�����, root->val, root->left �ǽϴ�ֵ���Ϸ���
    3. root�ݹ�����, root->val, root->right �ǽϴ�ֵ���Ϸ���
    
    ��ˣ����Ǽ���Ҫ�� root->val + left + right��¼��������maxSum���бȽ�
                     Ҳ��Ҫ��max(left, right) + root->val��Ϊ����ֵ��������ݹ�����

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
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0; //����˵recur�����з��ؾͲ����ˣ���Ϊ��Щ�������Խ�����չ��������˸�recur��������û���ж���������ô�����׳�����
        dfs(root); //��һ�μ���һ���з���ֵ�������������в���Ҫ�õ���
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + left + right);
        return max(left, right) + root->val;
    }
};