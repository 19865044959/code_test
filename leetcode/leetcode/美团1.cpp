/*
��������
����n��k��Ȼ������n�����֣�����Ϊ0����Alis�ķ��ӿ��ܳ�����������ַ�0���������ķ��ӣ����ֵ�ֵ���Ǽ۸񣩣�
��Ҫ��һ�����ӣ�Ȼ�����Alis�ķ��ӵ��������������

��������
��һ�������¼Alis�ķ��ӣ�����n�Σ�ÿ�ε��۸� <= kʱ���ͼ������и�Alis���Ӿ���֮�ͣ�С�ڸ��£�������ᣬ��������idx����
*/
#include<iostream>
#include<assert.h>
#include <vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

int main() {
    int n;
    int k;
    while (cin >> n >> k) {
        int bestIdx;
        int bestDiff = 100000;
        vector<int>idx;
        vector<int>prices(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> prices[i];
            if (prices[i] == 0) idx.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (prices[i] != 0 && prices[i] <= k) {
                int tempDiff = 0;
                for (auto id : idx) {
                    tempDiff += abs(id - i);
                }
                if (tempDiff < bestDiff) {
                    bestDiff = tempDiff;
                    bestIdx = i;
                }
            }
        }
        cout << bestIdx << endl;
    }
    return 0;
}