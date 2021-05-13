#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������dfs(ǰ�����ģ��)

˵����
    ������Ŀ��130��695

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row*column)  O(p)  ����p�����������������

�漰����֪ʶ�㣺
    1. ��֮��private����������Ӧ�ã�������private������Ҫʹ�õ�һ��������
        ��ô���������������class�����private�����������ǵ���һ�������������ʱ����
        ����˵���ڱ���֮��row��columnҪ��numIslands��inArea֮���õ�
                                       markҪ��numIslands��dfs֮���õ�
        �����row��column�趨Ϊ��ʱ��������ô����Ҫ�ں����д�����Щ��ʱ�������ǳ��鷳
    2. ����֮�н���dfs������ʱ�����õ���ȡ����������ֵ����������dfs��������ô����һ��neighborhood������װ����Щ��ֵ


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
                    //���Ｋ��dfs_adjacencyMatrixԴ��֮�У�Ѱ����ͨ��Ĵ���
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
    vector<vector<int>> neighborhood{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; //�����(row, column)���Ե��ҡ��¡�����ƫ����

    bool inArea(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < column;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        mark[i][j] = 1;
        for (int m = 0; m < 4; m++) {
            int newRow = i + neighborhood[m][0]; //����neighborhood�洢�����ֵ����������������
            int newColumn = j + neighborhood[m][1];
            //�������δԽ�磬������½�أ����һ�δ����ǣ��߹�������ô��������dfs����
            if (inArea(newRow, newColumn) && grid[newRow][newColumn] == '1' && !mark[newRow][newColumn]) {
                dfs(newRow, newColumn, grid);
            }
        }
    }
};

//����������
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
������dfs + ǰ�����ģ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row*column)  O(p)  ����p�����������������

�漰����֪ʶ�㣺

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