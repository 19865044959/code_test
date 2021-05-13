#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����������������ϲ�Ϊһ���������鷽��������λ������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m+n)  O(m+n)

�漰����֪ʶ�㣺

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