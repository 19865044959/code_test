#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：通过二分查找查找一个数

说明：
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/

时间复杂度与空间复杂度：O(logn) O(1)

涉及到的知识点：

***********************************************************************************************************/
int binarySearch1(vector<int>& nums, int target) {
	int n = nums.size();
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

/**********************************************************************************************************
方法：实现lower_bound，即在升序序列中，查找到第一个 >= target的数

说明：

时间复杂度与空间复杂度：O(logn) O(1)

涉及到的知识点：

***********************************************************************************************************/
int binarySearch2(vector<int>& nums, int target) {
	int n = nums.size();
	if (n == 0) return -1;
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target) right = mid - 1;
		else left = mid + 1;
	}
	if (left == n) return -1; //说明没找到
	else return left;
}

/**********************************************************************************************************
方法：实现upper_bound，即在升序序列中，查找到第一个 > target的数

说明：

时间复杂度与空间复杂度：O(logn) O(1)

涉及到的知识点：

***********************************************************************************************************/

int binarySearch3(vector<int>& nums, int target) {
	int n = nums.size();
	if (n == 0) return -1;
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] <= target) left = mid + 1;
		else {
			right = mid - 1;
		}
	}
	if (left == n) return-1;
	else return left;
}

//测试用
int main() {
	vector<int>nums1{ 2, 3, 3,3,3,3,5, 7 };
	vector<int>nums2{ 1, 2, 2, 2, 3 };
	int ans1 = binarySearch2(nums1, 3); //
	int ans2 = binarySearch3(nums1, 3);
	int ans3 = binarySearch2(nums1, 7);
	int ans4 = binarySearch3(nums1, 7);
	int ans5 = binarySearch3(nums1, 1);
	return 0;
}