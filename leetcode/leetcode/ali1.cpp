/*
	染色问题：
	给一个n*m的矩阵染色，起初都是白色W，小红会选择走过的路进行染红R
	最开始在左上角，向下走，遇到下面情况会向左转弯：
	1. 走到了地图边界，无法再走
	2. 当前位置前面的前面为红色

	遇到下面情况会停：
	1. 再往前走一格的话，会染红一个2*2的区域，此时不允许再向前走
	2. 左转后无法直走只能再向左转，这时候也需要停下来	
	+
	输入：n m
	输出：最终染色后的地图
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
