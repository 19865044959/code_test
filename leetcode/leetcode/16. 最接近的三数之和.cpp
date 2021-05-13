#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^3)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int threeSumClosest(vector<int>& nums, int target) {
         int n = nums.size();
         int distance = INT_MAX;
         int numSum;
         for(int i = 0; i < n - 2; i++){
             for(int j = i + 1; j < n - 1; j++){
                 for(int m = j + 1; m < n; m++){                                      
                     if(distance > abs(nums[i] + nums[j] + nums[m] - target)){
                         distance = abs(nums[i] + nums[j] + nums[m] - target);
                         numSum = nums[i] + nums[j] + nums[m];  
                     }
                 }
             }
         }
         return numSum;
     }
 };


 /**********************************************************************************************************
����������+˫ָ�뷨

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2)  O(logn)->�������ÿռ�

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int threeSumClosest(vector<int>& nums, int target) {
         int ans = INT_MAX / 2;
         auto find = [&](int nSum)->void {
             if (abs(ans - target) > abs(nSum - target)) {
                 ans = nSum;
             }
         };
         sort(nums.begin(), nums.end());
         int i, j, numSum;
         for (int m = 0; m < nums.size() - 2; m++) {
             if (m > 0 && nums[m] == nums[m - 1]) m++;
             i = m + 1;
             j = nums.size() - 1;
             while (i < j) {
                 numSum = nums[i] + nums[j] + nums[m];
                 if (numSum == target) return target;
                 find(numSum);
                 if (numSum > target) {
                     j--;
                     // while (i < j - 1 && nums[j] == nums[j - 1]) j--;
                 }
                 else {
                     i++;
                     // while (i + 1 < j && nums[i] == nums[i + 1]) i++;
                 }
             }
         }
         return ans;
     }
 };