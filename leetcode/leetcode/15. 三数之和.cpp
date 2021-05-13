#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����������+˫ָ��

˵����
    �����
    https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end()); //�Ż�1
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) return ans; //�Ż�2
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    //��ֹԪ���ظ�
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    //ָ���¸�Ԫ�أ�����Ҫ����ͬʱ�ı���п���ʹ���¸���Ϊ0
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) { //�Ż�3
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};