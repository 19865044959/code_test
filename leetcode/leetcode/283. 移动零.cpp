#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������˫ָ�뷨

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        int j = -1;
        for (int k = 0; k < n; k++) {
            if (nums[k] == 0 && i == -1) i = k;
            if (i != -1 && nums[k] != 0) {
                j = k;
                break;
            }
        }
        while (i >= 0 && i < n && j >= 0 && j < n) {
            if (nums[j] != 0) {
                nums[i++] = nums[j++];
            }
            else {
                j++;
            }
        }
        for (;i >= 0 && i < n; i++) {
            nums[i] = 0;
        }
    }
};