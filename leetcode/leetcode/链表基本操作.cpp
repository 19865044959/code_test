#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	};
};

/*
	注意：为什么这里的头节点需要用到指向指针的指针，而不能单单只是用到指针
	结论：但凡涉及到改变头指针的操作（注意是头指针，而不是头指针指向的值），都需要用到指向指针的指针
	本质：函数传值操作，传递的是变量的复制，而不是变量本身，如果是变量本身，需要加上引用符号&
	解释：当把头节点指针以值传入函数中时，我们传递的是头结点地址的拷贝，如果此时改变头结点指针，由于改变的仅是
		      头结点指针的拷贝，那么出了函数后，真正的头结点指针不会被改变，要想真正改变头结点，必须加上引用符号&或者传递指针的指针，即**
*/
ListNode* AddToTail(ListNode** pHead, int val) {
	ListNode* pNode = new ListNode(val);
	if (*pHead == NULL) {
		*pHead = pNode;
	}
	else {
		ListNode* pNext = *pHead;
		while (pNext->next != NULL) {
			pNext = pNext->next;
		}
		pNext->next = pNode;
	}
	return *pHead;
}

ListNode* AddToTail2(ListNode* pHead, int val) {
	ListNode* pNode = new ListNode(val);
	if (pHead == NULL) {
		pHead = pNode;
	}
	else {
		ListNode* pNext = pHead;
		while (pNext->next != NULL) {
			pNext = pNext->next;
		}
		pNext->next = pNode;
	}
	return pHead;
}

int main() {
	ListNode* pHead = NULL;
	ListNode* pHead2 = NULL;
	auto res = AddToTail(&pHead, 10);
	auto res2 = AddToTail2(pHead, 10);

	return 1;
}