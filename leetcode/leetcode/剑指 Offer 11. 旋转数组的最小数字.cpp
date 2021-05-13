#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
���������ַ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(logn) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (numbers[middle] > numbers[right]) {//�����
                left = middle + 1;
            }
            else if (numbers[middle] < numbers[right]) {//���Ҳ�
                right = middle;
            }
            else right--;
        }
        return numbers[left];
    }
};