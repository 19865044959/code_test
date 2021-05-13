#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������dfs + ǰ�����ģ��

˵����
    ������Ŀ��200��130

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row * column)  O(num)  ����num�ǵ�������  

�漰����֪ʶ�㣺

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
������dfs + ǰ�����ģ��

˵����
    dfs�����void����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row * column)  O(num)  ����num�ǵ�������

�漰����֪ʶ�㣺

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
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) { //ע�����������ô��ݣ������޷��ı䴫�ݵı���area
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