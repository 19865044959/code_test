#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

/**********************************************************************************************************
������ջ

˵����
    ��Ҫע�⵽����һ����ʵ�����һ���ַ����ǺϷ��ģ���ôһ�����ڵ�һ���������ţ�������һ��
    ��ȥ�����������ţ�ʣ���������Ȼ����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char>hash{ {'}', '{'}, {']', '['}, {')', '('} };
        stack<int>sta;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                sta.push(c);
                continue;
            }
            else if (sta.empty() || sta.top() != hash[c]) {
                return false;
            }
            sta.pop();
        }
        if (!sta.empty()) return false;
        return true;
    }
};