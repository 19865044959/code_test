#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

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
���������ֲ��ҷ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn)  O(1)

�漰����֪ʶ�㣺

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
������STL��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int searchInsert(vector<int>& nums, int target) {
         return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
     }
 };