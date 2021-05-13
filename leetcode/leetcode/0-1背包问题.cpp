#include <iostream>
#include <vector>
#include <algorithm>
/*
	题目描述：给定n件物品的价值val，以及对应的物品的重量weight，假设你现在有容量为p的背包，求能够装下物品的最大价值
*/
using namespace std;

class Solution {
public:
	int maxValGet(vector<int>val, vector<int>weight, int maxWeight) {
		int n = val.size();
		vector<vector<int>> dp(maxWeight + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= n; i++) {
			dp[0][i] = 0;
		}
		for (int j = 0; j <= maxWeight; j++) {
			dp[j][0] = 0;
		}
		for (int i = 1; i <= maxWeight; i++) {
			for (int j = 1; j <= n; j++) {
				int val_with_j = i - weight[j - 1] >= 0 ? (val[j - 1] + dp[i - weight[j - 1]][j - 1]) : 0; //j物品我拿了，剩余背包的容量为：i - weight[j - 1]，剩余容量对应最大的价值dp[i - weight[j - 1]][j - 1]
				int val_without_j = dp[i][j - 1]; //j物品我不拿，那么最大价值是除了j物品外的j-1个物品的最大价值dp[i][j - 1]
				dp[i][j] = max(val_without_j, val_with_j);
			}
		}
		return dp[maxWeight][n];
	}
};

int main() {
	/*
	吉他：重1 价1500
	音响：重4 价3000
	笔本：重3 价2000
	手机：重1 价2000
	*/
	vector<int> val({ 1500, 3000, 2000, 2000 });
	vector<int> weight({ 1, 4, 3, 1 });
	Solution a;
	auto res = a.maxValGet(val, weight, 4);

	return 1;
}