#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：动态规划

说明：
	1. 实现动态规划的四个步骤：
		(1). 定义子问题
			子问题定义：与原问题相似，只不过规模较小就是子问题，很像dfs之中递归时的结构
			子问题要求：
				①原问题可以由子问题表示出来
				②子问题的解可以由更小的子问题来求解
			题目中原问题是求全部房子中能偷到的最大金额，那么子问题是求前k个房子中能偷到的最大金额，用dp[k]来表示
		(2). 写出子问题的递推关系
			这一步是关键所在，也是最无法在代码中体现出的一步，对于本题：
			dp[k] = max(nums[k] + dp[k-2], dp[k-1])
		(3). 确定dp数组的计算顺序
			*①自底向上，使用dp数组循环
			②自顶向下，使用备忘录递归方法
		(4). 空间优化			

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：
	动态规划详解：
	https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/
***********************************************************************************************************/

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		if (n == 1) return nums[0];

		vector<int> dp(n, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[n - 1];
	}
};