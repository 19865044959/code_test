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
方法：hash表映射

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：
    链表的深拷贝，递归+迭代双方法
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