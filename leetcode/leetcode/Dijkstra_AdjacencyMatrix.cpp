#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：迪杰斯特拉算法

说明：用于计算图(有向/无向图)中最短路径问题

时间复杂度与空间复杂度：O(n^2) O(n)

涉及到的知识点：

***********************************************************************************************************/
#define inf INT_MAX / 2

pair<vector<int>, vector<int>> shortestPath_Dijkstra(vector<vector<int>> a, int v0) {
	//初始化工作
	int n = a.size();
	vector<int> final(n, 0);
	vector<int>preIndex(n, 0);
	vector<int>shortestPath(n);
	for (int i = 0; i < n; i++) {
		shortestPath[i] = a[v0][i];
	}
	final[v0] = 1; //add to closed list

	//主循环
	int k = -1;
	for (int i = 1; i < n; i++) {
		int minVal = inf;
		//求出与v0最近的距离的顶点
		for (int j = 0; j < n; j++) {
			if (shortestPath[j] < minVal && final[j] == 0) { //如果有更短的路径，并且那个点未被发现
				minVal = shortestPath[j];
				k = j;
			}
		}
		final[k] = 1; //说明顶点k的最短距离已经求出

		/*
		最关键的循环：minVal是v0到vk的最短距离，那么算出了这个minVal之后，
		v0-vj的距离shortestPath[j]是否会因为vk的加入而更加小呢？即：
		v0-vj > v0-vk-vj，即shortestPath[j] > minVal + a[k][j]
		如果是，那么更新shortestPath的值，并且将preIndex的值设为k，即vj的前驱节点是vk
		*/
		for (int j = 0; j < n; j++) {
			if (final[j] == 0 && minVal + a[k][j] < shortestPath[j]) {
				shortestPath[j] = minVal + a[k][j];
				preIndex[j] = k;
			}
		}
	}
	return make_pair(shortestPath, preIndex);
}

int main() {
	//构建邻接矩阵
	int n = 9;
	vector<vector<int>> a(n, vector<int>(n, inf));
	a[0][1] = 1;
	a[0][2] = 5;

	a[1][2] = 3;
	a[1][3] = 7;
	a[1][4] = 5;

	a[2][4] = 1;
	a[2][5] = 7;

	a[3][4] = 2;
	a[3][6] = 3;
	a[4][5] = 3;

	a[4][6] = 6;
	a[4][7] = 9;

	a[5][7] = 5;

	a[6][7] = 2;
	a[6][8] = 7;

	a[7][8] = 4;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) a[i][j] = 0; //vi到vi的距离为0
			a[j][i] = a[i][j]; //邻接矩阵应该是对称阵
		}
	}
	vector<int> shortestPath(n);
	vector<int> preIndex(n);
	auto temp = shortestPath_Dijkstra(a, 0);
	shortestPath = temp.first;
	preIndex = temp.second;
	return 0;
}