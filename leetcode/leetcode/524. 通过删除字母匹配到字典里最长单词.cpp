#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：运用了C++习题10_9里面的知识

说明：理解错误，人家说删除某些字符来得到，暗示了每个出现的字符都需要按照顺序

时间复杂度与空间复杂度：

涉及到的知识点：
    1.lambda表达式
***********************************************************************************************************/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), greater<string>());//逆字典序
        stable_sort(d.begin(), d.end(), [](string a, string b) {return a.size() < b.size();});//从字符长度小到大排序，并且不打乱逆字典序

        vector<int> barrel(26, 0); //桶计数
        for (auto i : s) {
            barrel[i - 'a']++;
        }
        string ans = "";
        for (int i = d.size() - 1; i >= 0; i--) {
            vector<int> temp(barrel);
            int flag = 1;
            for (auto j : d[i]) {
                if (temp[j - 'a']) {
                    temp[j - 'a']--;
                    continue;
                }
                flag = 0;
                break;
            }
            if (flag) {
                ans = d[i];
                break;
            }
        }
        return ans;
    }
};

/**********************************************************************************************************
方法：

说明：正解，考虑到了顺序

时间复杂度与空间复杂度：O(mn)，其中m = s.size(), n = d.size()  空间复杂度：O(m)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (auto str : d) {
            int j = 0;
            for (int i = 0; i < s.size() && j < str.size(); i++) {
                if (s[i] == str[j]) j++;
            }
            if (j == str.size()) {
                if (str.size() > ans.size() || (str.size() == ans.size() && (ans[0] - str[0] > 0))) {
                    ans = str;
                }
            }
        }
        return ans;
    }
};