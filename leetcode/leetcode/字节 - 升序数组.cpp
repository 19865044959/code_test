#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
//�������飬�и�����һ��0��������Ҫ���ҵ����һ���������һ��������Ҫ��O(logn)

class Solution {
public:
	pair<int, int> solve(vector<int>& nums) {
		int n = nums.size();
		//��һ������
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] <= 0) left = mid + 1; //�����ҵ������������Է��Ĵ󵨵ļӣ�����left������ܰ�����һ������
			else right = mid - 1; //�п���Խ�磬���Դ��±�һ������right
		}
		int firstP = nums[left]; //ʵ��������ǣ�left(1) right(0)����˷�������ȷ��
		//���һ������
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