#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：

说明：
	二刷详见题解

时间复杂度与空间复杂度：O(m*n) O(m*n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                //正则为空
                if (j == 0) {
                    dp[i][j] = (i == 0 ? 1 : 0);
                }
                //正则非空
                else {
                    //没有*
                    if (p[j - 1] != '*') {
                        if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    }
                    //有*
                    else {
                        //情况1，不看
                        if (j >= 2) {
                            dp[i][j] = dp[i][j] | dp[i][j - 2];
                        }
                        //情况2：看
                        if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                            dp[i][j] = dp[i][j] | dp[i - 1][j];
                        }
                    }
                }
            }
        }
        return dp[n][m];
    }
};