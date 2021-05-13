#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/**********************************************************************************************************
方法：基于邻接矩阵的深度优先搜索

说明：
	1. 邻接矩阵：把邻接点写作矩阵的形式
	2. 作出改进：如果利用了C++之中的可变数组，那么可以进一步将邻接矩阵简化，比如说以前，即使两个邻接点之间未连接，
		那么也必须在邻接矩阵之中记录，只不过记录值从1变成了0，有了可变数组，我们可以将不需要的节点不记录，
		更加节省空间与节省遍历时间
	3. 作出改进：可以任意选择起始节点startPoint

时间复杂度与空间复杂度：O(n + e)，O(n) 其中n是节点个数，e是边数

涉及到的知识点：

***********************************************************************************************************/

void DFS(vector<vector<int>>& a, vector<int>& visited, int i) {
	visited[i] = 1;
	cout << i << " ";
	for (int j = 0; j < a[i].size(); j++) {
		if (visited[a[i][j]] == 0) {
			DFS(a, visited, a[i][j]);
		}
	}
}

void DFSTraverse(vector<vector<int>>& a, int k) {
	vector<int> visited(a.size(), 0);
	for (int i = k; i < a.size(); i++) {
		//防止非连通图、回环等出现，若是连通图，那么这个循环只会执行一次
		if (!visited[i]) {
			DFS(a, visited, i);
		}
	}
	for (int i = 0; i < k; i++) {
		if (!visited[i]) {
			DFS(a, visited, i);
		}
	}
}

int main() {
	vector<vector<int>> a{ {1, 2}, {2, 3}, {0}, {3} };
	//vector<vector<int>> a{ {1, 2}, {2}, {0, 3}, {3} };
	int startPoint = 1;
	DFSTraverse(a, startPoint);
}