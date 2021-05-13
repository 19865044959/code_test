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

/**********************************************************************************************************
方法：层序遍历

说明：
    一般的层序遍历从堆栈里面最后一个弹出的元素一定是最下层的最右元素，那么可以通过改变插入堆栈的元素顺序
    来变成最后一个弹出的元素一定是最下层的最左元素，达到目的

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
        return temp->val;
    }
};
