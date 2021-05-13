#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>

using namespace std;

/**********************************************************************************************************
������ʵ����ǰ�����ģ��

˵����
    1. ǰ������� ���ڵ�  ������  ������
        ��������� ������  ���ڵ�  ������
    2. ����ǰ������ĵ�һ��Ԫ���Ǹ��ڵ����ʣ�������������ĸ��ڵ㽫����ֳ������������������󲿷�
        �������ǰ���������������ĸ��ڵ㡢������������������ͬ������������ڵ�ֵ���������ڵ�ֵ��������Χ�����������ڵ�ֵ��������Χ��
    3. ����ǰ��������ݹ�����������������������ɶ�������ʵ��
    4. ����Ҫ���������������������������������Χ

ʱ�临�Ӷ���ռ临�Ӷȣ�
    O(n)����ʾ���ƶ���������Ҫ����n�����ڵ�
    O(n)��
        1. ��ϣ��O(n)�ռ�
        2. ���ش���ҪO(n)�ռ�
        3. �����������Ҫh�ռ����ڵݹ�ʱջ�ռ䣬����h��ʾ�������߶�

�漰����֪ʶ�㣺
    1. ǰ�����ģ��
    2. ����ǰ�������������������������ʵ����3������֪��2���Ϳ��Է����������

***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        //�����ϣ��һ�ι��죬�Ժ�Ѱ����������ĸ��ڵ��±�ʱ�Ͳ����ٻ�O(n)ʱ�䣬����ֻ��O(1)ʱ�伴��
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildBST(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int, int> index; //��¼�������ֵ��Ӧ������

    //���룺ǰ��������顢����������顢ǰ����������±귶Χ��������������±귶Χ
    TreeNode* buildBST(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        
        //�������������������һ�䣬��ջ���
        if (preorder_left > preorder_right || inorder_left > inorder_right) return NULL;

        int preorder_root = preorder_left; //ǰ������ĸ��ڵ��±���ǵ�һ���±�
        int inorder_root = index[preorder[preorder_root]]; //���ù�ϣ��Ѱ������������ڵ��Ӧ�±�
        int left_tree_len = inorder_root - inorder_left; //�������������ȣ�Ϊ������±�������׼��

        TreeNode* root = new TreeNode(preorder[preorder_root]); //�����¸��ڵ㣬��Ϊroot

        //�ݹ飬��չroot����������������������Ҫ���±귶Χ���Լ��з��̵ȷ������
        root->left = buildBST(preorder, inorder, preorder_left + 1, preorder_left + left_tree_len, inorder_left, inorder_root - 1);
        root->right = buildBST(preorder, inorder, preorder_left + left_tree_len + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;//���ظ��ڵ�
    }
};