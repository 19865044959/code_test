#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：快排

说明：与第973题、快排源码一样

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        while (low < high) {
            int pivot = partition(arr, low, high);
            if (pivot == k) break;
            else if (pivot > k) {
                high = pivot - 1;
            }
            else {
                low = pivot + 1;
            }
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    int partition(vector<int>& arr, int low, int high) {
        //三数取中
        int medium = low + (high - low) / 2;
        if (arr[low] > arr[high]) swap(arr[low], arr[high]);
        if (arr[medium] > arr[high]) swap(arr[medium], arr[high]);
        if (arr[low] < arr[medium]) swap(arr[low], arr[medium]);
        int pivotkey = arr[low];
        //主循环
        while (low < high) {
            while (low < high && pivotkey <= arr[high]) high--;
            arr[low] = arr[high];
            while (low < high && pivotkey >= arr[low]) low++;
            arr[high] = arr[low];
        }
        arr[low] = pivotkey;
        return low;
    }
};