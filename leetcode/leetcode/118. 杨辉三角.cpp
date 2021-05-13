#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������Ƕ���

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n!) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res;
        res.push_back({ 1 });
        for (int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;
            temp[i] = 1;
            for (int j = 1; j < i; j++) {
                temp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(temp);
        }
        return res;
    }
};