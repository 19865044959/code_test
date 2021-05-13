#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：

说明：
    1. stack1用于append，stack2用于delete
    2. 当delete时
        ①当stack2不为空，直接弹出栈顶
        ②当stack2为空，并且stack1为空，返回-1
        ③当stack2位空，stack1不为空，那么将stack1的所有元素弹出并压入stack2，之后弹出stack2栈顶

时间复杂度与空间复杂度：O(1) O(n)

涉及到的知识点：

***********************************************************************************************************/

class CQueue {
public:
    CQueue() {
        while (!sta1.empty()) {
            sta1.pop();
        }
        while (!sta2.empty()) {
            sta2.pop();
        }
    }

    void appendTail(int value) {
        sta1.push(value);
    }

    int deleteHead() {
        int res;
        if (sta2.empty()) {
            if (sta1.empty()) return -1;
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        res = sta2.top();
        sta2.pop();
        return res;
    }
private:
    stack<int> sta1;
    stack<int> sta2;
};