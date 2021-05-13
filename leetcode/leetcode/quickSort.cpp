#include <iostream>
#include <vector>
#include<stdlib.h>
using std::vector;
using std::swap;

/**********************************************************************************************************
��������������

˵����
	�����������left ��right��������ֵ��left = 0;  right = c.size() - 1
	������������ǳ���n����n = c.size()

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)  O(logn)?

�漰����֪ʶ�㣺
    1. �ɱ�ʽΪ����һ����������ǰkС/������ļ��ϣ� ��һ����������ĵ�k��/С����

***********************************************************************************************************/
class Solution {
public:

private:
    int partition(vector<int>& nums, int left, int right) {
        int idx = rand() % (right - left + 1) + left; 
        int pivotKey = nums[left]; //����3��ȡ��
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