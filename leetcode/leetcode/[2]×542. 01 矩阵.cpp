#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������bfs

˵����
    0. ��ʼ״̬ʱ�����о����Ϊ-1
    1. ���Ƚ�����0Ԫ�����ھ�����Ϊ0
    2. �����0Ԫ���γɷ�Χ��߽�����Ԫ�ؾ�����Ϊ1
    3. ����߽����߽�����Ԫ�ؾ�����Ϊ2
    4. ....
    .
    .
    .
    ֱ�����о������Ϊ-1

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row + column)  O(row + column)

�漰����֪ʶ�㣺
    1. bfsģ�壨��������������dfs--104��������������--bfs��
    2. Ϊʲô���bfsģ�岻��Ҫ��while(!que.empty())�����ټ��������ѭ����
        int sizeq = que.size();
        for(int m = 0; m < sizeq; m++){
            ...
        }
        ������ѭ���Ǽ�¼��һ���Ԫ�ؾ���ȡ��ʱ�ļ����ã����ڱ����в���104����һ����Ҫ��¼������
                ���Ҳ����Ҫ���ѭ��

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


//�Ľ��棬���Բ���Ҫdist��ֱ����matrix����ģ�

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