#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

/**********************************************************************************************************
方法：详见105题

说明：

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        for (int i = 0; i < n; i++) {
            a[inorder[i]] = i;
        }
        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }
private:
    unordered_map<int, int> a;
    int n;
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int poStart, int poEnd) {
        if (inStart > inEnd || poStart > poEnd) return NULL;
        int rootVal = postorder[poEnd];
        int inIndex = a[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = dfs(inorder, postorder, inStart, inIndex - 1, poStart, poStart + inIndex - inStart - 1);
        root->right = dfs(inorder, postorder, inIndex + 1, inEnd, poStart + inIndex - inStart, poEnd - 1);
        /*
        root->left = dfs(inorder, postorder, inStart, inIndex - 1, poStart, inIndex - 1);
        root->right = dfs(inorder, postorder, inIndex + 1, inEnd, inIndex, poEnd - 1);
        想想上面这个为什么出错
        */
        return root;
    }
};