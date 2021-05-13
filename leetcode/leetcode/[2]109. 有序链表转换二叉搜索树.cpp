#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������dfs + ������ת��Ϊ����

˵�������108��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
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

/**********************************************************************************************************
����������ָ��

˵�������108��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n * logn)  O(logn)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        //������������һ���ڵ㲻���������ǲ�֪���ģ�����������������ʱ�䣬���ֱ�����������һ���ڵ����һ���ڵ�
        //��NULL��Ϊ�߽�������������ҿ���[left, right)�������ͱ����˱���������
        return makeTree(head, NULL);
    }
private:
    TreeNode* makeTree(ListNode* left, ListNode* right) {
        if (left == right) return NULL; //[left, left)����Ϊ��
        ListNode* midNode = getMidNode(left, right);
        TreeNode* root = new TreeNode(midNode->val);
        root->left = makeTree(left, midNode);//����Ҳ������ҿ�����Ϊ�ұ�midNode�Ѿ��Ǳ�ѡ����
        root->right = makeTree(midNode->next, right);
        return root;
    }
    ListNode* getMidNode(ListNode* left, ListNode* right) {
        ListNode* slow = left;
        ListNode* fast = left;
        while (fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};