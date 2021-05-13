#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
	题目1：足球比赛：若干个队伍两两互比，赢了得3分、平了1分、输了0分。
	输入是：多个 两只队伍的比分，
	输出是：每支队伍的总分，从高到低输出，当总分相同，按字典序排序输出
	难点：
	输入：
	a - b
	3 : 4
	c - d
	4 : 1
	上述输入都有空格，不允许用str1[0] str1[1] str2[2]装，否则会捕获不到相应的数字
	输出：
	1. 是在没有输入的情况下，才输出所有队伍的排名先后，而输入都是有回车的，因此cout需要放到while(cin >> str1 >> str2)循环外边
	2. 字典序，用sort  + lambda表达式，而lambda表达式怎么写也是一个难点
*/

int main() {
	string str1, str2;
	vector<pair<int, char>>vec;
	unordered_map<char, int>hash; //字典序排序
	while (getline(cin, str1) && getline(cin, str2)) { //输入有空格的都需要用getline(cin, str)
		bool flag1 = false;
		bool flag2 = false;
		char chr1, chr2;
		int n1 = 0, n2 = 0;
		//字符提取
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] >= 'a' && str1[i] <= 'z' && !flag1) {
				chr1 = str1[i];
				flag1 = true;
			}
			else if (str1[i] >= 'a' && str1[i] <= 'z' && flag1) {
				chr2 = str1[i];
			}
		}
		//数字提取
		for (int i = 0; i < str2.size(); i++) {
			if (str2[i] >= '0' && str2[i] <= '9' && !flag2) {
				n1 = str2[i];
				flag2 = true;
			}
			else if (str2[i] >= '0' && str2[i] <= '9' && flag2) {
				n2 = str2[i];
			}
		}
		//计数
		if (n1 > n2) {
			hash[chr1] += 3;
			hash[chr2] += 0;
		}
		else if (n1 == n2) {
			hash[chr1] += 1;
			hash[chr2] += 1;
		}
		else {
			hash[chr1] += 0;
			hash[chr2] += 3;
		}
	}
	for (auto iter = hash.begin(); iter != hash.end(); iter++) {
		vec.push_back(make_pair(iter->second, iter->first));
	}
	stable_sort(vec.begin(), vec.end(), [](const pair<int, char>& p1, const pair<int, char>& p2) { //注意是stable_sort
		return p1.first > p2.first;
		});

	////	如果需要字典序降序怎么办？
	//	sort(vec.begin(), vec.end(), [](const pair<int, char>& p1, const pair<int, char>& p2) { //注意是stable_sort
	//		if (p1.first > p2.first) return true;
	//		else if (p1.first == p2.first) return p1.second > p2.second;
	//		else return false;
	//		});

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second << ":" << vec[i].first << endl;
	}
	return 0;
}

/*
1:
a-b
3:4
b-c
2:2
a-c
4:3

2:
a-b
3:4
b-a
3:4

*/


/*
	题目2：公司里面玩游戏，员工带上有颜色的帽子（颜色各种各样），现在给你一个数组，比如：【1，1，2】，代表的是第一个员工看到跟他戴一样颜色的帽子有一个人，
	第二个员工看到跟他戴一样颜色的帽子有1个，第3个员工看到跟他戴一样颜色的帽子有2个。这个例子的输出应该是参加这个游戏的最少的员工，输出是5。
	输入：[n1, n2, .. nk] k < 1000
	输出：最小员工数目
	难点：输入值的获取，当时只考虑了输入看到的数量<10的情况，也就是只考虑到了数字只有一位的情况，所以只有40%通过率
	可以利用stringstream来获取
*/
int main() {
	string str;

	while (getline(cin, str)) {
		vector<int>vec(1000, 0);
		//除第一个括号，注意下面的字母与数字需要成对匹配
		str.erase(str.find_first_of('['), 1);
		//str.erase(str.find_last_of(']'), 1);
		stringstream ss(str); //stringstream流也可以这样初始化
		int n;
		char chr;
		while (ss >> n >> chr) {
			vec[n]++;
		}
		//计算最少人数
		int res = 0;
		res += vec[0];
		int cnt = 0;
		for (int i = 1; i < 1000; i++) {
			cnt = vec[i] / (i + 1);
			vec[i] = vec[i] % (i + 1);
			if (vec[i]) cnt++;
			res += cnt * (i + 1);
		}
		cout << res << endl;
	}
	return 0;
}
// [            0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 7            ]
//[10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11] -- 11*2 +12 = 34


/*
	题目3：
	现在有两个字符串，第一个称为母串，第二个称为子串，你现在手里有个游标，游标每次可以左移一格或者右移一格，
	游到最左边再左移就游到最右边（最右边同理）。现在给你这两个字符串和游标的初始位置，请你用游标找出子串在母串的位置的最小移动次数。例如：输入：asdfg adf 0 应输出：3
	
*/