#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
	��Ŀ1��������������ɸ������������ȣ�Ӯ�˵�3�֡�ƽ��1�֡�����0�֡�
	�����ǣ���� ��ֻ����ıȷ֣�
	����ǣ�ÿ֧������ܷ֣��Ӹߵ�����������ܷ���ͬ�����ֵ����������
	�ѵ㣺
	���룺
	a - b
	3 : 4
	c - d
	4 : 1
	�������붼�пո񣬲�������str1[0] str1[1] str2[2]װ������Ჶ�񲻵���Ӧ������
	�����
	1. ����û�����������£���������ж���������Ⱥ󣬶����붼���лس��ģ����cout��Ҫ�ŵ�while(cin >> str1 >> str2)ѭ�����
	2. �ֵ�����sort  + lambda���ʽ����lambda���ʽ��ôдҲ��һ���ѵ�
*/

int main() {
	string str1, str2;
	vector<pair<int, char>>vec;
	unordered_map<char, int>hash; //�ֵ�������
	while (getline(cin, str1) && getline(cin, str2)) { //�����пո�Ķ���Ҫ��getline(cin, str)
		bool flag1 = false;
		bool flag2 = false;
		char chr1, chr2;
		int n1 = 0, n2 = 0;
		//�ַ���ȡ
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] >= 'a' && str1[i] <= 'z' && !flag1) {
				chr1 = str1[i];
				flag1 = true;
			}
			else if (str1[i] >= 'a' && str1[i] <= 'z' && flag1) {
				chr2 = str1[i];
			}
		}
		//������ȡ
		for (int i = 0; i < str2.size(); i++) {
			if (str2[i] >= '0' && str2[i] <= '9' && !flag2) {
				n1 = str2[i];
				flag2 = true;
			}
			else if (str2[i] >= '0' && str2[i] <= '9' && flag2) {
				n2 = str2[i];
			}
		}
		//����
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
	stable_sort(vec.begin(), vec.end(), [](const pair<int, char>& p1, const pair<int, char>& p2) { //ע����stable_sort
		return p1.first > p2.first;
		});

	////	�����Ҫ�ֵ�������ô�죿
	//	sort(vec.begin(), vec.end(), [](const pair<int, char>& p1, const pair<int, char>& p2) { //ע����stable_sort
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
	��Ŀ2����˾��������Ϸ��Ա����������ɫ��ñ�ӣ���ɫ���ָ����������ڸ���һ�����飬���磺��1��1��2����������ǵ�һ��Ա������������һ����ɫ��ñ����һ���ˣ�
	�ڶ���Ա������������һ����ɫ��ñ����1������3��Ա������������һ����ɫ��ñ����2����������ӵ����Ӧ���ǲμ������Ϸ�����ٵ�Ա���������5��
	���룺[n1, n2, .. nk] k < 1000
	�������СԱ����Ŀ
	�ѵ㣺����ֵ�Ļ�ȡ����ʱֻ���������뿴��������<10�������Ҳ����ֻ���ǵ�������ֻ��һλ�����������ֻ��40%ͨ����
	��������stringstream����ȡ
*/
int main() {
	string str;

	while (getline(cin, str)) {
		vector<int>vec(1000, 0);
		//����һ�����ţ�ע���������ĸ��������Ҫ�ɶ�ƥ��
		str.erase(str.find_first_of('['), 1);
		//str.erase(str.find_last_of(']'), 1);
		stringstream ss(str); //stringstream��Ҳ����������ʼ��
		int n;
		char chr;
		while (ss >> n >> chr) {
			vec[n]++;
		}
		//������������
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
	��Ŀ3��
	�����������ַ�������һ����Ϊĸ�����ڶ�����Ϊ�Ӵ��������������и��α꣬�α�ÿ�ο�������һ���������һ��
	�ε�����������ƾ��ε����ұߣ����ұ�ͬ�������ڸ����������ַ������α�ĳ�ʼλ�ã��������α��ҳ��Ӵ���ĸ����λ�õ���С�ƶ����������磺���룺asdfg adf 0 Ӧ�����3
	
*/