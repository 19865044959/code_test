#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：分析法

说明： 
            思路：一共有4种字符，分别是：
                1. 数字
                2. .
                3. e/E
                4. +-
            现在只需要考虑在一种出现后，其他会不会已经出现，比如：
            .的出现之前：数字可以没有出现/有出现
                        .不能出现
                        e/E不能出现
                        +-号可以出现也可以不出现

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：
    字符串删除前后空格函数Trim
***********************************************************************************************************/

class Solution {
public:
    bool isNumber(string s) {
        /*
            思路：一共有4种字符，分别是：
                1. 数字
                2. .
                3. e/E
                4. +-
            现在只需要考虑在一种出现后，其他会不会已经出现，比如：
            .的出现之前：数字可以没有出现/有出现
                        .不能出现
                        e/E不能出现
                        +-号可以出现也可以不出现
        */
        bool numFlag = false;
        bool dotFlag = false;
        bool eorEFlag = false;
        bool symbolFlag = false;

        //去除头空格与尾空格
        trim(s);

        for (int i = 0; i < s.size(); i++) {
            //检查+-号：+-号出现的条件：在开头：i == 0 或者在e前面：s[i-1] == 'e/E'
            if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E'));

            //检查数字
            else if (s[i] >= '0' && s[i] <= '9') numFlag = true;

            //检查.：.一定需要在e/e之前出现，并且只能出现一个.
            else if (s[i] == '.' && eorEFlag == false && dotFlag == false) dotFlag = true;

            //检查e/E:在之前一定要出现数字，并且只能出现一个e/E
            else if ((s[i] == 'e' || s[i] == 'E') && numFlag == true && eorEFlag == false) {
                eorEFlag = true;
                numFlag = false; //防止123E通过
            }
            else {
                return false;
            }
        }
        return numFlag;
    }

    void trim(string& s) {
        if (!s.empty() && (s[0] == ' ' || s[s.size() - 1] == ' ')) {
            s.erase(0, s.find_first_not_of(' '));
            s.erase(s.find_last_not_of(' ') + 1);
        }
    }
};