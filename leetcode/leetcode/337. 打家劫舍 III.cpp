#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

   /*
     最优子结构：爷爷、孩子、孙子模型，最优只能是这两种的一个：max(1爷爷+4孙子, 2孩子)
     慢的原因：爷爷已经计算了孙子节点能偷最多多少钱，当孩子节点当爷爷，那么原来的孙子节点的值能直接用，当做孩子节点的值返回，
     但是我们仍然重新算了一遍，因此需要一个memo记录，而二叉树memo记录方法：hash表
  */
 class Solution {
 public:
     int rob(TreeNode* root) {
         if(root == NULL) return 0;
         int money = root->val;
         if(root->left){
             money += rob(root->left->left) + rob(root->left->right);
         }
         if(root->right){
             money += rob(root->right->left) + rob(root->right->right);
         }
         return max(money, rob(root->left) + rob(root->right));
     }
 };


 //memo
 class Solution {
 public:
     int rob(TreeNode* root) {
         if(root == NULL) return 0;
         if(hash.find(root) != hash.end()) return hash[root];
         int money = root->val;
         if(root->left){
             money += rob(root->left->left) + rob(root->left->right); 
         }
         if(root->right){
             money += rob(root->right->left) + rob(root->right->right);
         }
         int maxMoney = max(money, rob(root->left) + rob(root->right));
         hash[root] = maxMoney;
         return maxMoney;
     }

 private:
     unordered_map<TreeNode*, int>hash;
 };

 //dp
 struct SubtreeStatus {
     int selected;
     int notSelected;
 };

 class Solution {
 public:
     SubtreeStatus dfs(TreeNode* node) {
         if (!node) {
             return { 0, 0 };
         }
         auto l = dfs(node->left);
         auto r = dfs(node->right);
         int selected = node->val + l.notSelected + r.notSelected;
         int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
         return { selected, notSelected };
     }

     int rob(TreeNode* root) {
         auto rootStatus = dfs(root);
         return max(rootStatus.selected, rootStatus.notSelected);
     }
 };