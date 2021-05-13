#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
��������������

˵����
    1. ��ѡ����mid����midΪ�ֽ��ߣ��϶���һ���ǵ���������
    2. ע��Ⱥţ��ѵ�����32���Ǹ��Ⱥţ�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) { //����Ⱥź�Ҫ����������mid == 0ʱ��˵������ָ����ͬԪ�أ���ȻҲ�ǵ��������ģ�ֻ������һ��Ԫ�أ�
                if (nums[0] <= target && target < nums[mid]) right = mid - 1; 
                else left = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[n - 1]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};