#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：

时间复杂度与空间复杂度：O(n^2)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();
         for(int i = 0; i < n - 1; i++){
             for(int j = i + 1; j < n; j++){
                 if(nums[i] + nums[j] == target){
                     return {i, j};
                 }
             }
         }
         return {};
     }
 };



 /**********************************************************************************************************
 方法：哈希表

 说明：
    用空间去换时间

 时间复杂度与空间复杂度：O(n)  O(n)

 涉及到的知识点：

 ***********************************************************************************************************/
 class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> a;
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             a[nums[i]] = i;
         }
         for (int i = 0; i < n; i++) {
             int temp = target - nums[i];
             if (a.find(temp) != a.end() && a[temp] != i) {
                 return { i, a[temp] }; //注意这里如果填写了return {a[nums[i]],a[temp]}的话有些例子是无法通过的：比如
                                                 //输入数组：nums = {3, 3}, target = 6;答案是{0, 1},但是由于两个重复的元素会覆盖前一个
                                                 //的value值，因此返回的是{1, 1}导致错误！
             }
         }
         return {};
     }
 };