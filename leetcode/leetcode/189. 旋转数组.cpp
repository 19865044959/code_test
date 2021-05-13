#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：利用数组储存

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     void rotate(vector<int>& nums, int k) {
         int n = nums.size();
         vector<int> temp(n);
         for(int i = 0; i < n; i++){
             temp[(i + k) % n] = nums[i];
         }
         nums = temp;
     }
 };




 /**********************************************************************************************************
 方法2：利用数组翻转

 说明：

 时间复杂度与空间复杂度：O(n) O(1)

 涉及到的知识点：

 ***********************************************************************************************************/

 class Solution {
 public:
     void reverse(vector<int>& nums, int start, int end) {
         while (start < end) {
             swap(nums[start], nums[end]);
             start++;
             end--;
         }
     }

     void rotate(vector<int>& nums, int k) {
         int n = nums.size();
         k = k % n;
         reverse(nums, 0, n - 1);
         reverse(nums, 0, k - 1);
         reverse(nums, k, n - 1);
     }
 };