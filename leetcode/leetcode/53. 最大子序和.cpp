#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：暴力法（滑动窗口发）改进版

说明：
    险过
时间复杂度与空间复杂度：
	O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sumVal = 0;
            for (int j = i; j < n; j++) {
                sumVal += nums[j];
                maxSum = max(maxSum, sumVal);
            }
        }
        return maxSum;
    }
};

