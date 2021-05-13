#include<iostream>
#include<queue>
#include <vector>

#define FLOAT_MAX 100000.0

using namespace std;

typedef pair<pair<float, float>, pair<int, int>> twoPair;
/*
	输入：
	vector<vector<int>>grid  m * n
		当二维数组值为-1时，说明是障碍物，
		当为1时，说明是通路，
	pair<int, int>start_point
	pair<int, int>end_point
*/

bool isValid(vector<vector<int>>& grid, int p, int q) {
	if (p >= 0 && p < grid.size() && q >= 0 && q < grid[0].size() && grid[p][q] != -1) {
		return true;
	}
	else {
		return false;
	}
}

void updateOpenList(vector<vector<int>>& grid, priority_queue<twoPair, vector<twoPair>, greater<twoPair>>& pq, vector<vector<bool>>& closedList, vector<vector<float>>& minf, pair<int, int>& end, int i, int j, int p, int q, float f, float g) {
	if (isValid(grid, p, q) && !closedList[p][q]) {
		float newh = sqrt((p - end.first) * (p - end.first) + (q - end.second) * (q - end.second));
		float newg = g + 1;
		float newf = newh + newg;
		if (newf < minf[p][q]) {
			pq.push(make_pair(make_pair(newf, newg), make_pair(p, q)));
			minf[p][q] = newf;
		}
	}
}

float Astar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
	int row = grid.size();
	if (row == 0) return 0;
	int col = grid[0].size();

	//构建minf
	vector<vector<float>>minf(row, vector<float>(col, FLOAT_MAX));
	minf[start.first][start.second] = 0.0;

	//构建优先级队列 open list
	/*
		队列中的元素分别是： f  g  i   j
	*/
	priority_queue<twoPair, vector<twoPair>, greater<twoPair>>pq;
	pq.push(make_pair(make_pair(0.0, 0.0), make_pair(start.first, start.second)));

	//构建closed list
	vector<vector<bool>>closedList(row, vector<bool>(col, false));

	while (!pq.empty()) {
		twoPair node = pq.top();
		pq.pop();
		float f = node.first.first;
		float g = node.first.second;
		int i = node.second.first;
		int j = node.second.second;
		if (make_pair(i, j) == end) {
			return node.first.first;
		}
		closedList[i][j] = true;
		updateOpenList(grid, pq, closedList, minf, end, i, j, i + 1, j, f, g);
		updateOpenList(grid, pq, closedList, minf, end, i, j, i - 1, j, f, g);
		updateOpenList(grid, pq, closedList, minf, end, i, j, i, j + 1, f, g);
		updateOpenList(grid, pq, closedList, minf, end, i, j, i, j - 1, f, g);
	}
	return -1.0;
}

int main() {
	vector<vector<int>>grid1({ {1} });
	vector<vector<int>>grid2({ { 1, -1 }, { -1, 1 } });
	vector<vector<int>>grid3({ {1, 1, -1}, {-1, 1, -1}, {-1, 1, 1} });
	vector<vector<int>>grid4({ { 1, -1, 1, 1 }, { 1, -1, -1, 1 }, { 1, -1, 1, 1 }, { 1, 1, 1, -1 } });
	float res1 = Astar(grid1, make_pair(0, 0), make_pair(0, 0)); //0
	float res2 = Astar(grid2, make_pair(0, 0), make_pair(1, 1)); //找不到
	float res3 = Astar(grid3, make_pair(0, 0), make_pair(2, 2)); //4
	float res4 = Astar(grid4, make_pair(0, 0), make_pair(0, 2)); //10
}