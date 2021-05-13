#include <iostream>
#include <vector>
#include<stdlib.h>
using std::vector;
using std::swap;

/**********************************************************************************************************
方法：快速排序

说明：
	快排输入的是left 与right，即索引值：left = 0;  right = c.size() - 1
	堆排序输入的是长度n，即n = c.size()

时间复杂度与空间复杂度：O(nlogn)  O(logn)?

涉及到的知识点：
    1. 可变式为：求一个无序数组前k小/大的数的集合， 求一个无序数组的第k大/小的数

***********************************************************************************************************/
class Solution {
public:

private:
    int partition(vector<int>& nums, int left, int right) {
        int idx = rand() % (right - left + 1) + left; 
        int pivotKey = nums[left]; //可以3数取中
        while (left < right) {
            while (left < right && nums[right] >= pivotKey) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivotKey) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivotKey;
        return left;
    }
    //ver2
    int partition2(vector<int>& nums, int left, int right) {
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && nums[i] <= nums[left]) i++;
            while (i < j && nums[j] >= nums[left])j--;
            swap(nums[i], nums[j]);
        }
        return i;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }
};

int main() {
	//vector<int> a{ 4,2,14,661,443,224,11243,2,44 };
	//quickSort(a, 0, a.size() - 1);
	//return 0;
}