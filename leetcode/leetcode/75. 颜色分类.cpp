#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：统计法

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     void sortColors(vector<int>& nums) {
         vector<int> sum(3, 0);
         int n = nums.size();
         for(int i = 0; i < n; i++){
             sum[nums[i]]++;
         }
         for(int i = 0; i < n; i++){
             if(sum[0]-- > 0){
                 nums[i] = 0;
             }
             else if(sum[1]-- > 0){
                 nums[i] = 1;
             }
             else{
                 nums[i] = 2;
             }
         }
     }
 };

 /**********************************************************************************************************
方法2：统计法

说明：

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     void sortColors(vector<int>& nums) {
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             int flag = 0;
             for (int j = n - 1; j > i; j--) {
                 if (nums[j - 1] > nums[j]) {
                     int temp = nums[j - 1];
                     nums[j - 1] = nums[j];
                     nums[j] = temp;
                     flag = 1;
                 }
             }
             if (flag == 0) return;
         }
     }
 };
