#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
/*
    时间复杂度：分别是堆排序O(n)、最坏情况下，所有元素均需要被压入队列，此时是O(n)
    因此总共时间复杂度是：O(n^2)
*/

using namespace std;
#define INF INT_MAX / 2
typedef pair<int, pair<int, int>> twoPair;
int main() {
    int row, col;
    while (cin >> row >> col) {
        vector<vector<int>>maze(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> maze[i][j];
            }
        }
        //init
        priority_queue<twoPair, vector<twoPair>, greater<twoPair>>pq;
        vector<vector<bool>>closedList(row, vector<bool>(col, false));
        vector<vector<int>>shortest(row, vector<int>(col, INF));
        vector<vector<int>>preNode(row, vector<int>(col, 0));

        pq.push(make_pair(0, make_pair(0, 0)));
        closedList[0][0] = true;
        shortest[0][0] = 0;

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            pair<int, int>cor = { node.second.first, node.second.second };
            if (cor == make_pair(row - 1, col - 1)) {
                vector<pair<int, int>>temp;
                while (cor != make_pair(0, 0)) {
                    temp.push_back(cor);
                    int preX = preNode[cor.first][cor.second] / 100;
                    int preY = preNode[cor.first][cor.second] % 100;
                    cor = make_pair(preX, preY);
                }
                temp.push_back(cor);
                for (int i = temp.size() - 1; i >= 0; i--) {
                    cout << "(" << temp[i].first << "," << temp[i].second << ")" << endl;
                }
                break;
            }
            else {
                int xNew = cor.first + 0;
                int yNew = cor.second + 1;
                if (yNew < col && !maze[xNew][yNew] && !closedList[xNew][yNew]) {
                    if (node.first + 1 < shortest[xNew][yNew]) {
                        preNode[xNew][yNew] = 100 * cor.first + cor.second;
                        shortest[xNew][yNew] = node.first + 1;
                        pq.push(make_pair(node.first + 1, make_pair(xNew, yNew)));
                    }
                }
                xNew = cor.first + 0;
                yNew = cor.second - 1;
                if (yNew >= 0 && !maze[xNew][yNew] && !closedList[xNew][yNew]) {
                    if (node.first + 1 < shortest[xNew][yNew]) {
                        preNode[xNew][yNew] = 100 * cor.first + cor.second;
                        shortest[xNew][yNew] = node.first + 1;
                        pq.push(make_pair(node.first + 1, make_pair(xNew, yNew)));
                    }
                }
                xNew = cor.first + 1;
                yNew = cor.second + 0;
                if (xNew < row && !maze[xNew][yNew] && !closedList[xNew][yNew]) {
                    if (node.first + 1 < shortest[xNew][yNew]) {
                        preNode[xNew][yNew] = 100 * cor.first + cor.second;
                        shortest[xNew][yNew] = node.first + 1;
                        pq.push(make_pair(node.first + 1, make_pair(xNew, yNew)));
                    }
                }
                xNew = cor.first - 1;
                yNew = cor.second + 0;
                if (xNew >= 0 && !maze[xNew][yNew] && !closedList[xNew][yNew]) {
                    if (node.first + 1 < shortest[xNew][yNew]) {
                        preNode[xNew][yNew] = 100 * cor.first + cor.second;
                        shortest[xNew][yNew] = node.first + 1;
                        pq.push(make_pair(node.first + 1, make_pair(xNew, yNew)));
                    }
                }
            }
        }
    }
    return 0;
}

//回溯
using namespace std;

vector<pair<int, int>>tempPath;
vector<pair<int, int>>bestPath;
int row;
int col;

void getBestPath(vector<vector<int>>& maze, int i, int j) {
    maze[i][j] = 1;
    tempPath.push_back({ i, j });
    if (i == row - 1 && j == col - 1) {
        if (bestPath.empty() || bestPath.size() > tempPath.size()) {
            bestPath = tempPath;
        }
    }
    if (i + 1 < row && maze[i + 1][j] == 0) {
        getBestPath(maze, i + 1, j);
    }
    if (j + 1 < col && maze[i][j + 1] == 0) {
        getBestPath(maze, i, j + 1);
    }
    if (i - 1 >= 0 && maze[i - 1][j] == 0) {
        getBestPath(maze, i - 1, j);
    }
    if (j - 1 >= 0 && maze[i][j - 1] == 0) {
        getBestPath(maze, i, j - 1);
    }
    maze[i][j] = 0; //恢复现场
    tempPath.pop_back(); //恢复现场
}

int main() {
    while (cin >> row >> col) {
        tempPath.clear();
        bestPath.clear();
        vector<vector<int>>maze(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> maze[i][j];
            }
        }
        getBestPath(maze, 0, 0);
        for (int i = 0; i < bestPath.size(); i++) {
            cout << "(" << bestPath[i].first << "," << bestPath[i].second << ")" << endl;
        }
    }
    return 0;
}