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
�������������

˵����
    һ��Ĳ�������Ӷ�ջ�������һ��������Ԫ��һ�������²������Ԫ�أ���ô����ͨ���ı�����ջ��Ԫ��˳��
    ��������һ��������Ԫ��һ�������²������Ԫ�أ��ﵽĿ��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
