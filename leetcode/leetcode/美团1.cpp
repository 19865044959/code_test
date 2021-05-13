/*
距离问题
输入n，k，然后输入n个数字，数字为0代表Alis的房子可能出现在这里，数字非0代表其他的房子（数字的值就是价格），
你要买一个房子，然后距离Alis的房子的期望距离最近。

暴力法：
用一个数组记录Alis的房子，遍历n次，每次当价格 <= k时，就计算所有跟Alis房子距离之和，小于更新，否则不理会，返回最后的idx即可
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