#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//这题找的是nums[i] != i的这个数组的最左边的元素对应的下标
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == nums[mid]) left = mid + 1; //最后一定是right left，其中right指向的是最后一个nums[i] == i，因此返回left即可
            else {
                right = mid - 1; //
            }
        }
        return left;
    }
};