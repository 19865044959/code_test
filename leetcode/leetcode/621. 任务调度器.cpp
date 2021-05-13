#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������̰���㷨

˵����
	Ͱ˼��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> res(26); //hash��
        int temp = 1;
        int len = tasks.size();
        for (int i = 0; i < len; i++) {
            res[tasks[i] - 'A']++; //��¼hash��
        }
        sort(res.begin(), res.end(), [](const int& a, const int& b) {
            return a > b; //�ɴ�С�����õ���lambda���ʽ
            });
        for (int i = 1; i < 26; i++) {
            if (res[0] == res[i]) temp++; //��¼��Ŀ��������������
        }
        return max(len, (n + 1) * (res[0] - 1) + temp); //�����ȴʱ�䲻Ϊ0����ô(res[0] - 1) + temp > len�������ȴʱ��Ϊ0����ô len >= (n + 1) * (res[0] - 1) + temp
    }
};
