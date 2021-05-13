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

时间复杂度与空间复杂度：
	O(n)
	O(n)不符合题目要求

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     int firstMissingPositive(vector<int>& nums) {
         unordered_map<int, int> hash;
         int n = nums.size();
         for(auto k : nums){
              hash[k]++;
         }
         for(int i = 1; i <= n; i++){
             if(hash.find(i) != hash.end()) continue;
             else return i;
         }
         return n + 1; //当找了一遍也没找到这个正数时，应该考虑的是nums里面所有的都是正数，并且是1-n乱序，因此我们此时只需要返回n+1即可，适用例子：[]、[1]、[3,1,2]等等
     }
 };


 /**********************************************************************************************************
 方法1：原地哈希

 说明：
    仿照哈希表的储存，并结合数组自身的特点，将正数i+1放到位置i上

 时间复杂度与空间复杂度：
     O(n)
     O(1)

 涉及到的知识点：
    原地算法：原地算法就是不利用多余的空间（比如说临时创建的维数为n的数组），在原给定的数据数组上直接修改数组
    从而减少空间复杂度的算法
 ***********************************************************************************************************/

 class Solution {
 public:
     int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) { //两个交换数不能相等，否则会进入死循环
                 swap(nums, i, nums[i] - 1);
             }
         }

         for (int i = 0; i < n; i++) {
             if (nums[i] - 1 != i) return i + 1;
         }
         return n + 1;
     }
 private:
     void swap(vector<int>& nums, int i, int j) {
         int temp = nums[i];
         nums[i] = nums[j];
         nums[j] = temp;
     }
 };