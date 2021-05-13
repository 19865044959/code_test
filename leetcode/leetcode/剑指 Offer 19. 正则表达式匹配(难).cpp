#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������

˵����
	��ˢ������

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m*n) O(m*n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                //����Ϊ��
                if (j == 0) {
                    dp[i][j] = (i == 0 ? 1 : 0);
                }
                //����ǿ�
                else {
                    //û��*
                    if (p[j - 1] != '*') {
                        if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    }
                    //��*
                    else {
                        //���1������
                        if (j >= 2) {
                            dp[i][j] = dp[i][j] | dp[i][j - 2];
                        }
                        //���2����
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