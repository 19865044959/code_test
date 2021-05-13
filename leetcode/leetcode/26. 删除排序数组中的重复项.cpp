#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����������˫ָ��

˵����
	1. ��һ��ָ��ָ���һ��Ԫ��,nums[i]��Ϊ��ָ��
	����һ��ָ��ָ��ڶ���Ԫ��,nums[j]��Ϊ��ָ��
	��nums[i] == nums[j]ʱ����ָ��ָ����һ��Ԫ�أ�j++
	��nums[i] != nums[j]ʱ����ָ��ָ����һ��Ԫ�أ�i++��Ȼ�󽫿�ָ���ֵ����ָ�룬nums[i] = nums[j]
	һֱѭ��ֱ��j >= nʱ����
	2. �����һ����������㽫���ظ���Ԫ�������������е�ǰ���أ�����������������·����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

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