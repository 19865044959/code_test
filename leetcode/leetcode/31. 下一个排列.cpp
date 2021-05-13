#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：原地(分析法)

说明：
    1. 选择最后一位，即nums[n-1]，查找与之最近的大于nums[n-1]的数，如果找到，不妨假设是nums[k1]，index = k1
    2. 选择倒数第二位，即nums[n-2]，查找与之最近的大于nums[n-2]的数，如果找到，不妨假设是nums[k2-1]，index = k2
    3. 重复上述过程，直到nums的所有位全部被遍历，得到结果为k1 k2 k3 ... kn-1
    4. kchose = max(k1, k2, k3 ... kn-1)
    5. 交换kchose与对应的位p的值
    6. 顺序排列nums[kchose+1]  nums[kchose+2] ... nums[end - 1]、
    7. 特殊情况判断：如果kchose == -1，说明一个k值都没有，此时nums是最大值，需要翻转数组即可

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    //辅助函数作用：寻找在第k位前，小于nums[k]的最右侧值
    int tempfcn(vector<int>& nums, int k) {
        for (int i = k - 1; i >= 0; i--) {
            if (nums[i] < nums[k]) {
                return i;
            }
        }
        return k; //意味着nums[k]是最小值
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        int maxindex = -1;
        int p = -1;
        for (i = n - 1; i >= 0; i--) {
            int res = tempfcn(nums, i);
            if (res == i) continue;
            else {
                if (maxindex < res) {
                    maxindex = res;
                    p = i;
                }
            }
        }
        if (maxindex != -1) {
            int temp = nums[maxindex];
            nums[maxindex] = nums[p];
            nums[p] = temp;
            sort(nums.begin() + maxindex + 1, nums.end());
        }
        else {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        }
    }
};