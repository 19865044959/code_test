#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/**********************************************************************************************************
�����������ڽӾ���������������

˵����
	1. �ڽӾ��󣺰��ڽӵ�д���������ʽ
	2. �����Ľ������������C++֮�еĿɱ����飬��ô���Խ�һ�����ڽӾ���򻯣�����˵��ǰ����ʹ�����ڽӵ�֮��δ���ӣ�
		��ôҲ�������ڽӾ���֮�м�¼��ֻ������¼ֵ��1�����0�����˿ɱ����飬���ǿ��Խ�����Ҫ�Ľڵ㲻��¼��
		���ӽ�ʡ�ռ����ʡ����ʱ��
	3. �����Ľ�����������ѡ����ʼ�ڵ�startPoint

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n + e)��O(n) ����n�ǽڵ������e�Ǳ���

�漰����֪ʶ�㣺

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
		//��ֹ����ͨͼ���ػ��ȳ��֣�������ͨͼ����ô���ѭ��ֻ��ִ��һ��
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