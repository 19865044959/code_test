#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

/**********************************************************************************************************
方法：利用堆栈处理问题

说明：
    难点：太难想了，即使想出来，实现也困难重重，容易出错

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：
    这里的每一步都是精华！
***********************************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string ans = "";
        stack<pair<int, string>>sta; //这里运用了之前学习的pair，将(int,string)打包到一起，便于管理
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num *= 10; //这里为什么要×10？因为如果num是2位数或以上，比如382[a]，那么需要3*100 + 8*10 + 2个a
                num += s[i] - '0';
            }
            else if (s[i] == '[') {
                sta.push({ num, ans }); //s.push(pair<int, string>{num, ans})或s.push(make_pair(num, ans))均可
                num = 0; //这里清空num与ans是非常容易忽略的！
                ans = "";
            }
            else if (s[i] == ']') {
                int tempNum = sta.top().first;
                string tempStr = sta.top().second;
                sta.pop();
                //注意：这里是tempNum个ans加到tempStr后面
                for (int j = 0; j < tempNum; j++) {
                    tempStr += ans;
                }
                ans = tempStr; //让ans变成tempStr
            }
            else if (isalpha(s[i])) {
                ans += s[i];
            }
        }
        return ans;
    }
};

/**********************************************************************************************************
方法：发现子问题与原问题的相似性，利用递归解决问题

说明：
     b3[a2[c]]--> 前两个字符是：b3。当遇到'['时， a2与b3具有相似性；当再遇到'['时，c与a2、b3具有相似性，因此本题可以递归解决

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：
    这里的每一步都是精华！
***********************************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
    string dfs(string& s, int& i) {
        string res;
        int multi = 0;
        for (;i < s.length(); ++i) {
            if ('0' <= s[i] && '9' >= s[i]) {
                multi = multi * 10 + int(s[i] - '0');
            }
            else if (s[i] == '[') {
                string temp1, temp2 = dfs(s, ++i);
                while (multi != 0) {
                    temp1.append(temp2);
                    --multi;
                }
                res += temp1;
            }
            else if (s[i] == ']') {
                return res;
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};