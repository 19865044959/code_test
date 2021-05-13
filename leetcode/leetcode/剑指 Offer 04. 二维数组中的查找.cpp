#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：寻找特殊元素：右上角/左下角

说明：
	二维数组：对角线、4个角都可能成为特殊的解题钥匙

时间复杂度与空间复杂度：O(row + column) O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)  return false;
        int column = matrix[0].size();
        int i = row - 1;
        int j = 0;
        while (i >= 0 && j < column) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) i--;
            else j++;
        }
        return false;
    }
};
