#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

/**********************************************************************************************************
方法：贪心

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

/*我的思路：
    可以证明，最小的能够将[1,x]全部表示出来的数组为1 2 4 8 ... 2^n
    所以查找nums，如果没有1 2 4 ... 那么就补充进来即可
    但是按照这种想法，例子[1 3]  6 通不过，原因是：只需要补充2即可把1 2 3 4 5 6全部表示出来
    但是按照上述来算，则需要补充 2 4
*/
// class Solution {
// public:
//     int minPatches(vector<int>& nums, int n) {
//         int k = floor(log(n) - log(2)) + 1;
//         int count = 0;
//         int length = nums.size();
//         for(int i = 0; i <= k; i++){
//             if(find(nums.begin(), nums.end(), 1 << i) != nums.end()) continue;
//             count++;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            }
            else {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};