#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：二分搜索

说明：
    1. 你选择了mid后，以mid为分界线，肯定有一边是单调递增的
    2. 注意等号，难点在于32行那个等号！

时间复杂度与空间复杂度：O(logn) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) { //这个等号很要命！！！当mid == 0时，说明两个指向相同元素，当然也是单调递增的（只不过是一个元素）
                if (nums[0] <= target && target < nums[mid]) right = mid - 1; 
                else left = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[n - 1]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};