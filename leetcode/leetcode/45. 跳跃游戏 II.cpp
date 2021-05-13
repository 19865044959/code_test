#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：贪心算法

说明：
   1. 寻找子问题：到达前面每一个点都以最小跳跃数，即走的每一步都是最长的（局部最优）
    比如 2 3 1 2 4 2 3
    下标 0 1 2 3 4 5 6
    ①下标0最长到达下标2（第一步走最长）
    ②从下标0-下标2这一个范围，第二步走下标1可以达到下标4（第二步走最长）
    ③从下标1-下标4中，下标4可达到下标8（8 > 6说明可以走到终点，第三步最长）
    每步都最长构成了贪心算法

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        int p = 0;
        int count = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            maxlen = max(maxlen, nums[i] + i);
            if (i == p) {
                count++;
                p = maxlen;
                if (p >= n - 1) break;
            }
        }
        return count;
    }
};