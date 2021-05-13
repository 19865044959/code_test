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
    д��ҵ���⣺С���ż٣�1��д��ҵ�����ݽ����1-2�죬���ڸ��������������Լ�����������Ӧ��д����ҵ�������ؼ�����д������ҵ
    dp[i][j]��ʾ��i��i>= 1 && i <= n���죬j״̬�����ƹ�Ʊ���⣩��j = 0ûд��j = 1д
    ��ô
    dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + nums[i - 1]
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    ��ʼ������2����������ȡ��󼴿�
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