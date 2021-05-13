#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：bfs

说明：
    0. 初始状态时，所有距离均为-1
    1. 首先将所有0元素所在距离设为0
    2. 其次在0元素形成范围外边界所有元素距离设为1
    3. 在外边界的外边界所有元素距离设为2
    4. ....
    .
    .
    .
    直到所有距离均不为-1

时间复杂度与空间复杂度：O(row + column)  O(row + column)

涉及到的知识点：
    1. bfs模板（层序遍历）（详见dfs--104二叉树的最大深度--bfs）
    2. 为什么这个bfs模板不需要在while(!que.empty())下面再加上下面的循环：
        int sizeq = que.size();
        for(int m = 0; m < sizeq; m++){
            ...
        }
        答：上述循环是记录当一层的元素均被取出时的计数用，由于本题中不像104题中一样需要记录层数，
                因此也不需要这个循环

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return{};
        int column = matrix[0].size();

        vector<vector<int>> dist(row, vector<int>(column, -1));
        queue<pair<int, int>> que;
        vector<vector<int>> a{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 0) {
                    que.push({ i, j });
                    dist[i][j] = 0;
                }
            }
        }
        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            for (int k = 0; k < 4; k++) {
                int newRow = r + a[k][0];
                int newColumn = c + a[k][1];
                if (newRow >= 0 && newRow < row && newColumn >= 0 && newColumn < column) {
                    if (dist[newRow][newColumn] == -1) {
                        dist[newRow][newColumn] = dist[r][c] + 1;
                        que.push({ newRow, newColumn });
                    }
                }
            }
        }
        return dist;
    }
};


//改进版，可以不需要dist，直接在matrix上面改：

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return{};
        int column = matrix[0].size();

        // vector<vector<int>> dist(row, vector<int>(column, -1));
        queue<pair<int, int>> que;
        vector<vector<int>> a{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 0) {
                    que.push({ i, j });
                    //dist[i][j] = 0;
                }
                else {
                    matrix[i][j] = -1;
                }
            }
        }
        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            for (int k = 0; k < 4; k++) {
                int newRow = r + a[k][0];
                int newColumn = c + a[k][1];
                if (newRow >= 0 && newRow < row && newColumn >= 0 && newColumn < column) {
                    if (matrix[newRow][newColumn] == -1) {
                        matrix[newRow][newColumn] = matrix[r][c] + 1;
                        que.push({ newRow, newColumn });
                    }
                }
            }
        }
        return matrix;
    }
};