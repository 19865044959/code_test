#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

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
����2����ϣ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

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
����3��ԭ���㷨

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

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
    ��ʽ����һ�����飬���ĳ�����n+1������������ַ�Χ��[1,n]����˵�������������������һ���ظ�������
    ���ҳ�������֣�Ҫ�󣺿ռ临�Ӷ�O(1)���Ҳ��ܹ��޸�ԭ�������飨��ԭ���㷨ʧЧ��
*/
//���������ַ�
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