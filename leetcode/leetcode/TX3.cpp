/*
	����Ϸ��ÿ����Ϸ��ʱ����1������n����Ϸ��ÿ����Ϸ����Ӧ���������Լ���ֹʱ�䣬����겻�ɣ��Ϳ۳���Ӧ�������㡣��һ��������ʹ��������۵�����
	���룺
	n
	n��t
	n��val

	̰�ģ����������������Ϸ����Ϊʱ����ͬ���������ʱ�俿ǰ�ģ�������ʱ�俿���
*/

#include <iostream>
#include <vector>
#include<stdlib.h>
#include<string>
#include<queue>
using  namespace std;


struct node {
	int val;
	int t;
};

bool cmp(const node& n1, const node& n2) {
	if (n1.val != n2.val) return n1.val > n2.val;
	else {
		return n1.t < n2.t;
	}
}
int main() {
	int n;
	while (cin >> n) {
		vector<node>nd(n + 1);
		for (int i = 1; i <= n; i++) cin >> nd[i].t;
		for (int i = 1; i <= n; i++) cin >> nd[i].val;
		sort(nd.begin() + 1, nd.end(), cmp);
		int nowT = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (nowT + 1 <= nd[i].t) nowT++;
			else {
				ans += nd[i].val;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

/*
3
3 2  1
9 9 12

3
2 2  1
9 9 12

4
3 2 1 1
9 9 15 18
*/