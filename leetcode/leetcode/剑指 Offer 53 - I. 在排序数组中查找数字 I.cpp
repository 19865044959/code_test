#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
    类型：查找已排序数组里，相同数字的首部idx与尾部idx，即 b c a a a a d e
    思想：查找a的左边，即c元素；查找到a元素的右边，即d元素，即左右边界
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        //找右边第一个target
        int idx_right = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1; //由于我想找到右边边界，这个边界值是 > target的，那么我就放心的left = mid + 1
            else right = mid - 1; //由于我想找到右边的第一个 > target数，所以我要缩减区间，我这样一缩减，有两种选择：right = mid，这样有可能造成死循环；那么我就让right  = mid - 1，那么最后一定是：right指向target，left指向右侧区间，返回left即可
        }
        if (right < 0 || nums[right] != target) return 0;
        idx_right = left;

        left = 0; right = n - 1;
        //找左边第一个target
        int idx_left = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        idx_left = right;
        return idx_right - idx_left - 1;
    }
};