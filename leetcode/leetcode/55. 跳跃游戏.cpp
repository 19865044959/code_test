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

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (i > k) return false;
            if (n - 1 <= k) return true;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};