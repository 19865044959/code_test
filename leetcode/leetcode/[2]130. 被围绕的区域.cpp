#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：dfs(前序遍历模板)

说明：
	相似题目：200、695

时间复杂度与空间复杂度：O(row * column)  O(row * column)  

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if (row == 0) return;
        column = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == column - 1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X'; //注意这里：如果写作if而不是else if的话，那么所有的'O'最终都会被变成'X'，得不到正确答案
            }
        }
    }
private:
    int row, column;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= column || board[i][j] == 'X' || board[i][j] == '#') return;
        board[i][j] = '#';
        dfs(board, i, j + 1);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i - 1, j);
    }
};