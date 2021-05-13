#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0) return {};

        vector<int> track;
        backtrack(candidates, 0, target, track);
        return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int start, int target, vector<int>track) {
        //终止条件
        if (target == 0) {
            res.push_back(track);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < candidates.size(); i++) {
            //做选择并加入路径
            track.push_back(candidates[i]);
            //回溯
            backtrack(candidates, i, target - candidates[i], track);
            //撤销选择
            track.pop_back();
        }
    }
};