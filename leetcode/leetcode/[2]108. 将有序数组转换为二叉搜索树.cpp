#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������ǰ�����ģ��

˵����
    ����108���Ƚ�
    ���������������������֮������ڵ����һ���������е��������飬��˽���������ת��Ϊ������������
    ���䷴�������ע�⵽�����������ṹΪ�� 
    ������  ���ڵ�  ������
    ������ÿ��ȡ�м�Ԫ����Ϊ���ڵ㣬�ݹ�������������������ô���ص�һ���ǿ�ƽ�����������

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(logn)

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* dfs(vector<int>& nums, int lower, int upper) {
        if (lower > upper) return NULL;
        int medium = lower + (upper - lower) / 2;
        TreeNode* root = new TreeNode(nums[medium]);
        root->left = dfs(nums, lower, medium - 1);
        root->right = dfs(nums, medium + 1, upper);
        return root;
    }
};