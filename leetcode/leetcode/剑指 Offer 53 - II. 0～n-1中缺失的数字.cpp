#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//�����ҵ���nums[i] != i��������������ߵ�Ԫ�ض�Ӧ���±�
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == nums[mid]) left = mid + 1; //���һ����right left������rightָ��������һ��nums[i] == i����˷���left����
            else {
                right = mid - 1; //
            }
        }
        return left;
    }
};