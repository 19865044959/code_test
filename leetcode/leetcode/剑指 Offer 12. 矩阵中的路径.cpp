#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������dfs

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(3^K*M*N) O(3*K)
    ע�⣺K���ַ����ĳ���

�漰����֪ʶ�㣺

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
            //������ָ�board[i][j]������flag������飩Ҳ�Ǵ����
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0'; //*���Ϊ�ѷ���
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k]; //*�ھ�����board[i][j]������е㣬��Ҫ���[i][j]Ϊ�ѷ��ʣ����˳��ݹ��Ҫ��[i][j]�����ظ���δ����״̬
        //���󣺲��ָ�board[i][j]
        return res;
    }
};


/**********************************************************************************************************
���������ݷ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(3^K*M*N) O(3*K)
    ע�⣺K���ַ����ĳ���

�漰����֪ʶ�㣺

***********************************************************************************************************/