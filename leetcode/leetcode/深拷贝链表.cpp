#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
//两种方法，一种是递归，一种是迭代，迭代需要一个辅助节点dummy node
class DeepCopyListClass {
public:
    ListNode* DeepCopyRecur(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* headN = new ListNode(head->val);
        headN->next = DeepCopyRecur(head->next);
        return headN;
    }
    ListNode* DeepCopyIter(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* pre = dummyNode;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* node = new ListNode(cur->val);
            pre->next = node;
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* headN = pre->next;
        delete pre;
        return headN;
    }
private:
};