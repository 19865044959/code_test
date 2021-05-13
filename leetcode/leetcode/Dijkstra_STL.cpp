#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

#define inf INT_MAX / 2 
/**********************************************************************************************************
������

˵����
	���裺
		��ʼ��������
		0.0	ͨ��������빹��˫��߱�
		0.1	ά��һ��open list�������ȶ���ʵ�֣����open��������Ѿ�����������ʼ��ɼ��ĵ�
		0.2   ά��һ��closed list��������ʵ�֣�����˵���õ��Ѿ���start�������ž���㣬����Ҫ�ٸ�����
		0.3	��ʼ��open list����start�����open list֮��
		0.4	��ʼ��shortestPathΪinf
		LOOP
		2. ��open listΪ�գ�����false��˵�����ʧ�ܣ�start��end��֮��û�п��з���
		3. ������start��ľ���g(n)������һ����С�����gmin(n)����õ�Ϊn
		4. �����n��start��֮��ľ��������С���룬��ô���õ�n����closed list����
		5. �����������end����ô����start ��end֮��ľ��룬����
		6. Ѱ����n���ڵ����нڵ㣬n1, n2, n3, .. nk
		7. 
			�����nk�ǲ��ɴ��(shortestPath[nk] == inf)����ô����n�ڵ����nk�ǿɴ�ģ���˽�nk����open list
			���������n��nk��start�ľ����С����ô��Ȼ����shortestPath[nk]
		END LOOP



ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

int Dijkstra_STL(int n, vector<vector<int>>& edges, vector<int>& distance, int start, int end) {
	//ͨ������߱�����˫��߱�
	vector<vector<pair<int, int>>> g(n); 
	vector<bool> closedList(n, false);
	//priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	//priority_queueĬ���Ǵ󶥶ѣ����������Ԫ�������Ǹ�������������Ҫ��С·���������ҪС����
	//�����Ҫ�·������ôֱ�ӿ��ԣ�priority_queue<pair<int, int>>����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//����˫��߱�g
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
		//int dist = shortestPath[node]; //ע��distӦ���ǵ�ǰstart��node����̾��룡
		int dist = temp.first;
		closedList[node] = true;
		if (node == end) return shortestPath[end];
		for (auto k : g[node]) {
			int n = k.first;
			int d = k.second;
			if (!closedList[n]) { //���������Ƿ��Ѿ��ɴ���ŵ����ȶ����У������Ҫ��������ע�͵��Ƕλ���
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
	//����߱�
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