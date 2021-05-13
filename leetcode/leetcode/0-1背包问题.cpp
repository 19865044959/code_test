#include <iostream>
#include <vector>
#include <algorithm>
/*
	��Ŀ����������n����Ʒ�ļ�ֵval���Լ���Ӧ����Ʒ������weight������������������Ϊp�ı��������ܹ�װ����Ʒ������ֵ
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
				int val_with_j = i - weight[j - 1] >= 0 ? (val[j - 1] + dp[i - weight[j - 1]][j - 1]) : 0; //j��Ʒ�����ˣ�ʣ�౳��������Ϊ��i - weight[j - 1]��ʣ��������Ӧ���ļ�ֵdp[i - weight[j - 1]][j - 1]
				int val_without_j = dp[i][j - 1]; //j��Ʒ�Ҳ��ã���ô����ֵ�ǳ���j��Ʒ���j-1����Ʒ������ֵdp[i][j - 1]
				dp[i][j] = max(val_without_j, val_with_j);
			}
		}
		return dp[maxWeight][n];
	}
};

int main() {
	/*
	��������1 ��1500
	���죺��4 ��3000
	�ʱ�����3 ��2000
	�ֻ�����1 ��2000
	*/
	vector<int> val({ 1500, 3000, 2000, 2000 });
	vector<int> weight({ 1, 4, 3, 1 });
	Solution a;
	auto res = a.maxValGet(val, weight, 4);

	return 1;
}