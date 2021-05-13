#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：贪心算法

说明：
	桶思想

时间复杂度与空间复杂度：O(nlogn) O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> res(26); //hash表
        int temp = 1;
        int len = tasks.size();
        for (int i = 0; i < len; i++) {
            res[tasks[i] - 'A']++; //记录hash表
        }
        sort(res.begin(), res.end(), [](const int& a, const int& b) {
            return a > b; //由大到小排序，用的是lambda表达式
            });
        for (int i = 1; i < 26; i++) {
            if (res[0] == res[i]) temp++; //记录数目最多的任务数个数
        }
        return max(len, (n + 1) * (res[0] - 1) + temp); //如果冷却时间不为0，那么(res[0] - 1) + temp > len，如果冷却时间为0，那么 len >= (n + 1) * (res[0] - 1) + temp
    }
};
