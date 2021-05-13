#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1���������鴢��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

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
 ����2���������鷭ת

 ˵����

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

 �漰����֪ʶ�㣺

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