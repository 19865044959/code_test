#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������dfs

˵����
	1. �ж�һ���������ǲ��ǶԳƣ���ô��Ҫ�Ӹ��ڵ㿪ʼ���ж���������Ԫ���Ƿ����
	2. ���Խ���һ��������test�ж��Ƿ���ȣ�test���������������������
		���ȿ�ָ������������������ָ���Ƿ��Ϊ�գ������Ϊ�գ���ôһ���ǶԳƵģ�ֻ�и��ڵ����һ���Գƣ�
		���ֻ��һ��ָ��Ϊ�գ���һ����Ϊ�գ���һ���ǲ��Գ�
		�������Ϊ�գ���ô�ٿ�����ָ��ָ��ڵ��ֵ�Ƿ���ȣ�����ȣ�һ�����Գ�
		���ֵ��ȣ���ô���������ڵ�Ϊ���ڵ㣬�ظ����������������ж�

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
    bool isSymmetric(TreeNode* root) {
        return test(root, root);
    }
private:
    bool test(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL) return false;
        return (t1->val == t2->val) && test(t1->left, t2->right) && test(t1->right, t2->left);
    }
};