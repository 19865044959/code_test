#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：二分查找某个具体数+左移与右移

说明：

时间复杂度与空间复杂度：O(logn) - O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> searchRange(vector<int>& nums, int target) {
         int n = nums.size();
         int left = 0;
         int right = n - 1;
         int start, end;
         while(left <= right){
             int medium = left + (right - left) / 2;
             if(nums[medium] == target){
                 int temp = medium;
                 while(temp - 1 >= 0 && nums[temp-1] == target){
                     temp--;
                 }
                 start = temp;
                 temp = medium;
                 while(temp + 1 < n && nums[temp+1] == target){
                     temp++;
                 }
                 end = temp;
                 return {start, end};
             }
             else if(nums[medium] > target){
                 right = medium - 1;
             }
             else{
                 left = medium + 1;
             }
         }
         return {-1, -1};
     }
 };

 /**********************************************************************************************************
方法：直接通过二分查询左边界与右边界得到答案

说明：

时间复杂度与空间复杂度：O(logn)  O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        return { left, right };
    }
private:
    int leftBound(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (left == n) return -1;
        else return nums[left] == target ? left : -1;
    }

    int rightBound(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (left == 0) return -1;
        else return nums[left - 1] == target ? left - 1 : -1;
    }
};