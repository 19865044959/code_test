#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������ǰ�����ģ��

˵����
    ����Ϊ����104��һ����ֻ��Ҫһ�д���㶨������
        return 1 + min(minDepth(root->left), minDepth(root->right));
    ����ȴ�Ǵ�ģ���������[1,2]�������2����1������Ϊ�Σ���Ϊ��С����ǴӸ��ڵ㵽���Ҷ�ӽ������·���ϵĽڵ���֮��
    ��ô[1,2]���ڵ�1�Ǹ��ڵ㣬�ڵ�2��Ҷ�ӽ�㣬���ڱ������Ҷ�ӽ�㣬�����2������1

    ��ô�ҿ�������������㷨��
        1. �����ڵ�����������������ʱ����ʱ�򷵻ص��� 1 + min(minDepth(root->left), minDepth(root->right)); //��������̵�����
        2. �����ڵ������� || ������������ʱ����ʱ���ص���1 + max(minDepth(root->left), minDepth(root->right)) //�����ص��ǲ�Ϊ�յ������ĳ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(logn) - O(n)

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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return (root->left && root->right) == NULL ? 1 + max(minDepth(root->left), minDepth(root->right)) : 1 + min(minDepth(root->left), minDepth(root->right));
    }
};