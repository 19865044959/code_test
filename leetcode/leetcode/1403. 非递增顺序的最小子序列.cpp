#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
����������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)  O(n)

�漰����֪ʶ�㣺ʵ��accumulate����û��ֱ��forѭ��Ч�ʸ�

***********************************************************************************************************/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> ans;

        // int numSumTotal = accumulate(nums.begin(), nums.end(), 0);
        int numSumTotal = 0;
        for (int j = 0; j < nums.size(); j++) {
            numSumTotal += nums[j];
        }

        int numSumNow = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans.emplace_back(nums[i]);
            numSumNow += nums[i];
            if (numSumNow > numSumTotal / 2) break;
        }
        return ans;
    }
};