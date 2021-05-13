#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：超时

时间复杂度与空间复杂度：O(n^2)   O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0) return{};
        vector<int> counts(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++) {
            int cnt = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) cnt++;
            }
            counts[i] = cnt;
        }
        return counts;
    }
};