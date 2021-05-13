#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：不断变换上下左右边界，确定边界条件，进而得到答案

说明：

时间复杂度与空间复杂度：O(m * n)  O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int left = 0;
        int right = matrix[0].size() - 1;
        int low = matrix.size() - 1;
        int up = 0;
        vector<int> res;
        while (true) {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if (++up > low) break;
            for (int i = up; i <= low; i++) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int i = right; i >= left; i--) res.push_back(matrix[low][i]);
            if (--low < up) break;
            for (int i = low; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};