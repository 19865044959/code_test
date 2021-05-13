#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：超时

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
         for(int i = 0; i < n - 1; i++){
             for(int j = i + 1; j < n; j++){
                 if(numbers[i] + numbers[j] == target) return{i + 1, j + 1};
             }
         }
         return {-1, -1};
     }
 };


 /**********************************************************************************************************
方法：两边哈希

说明：
    这个方法有点儿啰嗦，有可能要做3次O(n)循环，只不过两数之和I中使用，我在这里强行使用，不推荐

时间复杂度与空间复杂度：
    O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
         unordered_map<int, int> hash;
         for(int i = 0; i < n; i++){
             hash[numbers[i]] = i;
         }
         for(int i = 0; i < n; i++){
             if(hash.find(target - numbers[i]) != hash.end() && hash[numbers[i]] != hash[target - numbers[i]]){
                 int lower, upper;
                 if(hash[numbers[i]] > hash[target - numbers[i]]){
                     lower = hash[target - numbers[i]];
                     upper = hash[numbers[i]];
                 }
                 else{
                     upper = hash[target - numbers[i]];
                     lower = hash[numbers[i]];
                 }
                 return {lower + 1, upper + 1};
             }
         }
         //不加下面一行代码通不过，原因是：与前面的两数之和不同的是：本题允许使用相同元素之和等于target，只要这两个相同元素下标不同即可
         for(int i = 0; i < n - 1; i++){
             if(numbers[i] == numbers[i + 1] && 2 * numbers[i] == target) return {i + 1, i + 2};
         }
         return {-1, -1};
     }
 };


/**********************************************************************************************************
方法：双指针

说明：
    见到无序数组，可以考虑哈希表
    见到有序数组，可以考虑双指针与二分查找

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
         int left = 0;
         int right = n - 1;
         while (left < right) {//不允许使用相同位置的元素两次
             if (target == numbers[left] + numbers[right]) return { left + 1, right + 1 };
             else if (target > numbers[left] + numbers[right]) {
                 left++;
             }
             else {
                 right--;
             }
         }
         return { -1, -1 };
     }
 };

