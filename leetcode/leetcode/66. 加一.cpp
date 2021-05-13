#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������ģ���λ

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) return digits;
        }
        //����9��99��999��9999�����֣��ھ����������ѭ���󣬻��ɣ�0��00��000��0000����ʱ����Ҫ��һλ���ҵ�һλ��1
        //�����10��100��1000��10000
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};