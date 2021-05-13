#include<iostream>
#include<assert.h>
#include <vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<unordered_set>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//���ö���������
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         TreeNode* lower = p->val < q->val ? p : q;
//         TreeNode* upper = p->val > q->val ? p : q;
//         return dfs(root, lower, upper);
//     }
// private:
//     TreeNode* dfs(TreeNode* root, TreeNode* lower, TreeNode* upper){
//         if(root == NULL) return NULL;
//         if(lower->val <= root->val && upper->val >= root->val) return root;
//         else if(lower->val > root->val) return dfs(root->right, lower, upper);
//         else return dfs(root->left, lower, upper);
//     }
// };


//������Ƕ���������ô����ô�죿
/*
    ��p��q���������е㶼��¼��a��b������vector����
    ��set����¼a�е�����node
    �������b���ҵ�set������node����return
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp;
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        dfs(temp, a, root, p);
        temp.clear();
        dfs(temp, b, root, q);
        unordered_set<TreeNode*>Set;
        for (int i = 0; i < a.size(); i++) {
            Set.insert(a[i]);
        }
        for (int i = b.size() - 1; i >= 0; i--) {
            if (Set.find(b[i]) != Set.end()) {
                return b[i];
            }
        }
        return NULL;
    }

private:
    void dfs(vector<TreeNode*>& temp, vector<TreeNode*>& k, TreeNode* root, TreeNode* p) {
        if (root == NULL) return;
        temp.push_back(root);
        if (root == p) {
            k = temp;
            return;
        }
        else {
            dfs(temp, k, root->left, p);
            dfs(temp, k, root->right, p);
        }
        temp.pop_back();
    }
};
