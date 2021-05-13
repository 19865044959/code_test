#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
���������������������ڷ����Ľ���

˵����
    �չ�
ʱ�临�Ӷ���ռ临�Ӷȣ�
	O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sumVal = 0;
            for (int j = i; j < n; j++) {
                sumVal += nums[j];
                maxSum = max(maxSum, sumVal);
            }
        }
        return maxSum;
    }
};

