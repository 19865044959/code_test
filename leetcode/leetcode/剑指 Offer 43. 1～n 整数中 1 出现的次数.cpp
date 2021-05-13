//˼��·��������
//����˼��·������1~n��n��������1���ֵĴ��� <-> �������ֵĸ�λ��ʮλ����λ��ǧλ...��1���ֵĴ���֮��

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        int low = 0;
        int cur = n % 10;
        int high = n / 10;
        long digit = 1;
        int res = 0;
        while (cur != 0 || high != 0) {
            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};