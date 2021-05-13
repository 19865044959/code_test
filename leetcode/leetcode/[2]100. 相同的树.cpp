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
方法：前序遍历

说明：

时间复杂度与空间复杂度：O(n)  O(n)
 
涉及到的知识点：

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
 方法：中序遍历

 说明：

 时间复杂度与空间复杂度：O(n)  O(n)

 涉及到的知识点：

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
 方法：后序遍历

 说明：

 时间复杂度与空间复杂度：O(n)  O(n)

 涉及到的知识点：

 ***********************************************************************************************************/
 class Solution {
 public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL) return true;
         if(p == NULL || q == NULL) return false;
         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val);
     }
 };
