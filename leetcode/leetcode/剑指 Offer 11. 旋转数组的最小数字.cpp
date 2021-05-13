#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：二分法

说明：

时间复杂度与空间复杂度：O(logn) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (numbers[middle] > numbers[right]) {//在左侧
                left = middle + 1;
            }
            else if (numbers[middle] < numbers[right]) {//在右侧
                right = middle;
            }
            else right--;
        }
        return numbers[left];
    }
};