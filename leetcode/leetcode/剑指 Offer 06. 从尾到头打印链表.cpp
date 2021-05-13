#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**********************************************************************************************************
����1���ö�̬���鴢������ֵ����ȡ������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> reversePrint(ListNode* head) {
         vector<int>res;
         ListNode* pNode = head;
         while(pNode != NULL){
             res.push_back(pNode->val);
             pNode = pNode->next;
         }
         int n = res.size();
         int middle = n / 2 - 1;
         for(int i = 0; i <= middle; i++){
             int temp = res[i];
             res[i] = res[n-i-1];
             res[n-i-1] = temp;
         }
         return res;
     }
 };

 /**********************************************************************************************************
����2�����ö�ջ������ȳ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> reversePrint(ListNode* head) {
         vector<int> res;
         stack<ListNode*> sta;
         ListNode* pNode = head;
         while(pNode != NULL){
             sta.push(pNode);
             pNode = pNode->next;
         }
         while(!sta.empty()){
             ListNode* temp = sta.top();
             sta.pop();
             res.push_back(temp->val);
         }
         return res;
     }
 };


 /**********************************************************************************************************
����3������ȳ��������õݹ����������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> reversePrint(ListNode* head) {
         vector<int> res;
         reversePrint_Recursive(head, res);
         return res;
     }

     void reversePrint_Recursive(ListNode* head, vector<int>& res) {
         if (head != NULL) {
             reversePrint_Recursive(head->next, res);
             res.push_back(head->val);
         }
         // if(head == NULL) return;
         // reversePrint_Recursive(head->next, res);
         // res.push_back(head->val);
     }
 };
