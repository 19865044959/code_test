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
�������ƽ��+sum

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
        //�п������ʣ��λû�м��㣬��ʱҪ�������Ͻ�λ��ֵ������оͼӣ�û�оͲ���
        if (carry != 0) curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};

//���ַ��������ǿ��Եģ�����leetcode���⽫ɾ���˵�Ԫ��Ҳ�������ڣ����Խ���Ǵ��
//�ṹ����ÿ�ζ��������curr->next = new ListNode(0)������������и�ֵ����
//����Ұ��������ϲ����������ܽ���������
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