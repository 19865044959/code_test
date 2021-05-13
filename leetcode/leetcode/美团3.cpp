/*
给你一个01串，你能删除三个连续的字符，可以无限次操作，问如何操作后让0和1的个数差最大，输出最大的差值。
使用dp即可dp0[x]代表前x个字符0-1最大的差值， dp1[x]代表前x个字符1-0的最大差值。
思路：动规
	设dp0[i]为以idx = i结尾的0 - 1的最大值，dp1[i]为以idx = i结尾的1 - 0的最大值，则有：
	dp0[i] = max(dp0[i - 3], //删除最后3个字符
						  dp0[i - 1] + cal(str[i]) //删除以倒数第1个结尾的3个字符
						  dp0[i - 2] + cal(str[i - 1], str[i]) //删除以倒数第二个结尾的3个字符
						  dp0[i - 3] + cal(str[i], str[i - 1], str[i - 2]) //不删除	
						)
*/

#include<iostream>
#include<assert.h>
#include <vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

int cal(char c) {
	if (c == '0') return 1;
	else return -1;
}

int cal(char c1, char c2) {
	return cal(c1) + cal(c2);
}

int cal(char c1, char c2, char c3) { //完美的函数重载与函数调用
	return cal(c1, c2) + cal(c3);
}

int max(int n1, int n2, int n3, int n4) {
	return max(max(n1, n2), max(n3, n4));
}
int main() {
	int n;
	string str;
	while (cin >> n >> str) {
		vector<int>dp0(n);
		vector<int>dp1(n);
		int cnt = 0;
		for (int i = 0; i < n && i < 3; i++) { //初始化dp0、dp1
			if (str[i] == '0') cnt++;
			else {
				cnt--;
			}
			dp0[i] = cnt;
			dp1[i] = -cnt;
			if (i == 2) {
				dp0[i] = max(cnt, 0);
				dp1[i] = max(-cnt, 0);
			}
		}
		for (int i = 3; i < n; i++) {
			dp0[i] = max(
				dp0[i - 3],
				dp0[i - 1] + cal(str[i]),
				dp0[i - 2] + cal(str[i - 1], str[i]),
				dp0[i - 3] + cal(str[i - 2], str[i - 1], str[i])
			);
		}
		for (int i = 3; i < n; i++) {
			dp1[i] = max(
				dp1[i - 3],
				dp1[i - 1] - cal(str[i]),
				dp1[i - 2] - cal(str[i - 1], str[i]),
				dp1[i - 3] - cal(str[i - 2], str[i - 1], str[i])
			);
		}
		cout << max(dp0[n - 1], dp1[n - 1]) << endl;
	}
	return 0;
}