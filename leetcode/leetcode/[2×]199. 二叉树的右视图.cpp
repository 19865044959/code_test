#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

/**********************************************************************************************************
方法：队列 + bfs （层序遍历）

说明：参考104题利用中序遍历求深度，把求深度改成push_back最后元素至ans里面即可

时间复杂度与空间复杂度：O(n) O(n)

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> q;
        vector<int> ans;
        TreeNode* p;

        q.push_back(root);

        while (!q.empty()) {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                p = q.front();
                q.pop_front();
                if (p->left) q.push_back(p->left);
                if (p->right) q.push_back(p->right);
            }
            //得到每一层最后一个元素对应的指针
            ans.push_back(p->val);
        }
        return ans;
    }
};

/**********************************************************************************************************
方法：dfs

说明：按照「根结点 -> 右子树 -> 左子树」的顺序访问， 就可以保证每层都是最先访问最右边的节点的。
          (与先序遍历 「根结点 -> 左子树 -> 右子树」 正好相反，先序遍历每层最先访问的是最左边的节点）

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0); // 从根节点开始访问，根节点深度是0
        return ans;
    }

private:
    vector<int> ans;
    void dfs(TreeNode* p, int depth) {
        if (!p) return;
        // 先访问 当前节点，再递归地访问 右子树 和 左子树。
        if (depth == ans.size()) {  // 如果当前节点所在深度还没有出现在res里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入res中。
                                                 // 这里的depth相当于下标，ans.size()是长度，那么一个数组，它的最大下标与长度之间总会满足：indexMax = length - 1，如果相等了，说明最大下表还未插入
            ans.push_back(p->val);
        }
        depth++;
        dfs(p->right, depth);
        dfs(p->left, depth);
    }
};