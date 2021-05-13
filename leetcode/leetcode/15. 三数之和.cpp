#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：排序+双指针

说明：
    详见：
    https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/

时间复杂度与空间复杂度：O(n^2)  O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end()); //优化1
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) return ans; //优化2
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    //防止元素重复
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    //指向下个元素，必须要两个同时改变才有可能使得下个和为0
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) { //优化3
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};