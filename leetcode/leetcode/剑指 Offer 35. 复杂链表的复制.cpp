#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/**********************************************************************************************************
������hash��ӳ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺
    �����������ݹ�+����˫����
***********************************************************************************************************/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> hash;
        Node* cur = head;
        while (cur != NULL) {
            hash[cur] = new Node(cur->val);
            cur = cur->next;
        }
        Node* dummyNode = new Node(0);
        Node* pre = dummyNode;
        cur = head;
        while (cur != NULL) {
            pre->next = hash[cur];
            pre->next->random = hash[cur->random];
            cur = cur->next;
            pre = pre->next;
        }
        Node* nodeN = dummyNode->next;
        delete dummyNode;
        return nodeN;
    }
};