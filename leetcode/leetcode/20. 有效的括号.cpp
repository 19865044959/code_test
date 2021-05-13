#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

/**********************************************************************************************************
方法：栈

说明：
    需要注意到这样一个事实：如果一个字符串是合法的，那么一定存在第一个左右扩号，他们是一对
    消去了这左右扩号，剩余的扩号仍然成立

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

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