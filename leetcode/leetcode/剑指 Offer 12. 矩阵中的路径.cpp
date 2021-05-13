#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：dfs

说明：

时间复杂度与空间复杂度：O(3^K*M*N) O(3*K)
    注意：K是字符串的长度

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
            //在这里恢复board[i][j]（利用flag标记数组）也是错误的
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0'; //*标记为已访问
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k]; //*在经过点board[i][j]后的所有点，都要标记[i][j]为已访问，在退出递归后，要把[i][j]这个点回复成未访问状态
        //错误：不恢复board[i][j]
        return res;
    }
};


/**********************************************************************************************************
方法：回溯法

说明：

时间复杂度与空间复杂度：O(3^K*M*N) O(3*K)
    注意：K是字符串的长度

涉及到的知识点：

***********************************************************************************************************/