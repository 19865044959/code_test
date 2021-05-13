#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

#define inf INT_MAX / 2 
/**********************************************************************************************************
方法：

说明：
	步骤：
		初始化工作：
		0.0	通过边与距离构造双向边表
		0.1	维护一个open list，用优先队列实现，这个open代表的是已经发现了与起始点可及的点
		0.2   维护一个closed list，用数组实现，用于说明该点已经与start点是最优距离点，不需要再更新了
		0.3	初始化open list，将start点放入open list之中
		0.4	初始化shortestPath为inf
		LOOP
		2. 当open list为空，返回false，说明查点失败，start与end点之间没有可行方案
		3. 根据与start点的距离g(n)，弹出一个最小距离点gmin(n)，设该点为n
		4. 这个点n与start点之间的距离就是最小距离，那么将该点n放入closed list里面
		5. 如果这个点就是end，那么返回start 与end之间的距离，结束
		6. 寻找与n相邻的所有节点，n1, n2, n3, .. nk
		7. 
			①如果nk是不可达的(shortestPath[nk] == inf)，那么经过n节点后发现nk是可达的，因此将nk放入open list
			②如果经过n后，nk到start的距离减小，那么仍然更新shortestPath[nk]
		END LOOP



时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

int Dijkstra_STL(int n, vector<vector<int>>& edges, vector<int>& distance, int start, int end) {
	//通过无向边表，构造双向边表
	vector<vector<pair<int, int>>> g(n); 
	vector<bool> closedList(n, false);
	//priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	//priority_queue默认是大顶堆，即输出的是元素最大的那个，但是我们需要最小路径，因此需要小顶堆
	//如果需要最长路径，那么直接可以：priority_queue<pair<int, int>>即可
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//构造双向边表g
	int m = edges.size();
	for (int i = 0; i < m; i++) {
		g[edges[i][0]].push_back(make_pair(edges[i][1], distance[i]));
		g[edges[i][1]].push_back(make_pair(edges[i][0], distance[i]));
	}
	vector<int> shortestPath(n, inf);
	shortestPath[start] = 0;

	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		auto temp = pq.top();
		pq.pop();
		int node = temp.second;
		//int dist = shortestPath[node]; //注意dist应该是当前start与node的最短距离！
		int dist = temp.first;
		closedList[node] = true;
		if (node == end) return shortestPath[end];
		for (auto k : g[node]) {
			int n = k.first;
			int d = k.second;
			if (!closedList[n]) { //这里无论是否已经可达，都放到优先队列中，否则就要按照上面注释的那段话了
				if (shortestPath[n] > dist + d) {
					shortestPath[n] = dist + d;
					pq.push(make_pair(shortestPath[n], n));
				}
			}
		}
	}
	return -1;
}

int main() {
	//构造边表
	int n = 16;
	vector<vector<int>> edges(n);
	vector<int>distance(n);
	edges[0] = { 0, 1 }, distance[0] = 1;
	edges[1] = { 0, 2 }, distance[1] = 5;
	edges[2] = { 1, 2 }, distance[2] = 3;
	edges[3] = { 1, 3 }, distance[3] = 7;
	edges[4] = { 1, 4 }, distance[4] = 5;
	edges[5] = { 2, 4 }, distance[5] = 1;
	edges[6] = { 2, 5 }, distance[6] = 7;
	edges[7] = { 3, 4 }, distance[7] = 2;
	edges[8] = { 4, 5 }, distance[8] = 3;
	edges[9] = { 3, 6 }, distance[9] = 3;
	edges[10] = { 4, 6 }, distance[10] = 6;
	edges[11] = { 4, 7 }, distance[11] = 9;
	edges[12] = { 5, 7 }, distance[12] = 5;
	edges[13] = { 6, 7 }, distance[13] = 2;
	edges[14] = { 6, 8 }, distance[14] = 7;
	edges[15] = { 7, 8 }, distance[15] = 4;

	int start = 0;
	int end = 8;

	int ans = Dijkstra_STL(n, edges, distance, start, end);

	return 0;
}