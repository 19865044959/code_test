#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：排序

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int findRepeatNumber(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         for(int i = 0; i < nums.size() - 1; i++){
             if(nums[i] == nums[i+1]) return nums[i];
         }
         return -1;
     }
 };

 /**********************************************************************************************************
方法2：哈希表

说明：

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int findRepeatNumber(vector<int>& nums) {
         vector<int> hash(nums.size());
         for(int i = 0; i < nums.size(); i++){
             if(hash[nums[i]]){
                 return nums[i];
             }
             else{
                 hash[nums[i]]++;
             }
         }
         return -1;
     }
 };


 /**********************************************************************************************************
方法3：原地算法

说明：

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int findRepeatNumber(vector<int>& nums) {
         for (int i = 0; i < nums.size(); i++) {
             while (i != nums[i]) {
                 if (nums[i] == nums[nums[i]]) {
                     return nums[i];
                 }
                 else {
                     int temp = nums[i];
                     nums[i] = nums[temp];
                     nums[temp] = temp;
                 }
             }
         }
         return -1;
     }
 };



 /*
    变式：有一个数组，它的长度是n+1，而里面的数字范围是[1,n]，这说明，这个数组里至少有一个重复的数字
    请找出这个数字，要求：空间复杂度O(1)并且不能够修改原来的数组（即原地算法失效）
*/
//方法：二分法
 class Solution {
 public:
     int findRepeatNumber(vector<int>& nums) {
         int n = nums.size();
         int start = 1;
         int end = n - 1;
         while (start <= end) {
             int middle = (end - start) >> 2 + start;
             int count = countRange(start, middle, nums);
             if (end == start) {
                 if (count > 1) return count;
                 else break;
             }
             else {
                 if (count > middle - start + 1) {
                     end = middle;
                 }
                 else {
                     start = middle + 1;
                 }
             }
         }
         return -1;
     }

     int countRange(int start, int end, vector<int>& nums) {
         int count = 0;
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             if (nums[i] >= start && nums[i] <= end) {
                 count++;
             }
         }
         return count;
     }
 };