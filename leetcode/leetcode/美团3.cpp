/*
����һ��01��������ɾ�������������ַ����������޴β���������β�������0��1�ĸ��������������Ĳ�ֵ��
ʹ��dp����dp0[x]����ǰx���ַ�0-1���Ĳ�ֵ�� dp1[x]����ǰx���ַ�1-0������ֵ��
˼·������
	��dp0[i]Ϊ��idx = i��β��0 - 1�����ֵ��dp1[i]Ϊ��idx = i��β��1 - 0�����ֵ�����У�
	dp0[i] = max(dp0[i - 3], //ɾ�����3���ַ�
						  dp0[i - 1] + cal(str[i]) //ɾ���Ե�����1����β��3���ַ�
						  dp0[i - 2] + cal(str[i - 1], str[i]) //ɾ���Ե����ڶ�����β��3���ַ�
						  dp0[i - 3] + cal(str[i], str[i - 1], str[i - 2]) //��ɾ��	
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

int cal(char c1, char c2, char c3) { //�����ĺ��������뺯������
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
		for (int i = 0; i < n && i < 3; i++) { //��ʼ��dp0��dp1
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