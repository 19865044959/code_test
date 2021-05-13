#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1��ͳ�Ʒ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
����2��ͳ�Ʒ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

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
