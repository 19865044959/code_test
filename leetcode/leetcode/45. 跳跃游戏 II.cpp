#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������̰���㷨

˵����
   1. Ѱ�������⣺����ǰ��ÿһ���㶼����С��Ծ�������ߵ�ÿһ��������ģ��ֲ����ţ�
    ���� 2 3 1 2 4 2 3
    �±� 0 1 2 3 4 5 6
    ���±�0������±�2����һ�������
    �ڴ��±�0-�±�2��һ����Χ���ڶ������±�1���Դﵽ�±�4���ڶ��������
    �۴��±�1-�±�4�У��±�4�ɴﵽ�±�8��8 > 6˵�������ߵ��յ㣬���������
    ÿ�����������̰���㷨

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        int p = 0;
        int count = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            maxlen = max(maxlen, nums[i] + i);
            if (i == p) {
                count++;
                p = maxlen;
                if (p >= n - 1) break;
            }
        }
        return count;
    }
};