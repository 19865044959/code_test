#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

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
        //��ֹ����
        if (target == 0) {
            res.push_back(track);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < candidates.size(); i++) {
            //��ѡ�񲢼���·��
            track.push_back(candidates[i]);
            //����
            backtrack(candidates, i, target - candidates[i], track);
            //����ѡ��
            track.pop_back();
        }
    }
};