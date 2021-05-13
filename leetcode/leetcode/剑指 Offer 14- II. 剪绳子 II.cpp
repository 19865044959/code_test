#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：详见I

说明：
	涉及到大数越界

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int b = n / 3;
        int c = n % 3;
        long long res = 1;
        if (c == 0) {
            for (int i = 1; i <= b; i++) {
                res = res * 3 % 1000000007;
            }
        }
        else if (c == 1) {
            for (int i = 1; i < b; i++) {
                res = res * 3 % 1000000007;
            }
            res = res * 4 % 1000000007;
        }
        else {
            for (int i = 1; i <= b; i++) {
                res = res * 3 % 1000000007;
            }
            res = res * 2 % 1000000007;
        }
        return res;
    }
};
