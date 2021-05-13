#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
    ���ͣ������������������ͬ���ֵ��ײ�idx��β��idx���� b c a a a a d e
    ˼�룺����a����ߣ���cԪ�أ����ҵ�aԪ�ص��ұߣ���dԪ�أ������ұ߽�
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        //���ұߵ�һ��target
        int idx_right = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1; //���������ҵ��ұ߽߱磬����߽�ֵ�� > target�ģ���ô�Ҿͷ��ĵ�left = mid + 1
            else right = mid - 1; //���������ҵ��ұߵĵ�һ�� > target����������Ҫ�������䣬������һ������������ѡ��right = mid�������п��������ѭ������ô�Ҿ���right  = mid - 1����ô���һ���ǣ�rightָ��target��leftָ���Ҳ����䣬����left����
        }
        if (right < 0 || nums[right] != target) return 0;
        idx_right = left;

        left = 0; right = n - 1;
        //����ߵ�һ��target
        int idx_left = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        idx_left = right;
        return idx_right - idx_left - 1;
    }
};