#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：排序法

说明：

时间复杂度与空间复杂度：O(nlogn)  O(n)

涉及到的知识点：实测accumulate函数没有直接for循环效率高

***********************************************************************************************************/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> ans;

        // int numSumTotal = accumulate(nums.begin(), nums.end(), 0);
        int numSumTotal = 0;
        for (int j = 0; j < nums.size(); j++) {
            numSumTotal += nums[j];
        }

        int numSumNow = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans.emplace_back(nums[i]);
            numSumNow += nums[i];
            if (numSumNow > numSumTotal / 2) break;
        }
        return ans;
    }
};