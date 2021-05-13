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
     �����ӽṹ��үү�����ӡ�����ģ�ͣ�����ֻ���������ֵ�һ����max(1үү+4����, 2����)
     ����ԭ��үү�Ѿ����������ӽڵ���͵������Ǯ�������ӽڵ㵱үү����ôԭ�������ӽڵ��ֵ��ֱ���ã��������ӽڵ��ֵ���أ�
     ����������Ȼ��������һ�飬�����Ҫһ��memo��¼����������memo��¼������hash��
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