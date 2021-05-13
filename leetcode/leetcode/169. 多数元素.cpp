#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：哈希表

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         unordered_map<int, int> hash;
         int n = nums.size();
         for(int i = 0; i < n; i++){
             hash[nums[i]]++;
             if(hash[nums[i]] > int(n / 2)){
                 return nums[i];
             }
         }
         return -1;
     }
 };

 /**********************************************************************************************************
 方法2：排序+取中

 说明：

 时间复杂度与空间复杂度：O(nlogn)  O(1)

 涉及到的知识点：

 ***********************************************************************************************************/

  class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         return nums[int(nums.size() / 2)];
     }
 };



  /**********************************************************************************************************
方法3：利用一个变量进行统计

说明：

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/

  class Solution {
  public:
      int majorityElement(vector<int>& nums) {
          int n = nums.size();
          int ele = -1;
          int cnt = 0;
          for (int i = 0; i < n; i++) {
              if (cnt == 0) {
                  ele = nums[i];
                  cnt++;
              }
              else if (ele == nums[i]) cnt++;
              else cnt--;
          }
          return ele;
      }
  };