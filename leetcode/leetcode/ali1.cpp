/*
	Ⱦɫ���⣺
	��һ��n*m�ľ���Ⱦɫ��������ǰ�ɫW��С���ѡ���߹���·����Ⱦ��R
	�ʼ�����Ͻǣ������ߣ������������������ת�䣺
	1. �ߵ��˵�ͼ�߽磬�޷�����
	2. ��ǰλ��ǰ���ǰ��Ϊ��ɫ

	�������������ͣ��
	1. ����ǰ��һ��Ļ�����Ⱦ��һ��2*2�����򣬴�ʱ����������ǰ��
	2. ��ת���޷�ֱ��ֻ��������ת����ʱ��Ҳ��Ҫͣ����	
	+
	���룺n m
	���������Ⱦɫ��ĵ�ͼ
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;



int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> matrix(n, vector<int>(m, 0));
		vector<vector<int>> tmp = {
			{1, 0},
			{0, 1},
			{-1, 0},
			{0, -1}
		};
		int flag = 0;
		int i = 0, j = 0;
		while (true) {
			if (matrix[i][j] == 1 || fuc(matrix, i, j)) break;
			matrix[i][j] = 1;
			int p = tmp[flag][0];
			int q = tmp[flag][1];
			if()
		}
	}
}
