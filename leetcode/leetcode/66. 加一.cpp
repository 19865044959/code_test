#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：模拟进位

说明：

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

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
        //形如9、99、999、9999等数字，在经历过上面的循环后，会变成：0、00、000、0000，这时候需要加一位并且第一位变1
        //即变成10、100、1000、10000
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};