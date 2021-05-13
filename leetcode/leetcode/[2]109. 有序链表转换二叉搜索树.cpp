#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：dfs + 将链表转换为数组

说明：详见108题

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

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
方法：快慢指针

说明：详见108题

时间复杂度与空间复杂度：O(n * logn)  O(logn)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        //由于链表的最后一个节点不经过遍历是不知道的，而经过遍历则会损耗时间，因此直接以链表最后一个节点的下一个节点
        //即NULL作为边界条件，即左闭右开，[left, right)，这样就避免了遍历链表了
        return makeTree(head, NULL);
    }
private:
    TreeNode* makeTree(ListNode* left, ListNode* right) {
        if (left == right) return NULL; //[left, left)集合为空
        ListNode* midNode = getMidNode(left, right);
        TreeNode* root = new TreeNode(midNode->val);
        root->left = makeTree(left, midNode);//这里也是左闭右开，因为右边midNode已经是被选过了
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