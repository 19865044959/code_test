#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    vector<vector<int>>prices(m + 1, vector<int>(3, 0));
    vector<vector<int>>pricesMulPriority(m + 1, vector<int>(3, 0));
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0) {
            prices[i][0] = a;
            pricesMulPriority[i][0] = a * b;
        }
        else if (prices[c][1] == 0) {
            prices[c][1] = a;
            pricesMulPriority[c][1] = a * b;
        }
        else {
            prices[c][2] = a;
            pricesMulPriority[c][2] = a * b;
        }
    }

    vector<vector<int>>dp(m + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= N; j++) {
            int p0 = prices[i][0], q0 = pricesMulPriority[i][0];
            int p1 = prices[i][1], q1 = pricesMulPriority[i][1];
            int p2 = prices[i][2], q2 = pricesMulPriority[i][2];
            dp[i][j] = (j - p0 >= 0) ? max(dp[i - 1][j], dp[i - 1][j - p0] + q0) : dp[i - 1][j];
            dp[i][j] = (j - p0 - p1 >= 0) ? max(dp[i][j], dp[i - 1][j - p0 - p1] + q0 + q1) : dp[i][j];
            dp[i][j] = (j - p0 - p1 - p2 >= 0) ? max(dp[i][j], dp[i - 1][j - p0 - p1 - p2] + q0 + q1 + q2) : dp[i][j];
        }
    }
    cout << dp[m][N] << endl;
    return 0;
}