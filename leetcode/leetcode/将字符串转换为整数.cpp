#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������
	�������⣬��Ҫ������ȫ��

˵����
	΢�������⣬˼����
	1. �����ַ���ô��
	2. ���������ô��
	3. ��������ô��

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

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
