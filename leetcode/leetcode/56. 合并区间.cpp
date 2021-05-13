#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); //��������������֮��Ĵ�С�Ƚϣ�ĳһ��ֵ��ͬ�˲űȽ���һ���������Ǹ�ǰ���ֵ���ĸ�����ʹ�
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) { 
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};