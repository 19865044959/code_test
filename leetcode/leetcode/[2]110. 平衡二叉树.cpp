#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**********************************************************************************************************
�������Ӷ����ף�ǰ�����

˵����
    ������������Ѿ������ˣ���ôֻ��Ҫ�������ݹ飬�����ж�root�����Ҷ���������Ƿ�����abs(depth1 - depth2) < 2��������������Ϊ���ڵ�����ݹ�
    �Ӷ���������ô��˼���������root�Ƿ�����ƽ���������Ȼ������root->left�Ƿ����㣬����root->right�Ƿ����㣬����depth�ĵݹ��Ǵӵ׵����ģ�
ʱ�临�Ӷ���ռ临�Ӷȣ�
   ʱ�临�Ӷȣ�O(n*logn)
   �ռ临�Ӷȣ�O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};

/**********************************************************************************************************
�������ӵ����� + ��֦

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int leftTreeHeight = dfs(root->left);
        int rightTreeHeight = dfs(root->right);

        /*������ǳ��ؼ���
            ���ĳ�����ڵ㣬������������������������ƽ���������������ô��Ҳ�϶�����ƽ���������
            ��ʹ����������������ƽ�����������ô������������߶Ȳ����2����ô���ڵ�Ͳ���ƽ���������������Ҳ�Ͳ���ƽ��������ˡ�
         */
        if (leftTreeHeight == -1 || rightTreeHeight == -1 || abs(leftTreeHeight - rightTreeHeight) > 1) return -1;

        return max(leftTreeHeight, rightTreeHeight) + 1; //ע�⿴��ĿҪ��ƽ�����������˼��ÿ���ڵ����������'�߶�'����ֵ������1��������˵���ڵ����������������˹�ϵ����ô���Ƿ��ظ��ڵ�ĸ߶ȸ����Σ�ʹ�õݹ����������ȥ       
    }
};