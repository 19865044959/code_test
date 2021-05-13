#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：两有序数组合并为一个有序数组方法、求中位数方法

说明：

时间复杂度与空间复杂度：O(m+n)  O(m+n)

涉及到的知识点：

***********************************************************************************************************/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> nums3(n);
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                nums3[k++] = nums2[j++];
            }
            else {
                nums3[k++] = nums1[i++];
            }
        }
        while (i < nums1.size()) {
            nums3[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            nums3[k++] = nums2[j++];
        }
        if (n & 0x01) return double(nums3[int(n / 2)]);
        else {
            return (double(nums3[n / 2 - 1]) + double(nums3[n / 2])) / 2;
        }
    }
};