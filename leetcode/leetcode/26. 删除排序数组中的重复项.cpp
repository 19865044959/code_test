#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：快慢双指针

说明：
	1. 用一个指针指向第一个元素,nums[i]作为慢指针
	用另一个指针指向第二个元素,nums[j]作为快指针
	当nums[i] == nums[j]时，快指针指向下一个元素，j++
	当nums[i] != nums[j]时，慢指针指向下一个元素，i++，然后将快指针的值给慢指针，nums[i] = nums[j]
	一直循环直到j >= n时结束
	2. 如果是一个无序的让你将不重复的元素重新升序排列到前面呢？可以先排序，再老套路即可

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		int i = 0;
		for (int j = 1; j < n; j++) {
			if(nums[i] != nums[j]){
				nums[++i] = nums[j];
			}
		}
		return i + 1;
	}
};