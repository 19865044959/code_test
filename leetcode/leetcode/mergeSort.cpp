#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：归并排序

说明：

时间复杂度与空间复杂度：O(nlogn) O(n)

涉及到的知识点：

***********************************************************************************************************/
void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int>temp(nums.size());
	for (int k = left; k <= right; k++) {
		temp[k] = nums[k];
	}
	int i = left;
	int j = mid + 1;
	for (int k = left; k <= right; k++) {
		if (i == mid + 1) {
			nums[k] = temp[j];
			j++;
		}
		else if (j == right + 1) {
			nums[k] = temp[i];
			i++;
		}
		else if (temp[i] <= temp[j]) {
			nums[k] = temp[i];
			i++;
		}
		else {
			nums[k] = temp[j];
			j++;
		}
	}
}

void mergeSort(vector<int>& nums, int left, int right) {
	if (left == right) return;
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	if (nums[mid] <= nums[mid + 1]) return;
	merge(nums, left, mid, right);	
}

int main() {
	vector<int> temp({ 233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004 });
	mergeSort(temp, 0, temp.size() - 1);
	return 0;
}