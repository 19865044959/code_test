#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
�������������

˵����
    ���ö�������������ǵ���������һ��������ɽ���
    1. �����Ƚ��������еĽڵ����������ȡ��ֵ������value����֮��
    2. ���Ŷ�value������в������ҵ����������ϵ���˳���Ԫ��a,b
    3. ���žͼ����ڶ������н�������������ҵ�Ԫ��a����ΪԪ��b���ҵ�Ԫ��b����ΪԪ��a����ɻָ�

ʱ�临�Ӷ���ռ临�Ӷȣ�
    O(n)
        1. �Ӷ�����������������õ��ڵ�ֵ�������浽�����У�O(n)
        2. ���������ҵ����������������Ԫ�أ�O(n)
        3. �Ӷ��������ҵ�������������ʣ���Ԫ�أ���������O(n)

    O(n)
        1. ����value�� O(n)
        2. һ������һ��ǰ�������O(n)

�漰����֪ʶ�㣺
    1. �����������������������
    2. �������У���������Ԫ�ػ�������׼����findTwoSwap
    3. ���������
***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*

 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        vector<int> a = findTwoSwap(value);
        recover(root, a[0], a[1]);
    }

private:
    vector<int> value;
    int cnt = 2;

    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        inOrder(root->left);
        value.push_back(root->val);
        inOrder(root->right);
    }

    vector<int> findTwoSwap(vector<int>& value) {
        int n = value.size();
        int x = -1, y = -1;
        for (int i = 0; i < n - 1; i++) {
            if (value[i + 1] < value[i]) {
                y = value[i + 1];
                if (x == -1) x = value[i];
                else break;
            }
        }
        return { x, y };
    }

    void recover(TreeNode* root, int x, int y) {
        if (root == NULL) return;
        //����ǰ�����򡢺������������ν������
        if (root->val == x || root->val == y) {
            root->val = root -> val == x ? y : x; //���root->val == x����ô�Ҹ�����y�����==y���Ҹ�����x
            cnt--;
        }
        if (!cnt) return;
        recover(root->left, x, y);
        recover(root->right, x, y);
    }
};