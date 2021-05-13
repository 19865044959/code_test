#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������˫�����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

//˫�����
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        temp.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int retval = temp.back();
        temp.pop_back();
        return retval;
    }

    /** Get the top element. */
    int top() {
        return temp.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return temp.empty();
    }
private:
    deque<int> temp;
};