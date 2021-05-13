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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**********************************************************************************************************
方法：层序遍历

说明：
    1. 利用层序遍历求出每个节点的到根节点的路径图，以string表示，其中0代表左子树，1代表右子树
    2. 从中寻找到二叉树根节点到各个叶子结点的路径图
    3. 挑出两个叶子结点，计算其LCA（最近公共祖先），根据其公共祖先来计算它们的距离
    4. 当距离<=指定距离时，ans++

时间复杂度与空间复杂度：O(n^2*depth), O(n^2)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> q;
        vector<string> s;
        q.push_back(root);
        s.push_back("");
        for (int i = 0; i < q.size(); i++) { //注意这里是q.size()而不是将int n = q.size()，是因为每次push_back都会使得q.size()动态发生改变，与一般不存a.end()一个道理
            TreeNode* nodeptr = q[i];
            string nodestr = s[i];
            if (nodeptr->left != NULL) {
                q.push_back(nodeptr->left);
                s.push_back(nodestr + "0");
            }
            if (nodeptr->right != NULL) {
                q.push_back(nodeptr->right);
                s.push_back(nodestr + "1");
            }
        }
        int ans = 0;
        for (int i = 0; i < q.size() - 1; i++) {
            for (int j = i + 1; j < q.size(); j++) {
                if (q[i]->left != NULL || q[i]->right != NULL || q[j]->left != NULL || q[j]->right != NULL) continue; //这句话的意思是找到两个叶子结点，因为叶子节点的子女均为空节点
                int size = s[i].size() + s[j].size();
                for (int k = 0; k < s[i].size() && k < s[j].size(); k++) {
                    if (s[i][k] == s[j][k]) size -= 2; //如果存在公共路径（公有祖先），那么长度数-2,
                    else break; //这句话非常精髓也非常易忘！祖先是第一个路径字符开始全都要相同，如果有一个不相同，说明上一个就是LCA，如果不加这句话，那么0011与0111的共同祖先数
                                      //就从1个'0'变成了3个： '0'、'1'、'1'，导致计算错误
                }
                if (size <= distance) ans++;
            }
        }
        return ans;
    }
};
