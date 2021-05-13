/*
	玩游戏，每个游戏耗时都是1，共有n个游戏，每个游戏有相应的荣誉点以及截止时间，如果完不成，就扣除相应的荣誉点。求一个方案，使得荣誉点扣得最少
	输入：
	n
	n个t
	n个val

	贪心：先完成荣誉点多的游戏（因为时间相同），再完成时间靠前的，最后完成时间靠后的
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