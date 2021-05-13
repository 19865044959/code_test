#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int searchInsert(vector<int>& nums, int target) {
         int n = nums.size();
         int i;
         for(i = 0; i < n; i++){
             if(nums[i] >= target) return i;
         }
         return i;
     }
 };

 /**********************************************************************************************************
方法：二分查找法

说明：

时间复杂度与空间复杂度：O(logn)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int searchInsert(vector<int>& nums, int target) {
         int low = 0;
         int high = nums.size() - 1;
         while(low < high){
             int medium = low + (high - low) / 2;
             if(nums[medium] == target) return medium;
             if(nums[medium] > target){
                 high = medium - 1;
             }
             else{
                 low = medium + 1;
             }
         }
         int maxVal = max(low, high);
         if(nums[maxVal] >= target) return maxVal;
         else return maxVal + 1;
     }
 };

 /**********************************************************************************************************
方法：STL库

说明：

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int searchInsert(vector<int>& nums, int target) {
         return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
     }
 };