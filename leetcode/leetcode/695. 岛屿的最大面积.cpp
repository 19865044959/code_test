#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：dfs + 前序遍历模板

说明：
    相似题目：200、130

时间复杂度与空间复杂度：O(row * column)  O(num)  其中num是岛屿数量  

涉及到的知识点：

***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        if (row == 0) return 0;
        column = grid[0].size();
        int maxArea = 0;
        int area;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j]) {
                    area = dfs(grid, i, j);
                    maxArea = area > maxArea ? area : maxArea;
                }
            }
        }
        return maxArea;
    }

private:
    int row, column;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= row) return 0;
        if (j < 0 || j >= column) return 0;
        if (grid[i][j]) {
            grid[i][j] = 0;
            return 1 + dfs(grid, i, j + 1) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i - 1, j);
        }
        return 0;
    }
};

/**********************************************************************************************************
方法：dfs + 前序遍历模板

说明：
    dfs变成了void函数

时间复杂度与空间复杂度：O(row * column)  O(num)  其中num是岛屿数量

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        column = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j]) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

private:
    int row;
    int column;
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) { //注意这里是引用传递，否则无法改变传递的变量area
        if (i < 0 || i >= row || j < 0 || j >= column) return;
        if (grid[i][j]) {
            grid[i][j] = 0;
            area++;
            dfs(grid, i, j + 1, area);
            dfs(grid, i + 1, j, area);
            dfs(grid, i, j - 1, area);
            dfs(grid, i - 1, j, area);
        }
        return;
    }
};