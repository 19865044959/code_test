#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
��������̬�滮

˵��������ͬ·��1

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row * column)  O(row * column)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        for (int i = 0; i < row; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            }
            else {
                break;
            }
        }

        for (int i = 0; i < column; i++) {
            if (obstacleGrid[0][i] == 0) {
                dp[0][i] = 1;
            }
            else {
                break;
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][column - 1];
    }
};