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

/**********************************************************************************************************
方法：哑结点+sum

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int x = l1 == NULL ? 0 : l1->val;
            int y = l2 == NULL ? 0 : l2->val;
            int sum = x + y + carry;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        //有可能最后还剩进位没有计算，这时要主动加上进位的值，如果有就加，没有就不加
        if (carry != 0) curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};

//这种方法理论是可以的，但是leetcode判题将删除了的元素也计入在内，所以结果是错的
//结构：我每次都是先添加curr->next = new ListNode(0)，再向里面进行赋值操作
//如果我把这两步合并起来，则能解决这个问题
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry = 0;
//         ListNode* node = new ListNode(0);
//         ListNode* curr = node;
//         while(l1 != NULL || l2 != NULL){
//             int x = l1 == NULL ? 0 : l1->val;
//             int y = l2 == NULL ? 0 : l2->val;
//             curr->val = (x + y + carry) % 10;
//             carry = (x + y + carry) / 10;
//             curr->next = new ListNode(0);
//             curr = curr->next;
//             if(l1 != NULL) l1 = l1->next;
//             if(l2 != NULL) l2 = l2->next;
//         }
//         if(carry != 0) curr->val = carry;
//         else{
//             delete curr;
//         }
//         return node;
//     }
// };