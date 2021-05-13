#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<set>
#include<map>
#include <stack>
/*
    写作业问题：小明放假，1天写作业后，劳逸结合玩1-2天，现在给出假期天数，以及各个天数对应能写的作业数，返回假期能写最多的作业
    dp[i][j]表示第i（i>= 1 && i <= n）天，j状态（类似股票问题），j = 0没写，j = 1写
    那么
    dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + nums[i - 1]
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    初始条件有2个，算两次取最大即可
*/
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][1] = nums[0];
        int maxVal = 0;
        for (int i = 2; i <= n; i++) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + nums[i - 1];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            maxVal = max(max(dp[i][1], dp[i][0]), maxVal);
        }

        vector<vector<int>> dp2(n + 1, vector<int>(2, 0));
        dp[2][1] = nums[0];
        for (int i = 3; i <= n; i++) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + nums[i - 1];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            maxVal = max(max(dp[i][1], dp[i][0]), maxVal);
        }

        cout << maxVal << endl;
    }
    return 0;
}