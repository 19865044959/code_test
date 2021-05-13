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
����1�����������ҵ���ɾ���ڵ��ǰһ���ڵ㼴��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�
    ʱ�临�Ӷȣ�O(n)
    �ռ临�Ӷȣ�O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL) return NULL;//0. ͷָ�������������NULL����ֱ�ӷ���NULL
            if (head->val == val) return head->next; //1. ���ɾ������ͷ�ڵ㣬��ôֱ�ӷ���ͷ������һ���ڵ㼴�ɣ�������һ���ڵ��Ƿ�Ϊ�գ�
        ListNode* pNode = head;
        while (pNode->next != NULL && pNode->next->val != val) {
            pNode = pNode->next;
        }
        if (pNode->next == NULL) return head; //2. �����ɾ����ֵval���������У�ֱ�ӷ���ͷָ�뼴��
        pNode->next = pNode->next->next;
        return head;
    }
};


/**********************************************************************************************************
����2������ֱ�Ӹ��˴�ɾ��ָ��

˵����
    ע�⣺����Ĵ����Ѿ�Ĭ����toBeDeleted�Ѿ�������֮��

ʱ�临�Ӷ���ռ临�Ӷȣ�
    ʱ�临�Ӷȣ�O(1)
    �ռ临�Ӷȣ�O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, ListNode* toBeDeleted) {
        if (head == NULL || toBeDeleted == NULL) return head;// 0.���head����toBeDeleted == NULL����ֱ�ӷ���head
        if (head == toBeDeleted && head->next == NULL) {// 1.���Ҫɾ������ͷ�ڵ㣬������������ֻ��һ���ڵ�
            delete toBeDeleted;
            toBeDeleted = NULL;
            head = NULL;
            return head;
        }
        if (toBeDeleted->next != NULL) { //2. �����ɾ���Ľڵ㲻�����һ���ڵ�
            ListNode* pNode = toBeDeleted->next;
            toBeDeleted->val = pNode->val;
            toBeDeleted->next = pNode->next;
            delete pNode;
            pNode = NULL;
        }
        else { // 3. �����ɾ������β�ڵ�
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