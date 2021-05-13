#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

// //������ O(n^2)
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int res = 0;
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i + 1; j < nums.size(); j++){
//                 if(nums[i] > nums[j]) res++;
//             }
//         }
//         return res;
//     }
// };

//�鲢�����Ӧ�ã��ڹ鲢����ʱ������ͳ��������
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> temp(n);
        return mergeSort(nums, 0, n - 1, temp);
    }
    int mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if (left == right) return 0;
        int mid = left + (right - left) / 2;
        int leftCount = mergeSort(nums, left, mid, temp);
        int rightCount = mergeSort(nums, mid + 1, right, temp);
        if (nums[mid] <= nums[mid + 1]) return leftCount + rightCount;
        int crossCount = sortAndCount(nums, left, mid, right, temp);
        return leftCount + crossCount + rightCount;
    }
    int sortAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        for (int i = left; i <= right; i++) {
            temp[i] = nums[i];
        }
        int cnt = 0;
        int i = left;
        int j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                nums[k] = temp[j];
                j++;
            }
            else if (j == right + 1) { //���������if�ͻ������Ϊǰһ�仰���һ�仰ֻ�ܷ���һ����Ҫ��������ߵ���ĩβ��Ҫ�������ұߴﵽĩβ
                nums[k] = temp[i];
                i++;
            }
            else if (temp[i] <= temp[j]) { //�������<����ô==���ֻ��Ƶ����棬��ôcountֵ��������==�Ĳ��֣��������Ķ������>�ſ��ԣ�
                nums[k] = temp[i];
                i++;
            }
            else {
                nums[k] = temp[j];
                j++;
                cnt += mid - i + 1;
            }
        }
        return cnt;
    }
};