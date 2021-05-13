#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**********************************************************************************************************
�������Ե��򶥵�dfs

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)    O(n)
 
�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     bool isBalanced(TreeNode* root) {
         return dfs(root) != -1;
     }
 private:
     int dfs(TreeNode* root) {
         if (root == NULL) return 0;
         int left = dfs(root->left);
         if (left == -1) return -1;
         int right = dfs(root->right);
         if (right == -1) return -1;
         return abs(left - right) < 2 ? max(left, right) + 1 : -1;
     }
 };

 /**********************************************************************************************************
�������Զ����dfs

˵������Ϊ�����뵽��˼·�����жϸ��ڵ��Ƿ���������������������Ȳ� < 2���ٵݹ���ڵ������������ڵ�������
          ע�������õ�����һ��������ȵĴ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)    O(n)

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
         return max(depth(root->left), depth(root->right)) + 1;
     }
 };