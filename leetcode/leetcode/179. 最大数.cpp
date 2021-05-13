#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：

涉及到的知识点：
1. 见面试题45
2. ""代表的是字符串，而''代表的是字符！string[i]返回的是字符而不是字符串！，因此需要用单引号而不是双引号

***********************************************************************************************************/
class Solution_179 {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for (auto i : nums) {
            temp.push_back(to_string(i));
        }
        sort(temp.begin(), temp.end(), findMax);
        string ans = "";
        for (auto i : temp) {
            ans += i;
            if (ans[0] == '0') break;//注意！不可以写成"0"，因为""是字符串，而ans[0]返回的是字符！
        }
        return ans;
    }

private:
    static bool findMax(string str1, string str2) {
        return str1 + str2 > str2 + str1;
    }
};