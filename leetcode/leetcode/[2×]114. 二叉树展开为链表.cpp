#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
�������������

˵����

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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = NULL;
        last = root;
    }
private:
    TreeNode* last = NULL;
};