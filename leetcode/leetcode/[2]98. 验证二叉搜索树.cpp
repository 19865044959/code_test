#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������dfs + �������������� + �ݹ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ� O(n)  O(logn) - O(n)

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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool dfs(TreeNode* ptr, long long lower, long long upper) {
        if (ptr == NULL) return true;
        if (ptr->val >= upper || ptr->val <= lower) return false;
        return dfs(ptr->left, lower, ptr->val) && dfs(ptr->right, ptr->val, upper);
    }
};

/**********************************************************************************************************
���������ö������������ʱ�����һ��������������һ����

˵���������ǲ�̫�˽�

ʱ�临�Ӷ���ռ临�Ӷȣ� O(n)  O(logn) - O(n)

�漰����֪ʶ�㣺
    1. ��������������������ٸ��ڵ㣬���������

***********************************************************************************************************/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        // 1. ���������������������������ڲ�������������ģ���ô���ڵ�Ӧ��Ҳ���������������Ҳ���Ƕ�����������
        if (!isValidBST(root->left)) {
            return false;
        }
        // 2. ���ʵ�ǰ�ڵ㣺�����ǰ�ڵ�С�ڵ������������ǰһ���ڵ㣬˵��������BST������ false�������������
        if (root->val <= pre) {
            return false;
        }
        pre = root->val; //������������Ҫ�����������������Ҫ��pre���³ɸ��ڵ��ֵ
        // 3. ���������� 
        return isValidBST(root->right);
    }
private:
    long long pre = LLONG_MIN;
};