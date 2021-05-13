#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：动态规划

说明：
	此题是在198题上的扩展，偷环形屋与偷直线屋唯一不同的区别就是：偷直线屋可以第一个与最后一个房子都偷，
	但是偷环形屋不允许第一个与最后一个都偷，要择其一，因此可以将题目化为：不偷第一间房/不偷最后一间房的直线屋

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]); //保证下面传入dpSolution里面的值至少为2个，这样就可以对dp[0]与dp[1]初始化了
        int ans1 = dpSolution(nums.begin() + 1, nums.end());
        int ans2 = dpSolution(nums.begin(), nums.end() - 1);
        return max(ans1, ans2);
    }
private:
    int dpSolution(vector<int>::iterator iter1, vector<int>::iterator iter2) {
        vector<int> numCopy(iter1, iter2);

        //下面的代码与198一模一样
        int n = numCopy.size();
        vector<int> dp(n, 0);
        dp[0] = numCopy[0]; //由于上面传入的值至少为2个，因此可以直接对dp[0]与dp[1]进行初始化
        dp[1] = max(numCopy[0], numCopy[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + numCopy[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};