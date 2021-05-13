#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
��������̬�滮

˵����
	1. ���������⣺���������ߵ���[i][j]�����̾��룬��dp[i][j]��ʾ
	2. Ѱ��������ĵݹ��ϵ
	����ֻ�ܴ��Ҳ�����²����ﵽdp[i][j]����ˣ�
		��i == 0ʱ��dp[i][j] = dp[i][j-1] + nums[i][j];
		��j == 0ʱ��dp[i][j] = dp[i-1][j] + nums[i][j];
		�۾���Ϊ��ʱ��dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + nums[i][j]; 
    3. ֱ����grid�Ͻ����޸ļ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

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