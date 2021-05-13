#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1����ϣ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
 ����2������+ȡ��

 ˵����

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)  O(1)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/

  class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         return nums[int(nums.size() / 2)];
     }
 };



  /**********************************************************************************************************
����3������һ����������ͳ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

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