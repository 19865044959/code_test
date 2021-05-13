#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//方法1：真实模拟，超时
class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        string ans(n, '0');
        int cnt = 0;
        for (int i = 0;i < n;) {
            if (ans == target) break;
            while (ans[i] == target[i] && i < n) i++;
            for (int j = i; j < n; j++) {
                if (ans[j] == '0')  ans[j] = '1';
                else ans[j] = '0';
            }
            cnt++;
            i++;
        }
        return cnt;
    }
};

//方法2：返回的是最少翻转次数，没有必要像上面那样把翻转都模拟出来
class Solution {
public:
    int minFlips(string target) {
        int org = 0;
        int cnt = 0;
        for (auto k : target) {
            int i = k - '0';
            if (org != i) {
                cnt++;
                org = i;
            }
        }
        return cnt;
    }
};

//方法3：大神写法
class Solution {
public:
    int minFlips(string target) {
        int org = 0;
        int cnt = 0;
        for (auto k : target) {
            int i = k - '0';
            if (org ^ i == 1) { //按位异或写法，相同为0，不同为1
                org ^= 1; //一个数与1异或，这个数会取反
                cnt++;
            }
        }
        return cnt;
    }
};