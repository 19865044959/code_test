#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����������˼��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�
	ʱ�䣺O(n) + O(n / 2) + O(n / 4) + ... = O(n)
	�ռ䣺���ŵݹ�����ΪO(logn)

�漰����֪ʶ�㣺
	����Դ��
***********************************************************************************************************/


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k == 0) return {};
        quickSort(arr, 0, arr.size() - 1, k);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }

private:
    int partition(vector<int>& arr, int low, int high) {
        int pivotKey = arr[low];
        while (low < high) {
            while (low < high && arr[high] >= pivotKey) high--;
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivotKey) low++;
            arr[high] = arr[low];
        }
        arr[low] = pivotKey;
        return low;
    }

    void quickSort(vector<int>& arr, int low, int high, int k) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            if (pivot == k) return;
            if (pivot > k) quickSort(arr, low, pivot - 1, k);
            else quickSort(arr, pivot + 1, high, k);
        }
    }
};