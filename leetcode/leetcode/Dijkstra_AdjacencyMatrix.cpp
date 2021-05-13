#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
�������Ͻ�˹�����㷨

˵�������ڼ���ͼ(����/����ͼ)�����·������

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
#define inf INT_MAX / 2

pair<vector<int>, vector<int>> shortestPath_Dijkstra(vector<vector<int>> a, int v0) {
	//��ʼ������
	int n = a.size();
	vector<int> final(n, 0);
	vector<int>preIndex(n, 0);
	vector<int>shortestPath(n);
	for (int i = 0; i < n; i++) {
		shortestPath[i] = a[v0][i];
	}
	final[v0] = 1; //add to closed list

	//��ѭ��
	int k = -1;
	for (int i = 1; i < n; i++) {
		int minVal = inf;
		//�����v0����ľ���Ķ���
		for (int j = 0; j < n; j++) {
			if (shortestPath[j] < minVal && final[j] == 0) { //����и��̵�·���������Ǹ���δ������
				minVal = shortestPath[j];
				k = j;
			}
		}
		final[k] = 1; //˵������k����̾����Ѿ����

		/*
		��ؼ���ѭ����minVal��v0��vk����̾��룬��ô��������minVal֮��
		v0-vj�ľ���shortestPath[j]�Ƿ����Ϊvk�ļ��������С�أ�����
		v0-vj > v0-vk-vj����shortestPath[j] > minVal + a[k][j]
		����ǣ���ô����shortestPath��ֵ�����ҽ�preIndex��ֵ��Ϊk����vj��ǰ���ڵ���vk
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
	//�����ڽӾ���
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
			if (i == j) a[i][j] = 0; //vi��vi�ľ���Ϊ0
			a[j][i] = a[i][j]; //�ڽӾ���Ӧ���ǶԳ���
		}
	}
	vector<int> shortestPath(n);
	vector<int> preIndex(n);
	auto temp = shortestPath_Dijkstra(a, 0);
	shortestPath = temp.first;
	preIndex = temp.second;
	return 0;
}