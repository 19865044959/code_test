#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������ͨ�����ֲ��Ҳ���һ����

˵����
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn) O(1)

�漰����֪ʶ�㣺

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
������ʵ��lower_bound���������������У����ҵ���һ�� >= target����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn) O(1)

�漰����֪ʶ�㣺

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
	if (left == n) return -1; //˵��û�ҵ�
	else return left;
}

/**********************************************************************************************************
������ʵ��upper_bound���������������У����ҵ���һ�� > target����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn) O(1)

�漰����֪ʶ�㣺

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

//������
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