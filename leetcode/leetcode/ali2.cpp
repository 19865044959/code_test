/*
    建树 + 新概念（最长支长度）
*/
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

int res = 0;
int k = 0;

//建树
void dfs(TreeNode* root, int val) {
    if (root == NULL) return;
    if (root->val > val) {
        if (root->left == NULL) {
            root->left = new TreeNode(val);
            return;
        }
        else {
            dfs(root->left, val);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = new TreeNode(val);
            return;
        }
        else {
            dfs(root->right, val);
        }
    }
}


void recur(TreeNode* root) {
    if (root == NULL) return;
    TreeNode* ptr = root;
    int cnt = -1;
    while (ptr) {
        cnt++;
        ptr = ptr->left;
    }
    if (cnt > res) {
        res = cnt;
        k = 1;
    }
    else if (cnt == res) {
        k++;
    }

    cnt = -1;
    ptr = root;
    while (ptr) {
        cnt++;
        ptr = ptr->right;
    }
    if (cnt > res) {
        res = cnt;
        k = 1;
    }
    else if (cnt == res) {
        k++;
    }
    recur(root->left);
    recur(root->right);
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> nodes(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i];
        }
        TreeNode* root = new TreeNode(nodes[0]);
        for (int i = 1; i < n; i++) {
            dfs(root, nodes[i]);
        }
        recur(root);
        cout << res << " " << k << endl;
    }
    return 0;
}