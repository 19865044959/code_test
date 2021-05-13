#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：转置矩阵 + 每列互换

说明：
	预备知识：转置矩阵可以通过原地算法直接实现

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //求转置矩阵
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //每列互换
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < int(n / 2); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
};

/**********************************************************************************************************
方法2：以“圈”的方式进行旋转

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int j = 0; j < n / 2; j++) {
            for (int i = j; i < n - 1 - j; i++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = tmp;
            }
        }
    }
};




