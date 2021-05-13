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
方法1：遍历链表，找到待删除节点的前一个节点即可

说明：

时间复杂度与空间复杂度：
    时间复杂度：O(n)
    空间复杂度：O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL) return NULL;//0. 头指针如果本来就是NULL，则直接返回NULL
            if (head->val == val) return head->next; //1. 如果删除的是头节点，那么直接返回头结点的下一个节点即可（不论下一个节点是否为空）
        ListNode* pNode = head;
        while (pNode->next != NULL && pNode->next->val != val) {
            pNode = pNode->next;
        }
        if (pNode->next == NULL) return head; //2. 如果待删除的值val不在链表中，直接返回头指针即可
        pNode->next = pNode->next->next;
        return head;
    }
};


/**********************************************************************************************************
方法2：假设直接给了待删除指针

说明：
    注意：这里的代码已经默认了toBeDeleted已经在链表之中

时间复杂度与空间复杂度：
    时间复杂度：O(1)
    空间复杂度：O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, ListNode* toBeDeleted) {
        if (head == NULL || toBeDeleted == NULL) return head;// 0.如果head或者toBeDeleted == NULL，则直接返回head
        if (head == toBeDeleted && head->next == NULL) {// 1.如果要删除的是头节点，并且整个链表只有一个节点
            delete toBeDeleted;
            toBeDeleted = NULL;
            head = NULL;
            return head;
        }
        if (toBeDeleted->next != NULL) { //2. 如果待删除的节点不是最后一个节点
            ListNode* pNode = toBeDeleted->next;
            toBeDeleted->val = pNode->val;
            toBeDeleted->next = pNode->next;
            delete pNode;
            pNode = NULL;
        }
        else { // 3. 如果待删除的是尾节点
            ListNode* pNode = head;
            while (pNode->next != toBeDeleted) {
                pNode = pNode->next;
            }
            pNode->next = pNode->next->next;
            delete toBeDeleted;
            toBeDeleted = NULL;
        }
        return head;
    }
};