#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：排序法

说明：

时间复杂度与空间复杂度：O(nlogn) O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); //数组排序即是数组之间的大小比较，某一个值相同了才比较下一个，否则那个前面的值大哪个数组就大
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