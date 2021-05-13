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
������ǰ�����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)
 
�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL) return true;
         if(p == NULL || q == NULL) return false;
         if(p->val != q->val) return false;
         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
     }
 };


 /**********************************************************************************************************
 �������������

 ˵����

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/
 class Solution {
 public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL) return true;
         if(p == NULL || q == NULL) return false;
         return isSameTree(p->left, q->left) && (p->val == q->val) && isSameTree(p->right, q->right);
     }
 };


 /**********************************************************************************************************
 �������������

 ˵����

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/
 class Solution {
 public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL) return true;
         if(p == NULL || q == NULL) return false;
         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val);
     }
 };
