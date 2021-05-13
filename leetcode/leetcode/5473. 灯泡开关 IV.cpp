#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//����1����ʵģ�⣬��ʱ
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

//����2�����ص������ٷ�ת������û�б�Ҫ�����������ѷ�ת��ģ�����
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

//����3������д��
class Solution {
public:
    int minFlips(string target) {
        int org = 0;
        int cnt = 0;
        for (auto k : target) {
            int i = k - '0';
            if (org ^ i == 1) { //��λ���д������ͬΪ0����ͬΪ1
                org ^= 1; //һ������1����������ȡ��
                cnt++;
            }
        }
        return cnt;
    }
};