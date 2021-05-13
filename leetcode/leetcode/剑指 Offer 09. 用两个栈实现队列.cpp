#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������

˵����
    1. stack1����append��stack2����delete
    2. ��deleteʱ
        �ٵ�stack2��Ϊ�գ�ֱ�ӵ���ջ��
        �ڵ�stack2Ϊ�գ�����stack1Ϊ�գ�����-1
        �۵�stack2λ�գ�stack1��Ϊ�գ���ô��stack1������Ԫ�ص�����ѹ��stack2��֮�󵯳�stack2ջ��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(1) O(n)

�漰����֪ʶ�㣺

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