#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������dfs(ǰ�����ģ��)

˵����
	������Ŀ��200��695

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row * column)  O(row * column)  

�漰����֪ʶ�㣺

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
                else if (board[i][j] == 'O') board[i][j] = 'X'; //ע��������д��if������else if�Ļ�����ô���е�'O'���ն��ᱻ���'X'���ò�����ȷ��
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