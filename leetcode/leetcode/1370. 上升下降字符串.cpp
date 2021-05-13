#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：桶计数

说明：类似于hash表，只要是题目中有明确或者暗示说明均为小写/大写字母，均为数字(且范围给定)都可以考虑

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：
    1.string的范围for循环取出来的是字符，字符可以通过加减某个常数来变成另一个字符，规律就是ascii码
    比如：
            string temp{'a' + 2, 'c' - 1, 'd'}; //合法，temp = "cbd"
    注意：字符串不能这样加减！因此"a" - 2就是绝对错误的！

***********************************************************************************************************/
class Solution {
public:
    string sortString(string s) {
        vector<int> barrel(26, 0);
        for (auto i : s) {
            barrel[i - 'a']++;
        }
        string ans;
        while (ans.size() != s.size()) {
            for (int i = 0; i < barrel.size(); i++) {
                addChar(barrel, ans, i);
            }
            for (int j = barrel.size() - 1; j >= 0; j--) {
                addChar(barrel, ans, j);
            }
        }
        return ans;
    }
private:
    void addChar(vector<int>& barrel, string& ans, int i) {
        if (barrel[i]) {
            barrel[i]--;
            ans.push_back(i + 'a');
        }
    }
};