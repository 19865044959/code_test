#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：动态规划

说明：
	1. 定义子问题：子问题是走到第[i][j]格的最短距离，以dp[i][j]表示
	2. 寻找子问题的递归关系
	由于只能从右侧或者下侧来达到dp[i][j]，因此：
		①i == 0时，dp[i][j] = dp[i][j-1] + nums[i][j];
		②j == 0时，dp[i][j] = dp[i-1][j] + nums[i][j];
		③均不为零时，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + nums[i][j]; 
    3. 直接在grid上进行修改即可

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int column = grid[0].size();
        for (int i = 1; i < row; i++) {
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        for (int i = 1; i < column; i++) {
            grid[0][i] = grid[0][i] + grid[0][i - 1];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[row - 1][column - 1];
    }
};