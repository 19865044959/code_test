#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：dfs(前序遍历模板)

说明：
    相似题目：130、695

时间复杂度与空间复杂度：O(row*column)  O(p)  其中p是整个区域岛屿的数量

涉及到的知识点：
    1. 类之中private变量的熟练应用：如果多个private函数都要使用到一个变量，
        那么不妨设这个变量是class里面的private变量，而不是单单一个函数里面的临时变量
        比如说：在本题之中row、column要在numIslands与inArea之中用到
                                       mark要在numIslands于dfs之中用到
        如果将row、column设定为临时变量，那么还需要在函数中传递这些临时变量，非常麻烦
    2. 矩阵之中进行dfs迭代，时常会用到获取四邻域坐标值，继续进行dfs迭代，那么可用一个neighborhood变量来装载这些差值


***********************************************************************************************************/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row == 0) return 0;
        column = grid[0].size();
        mark = vector<vector<int>>(row, vector<int>(column, 0));
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '1' && !mark[i][j]) {
                    //这里极像dfs_adjacencyMatrix源码之中，寻找连通域的代码
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }

private:
    int row, column;
    vector<vector<int>> mark;
    vector<vector<int>> neighborhood{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; //相对于(row, column)而言的右、下、左、上偏移量

    bool inArea(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < column;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        mark[i][j] = 1;
        for (int m = 0; m < 4; m++) {
            int newRow = i + neighborhood[m][0]; //利用neighborhood存储坐标差值，求解四邻域的坐标
            int newColumn = j + neighborhood[m][1];
            //如果数组未越界，并且是陆地，并且还未被标记（走过），那么继续进行dfs搜索
            if (inArea(newRow, newColumn) && grid[newRow][newColumn] == '1' && !mark[newRow][newColumn]) {
                dfs(newRow, newColumn, grid);
            }
        }
    }
};

//可做测试用
/*
int main() {
    Solution temp;
    vector<vector<char>> a{
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'} };
    int ans = temp.numIslands(a);
    return 0;
}
*/

/**********************************************************************************************************
方法：dfs + 前序遍历模板

说明：

时间复杂度与空间复杂度：O(row*column)  O(p)  其中p是整个区域岛屿的数量

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row == 0) return 0;
        column = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }

private:
    int row, column;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= row) return;
        if (j < 0 || j >= column) return;
        grid[i][j] = '0';
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
    }
};