#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������ѭ��������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int Fminus2 = 0;
        int Fminus1 = 1;
        int F;
        for (int i = 2; i <= n; i++) {
            F = (Fminus2 + Fminus1) % 1000000007;
            Fminus2 = Fminus1;
            Fminus1 = F;
        }
        return F;
    }
};