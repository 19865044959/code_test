#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
//升序数组，有负数、一堆0、正数，要求找到最后一个负数与第一个正数，要求O(logn)

class Solution {
public:
	pair<int, int> solve(vector<int>& nums) {
		int n = nums.size();
		//第一个正数
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] <= 0) left = mid + 1; //由于找的是正数，所以放心大胆的加，并且left里面可能包含第一个正数
			else right = mid - 1; //有可能越界，所以答案下标一定不是right
		}
		int firstP = nums[left]; //实际上最后是：left(1) right(0)，因此返回是正确的
		//最后一个负数
		left = 0; right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= 0) right = mid - 1;
			else left = mid + 1;
		}
		int lastN = nums[right];
		return { lastN, firstP };
	}
private:
};

int main() {
	vector<int>temp({ -3, -3, -2, -1, 0, 0, 0, 1, 3, 3, 5 });
	Solution a;
	auto res = a.solve(temp);

	return 0;
}