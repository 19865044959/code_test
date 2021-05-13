#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：
	简单面试题，需要考虑周全！

说明：
	微软面试题，思考：
	1. 特殊字符怎么办
	2. 数字溢出怎么办
	3. 正负号怎么办

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
	int StrToInt(string& str) {
		int n = str.size();
		int negFlag = 0;
		long long res = 0;
		if (n > 64) {
			cout << "The string is out of range!" << endl;
			return -1;
		}
		if (str[0] == '-') {
			negFlag = 1;
		}
		else if (str[0] == '+') {
		}
		else if ((str[0] - '0') > 10 || (str[0] - '0') < 0) {
			cout << "The string input is illegal!" << endl;
			return -1;
		}
		else {
			res = str[0] - '0';
		}

		for (int i = 1; i < n; i++) {
			int temp = str[i] - '0';
			if (temp > 10 || temp < 0) {
				cout << "The string input is illegal!" << endl;
				return -1;
			}
			res = res * 10 + temp;
		}
		if (negFlag) {
			res = -res;
		}
		return res;
	}
};

int main() {
	Solution a;
	string str1("1234567");
	string str2("+1234567");
	string str3("-1234567");
	string str4("L1234567");
	string str5("12345QWE7");
	string str6("12345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE712345QWE7");
	auto res = a.StrToInt(str6);
	return res;
}
