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
	ע�⣺Ϊʲô�����ͷ�ڵ���Ҫ�õ�ָ��ָ���ָ�룬�����ܵ���ֻ���õ�ָ��
	���ۣ������漰���ı�ͷָ��Ĳ�����ע����ͷָ�룬������ͷָ��ָ���ֵ��������Ҫ�õ�ָ��ָ���ָ��
	���ʣ�������ֵ���������ݵ��Ǳ����ĸ��ƣ������Ǳ�����������Ǳ���������Ҫ�������÷���&
	���ͣ�����ͷ�ڵ�ָ����ֵ���뺯����ʱ�����Ǵ��ݵ���ͷ����ַ�Ŀ����������ʱ�ı�ͷ���ָ�룬���ڸı�Ľ���
		      ͷ���ָ��Ŀ�������ô���˺�����������ͷ���ָ�벻�ᱻ�ı䣬Ҫ�������ı�ͷ��㣬����������÷���&���ߴ���ָ���ָ�룬��**
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