#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

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