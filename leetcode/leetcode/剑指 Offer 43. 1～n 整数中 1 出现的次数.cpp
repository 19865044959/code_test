//思考路径有问题
//大佬思考路径：求1~n这n个整数中1出现的次数 <-> 所有数字的个位、十位、百位、千位...中1出现的次数之和

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

时间复杂度与空间复杂度：O(logn) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        int low = 0;
        int cur = n % 10;
        int high = n / 10;
        long digit = 1;
        int res = 0;
        while (cur != 0 || high != 0) {
            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};