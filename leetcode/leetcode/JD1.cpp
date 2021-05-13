#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<set>
#include<map>
#include <stack>
using namespace std;

/*
    质数串问题：定义k = max出现次数 - min出现次数，当k是质数时，说明是质数串，给个无限循环的字符串，求前n个字符串组成的子串是否是质数串
    A 82%没全通过
*/
int main() {
    string S;
    int n;
    while (cin >> S >> n) {
        vector<int> hash(26, 0);
        for (auto chr : S) {
            hash[chr - 'a']++;
        }
        int k = n / S.size();
        int c = n % S.size();
        for (int i = 0; i < 26; i++) {
            hash[i] *= k;
        }
        for (int i = 0; i < c; i++) {
            hash[S[i] - 'a']++;
        }
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        for (int i = 0; i < 26; i++) {
            max1 = max(max1, hash[i]);
            if (hash[i]) min1 = min(min1, hash[i]);
        }
        int ans = max1 - min1;
        bool flag = false;
        if (ans) {
            for (int i = 2; i <= sqrt(ans); i++) {
                if (ans % i == 0) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
        cout << ans << endl;
    }
    return 0;
}