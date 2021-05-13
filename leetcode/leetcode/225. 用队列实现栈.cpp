#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：双向队列

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

//双向队列
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