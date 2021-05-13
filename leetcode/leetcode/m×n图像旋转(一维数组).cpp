//给定一个m * n的一维图像，你能够原地旋转90°吗？
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//旋转前的节点，也就是左旋90度
//(i, j) - > (n - 1 - j, i)
int getPre(int n, int m, int i, int j) {
	return j * n + n - 1 - i;
}

//旋转后的节点，也就是右旋90度
//(i, j) - > (j, m - 1 - i)
int getPos(int m, int n, int i, int j) {
	return j * m + (m - 1 - i);
}

void moveData(int* ptr, int i, int m, int n) {
	int cur = i;
	int tmp = ptr[i];
	int pre = getPre(m, n, i / n, i % n);
	while (pre != i) {
		ptr[cur] = ptr[pre];
		cur = pre;
		pre = getPre(n, m, pre / m, pre % m);
	}
	ptr[cur] = tmp;
}

void matrixRotate(int* ptr, int m, int n) {
	for (int i = 0; i < m * n; i++) {
		int pos = getPos(m, n, i / n, i % n);
		while (pos > i) pos = getPos(m, n, pos / n, pos % n);
		if (pos == i) moveData(ptr, i, m, n);
	}
}

void showMatrix(int* ptr, int m, int n) {
	for (int i = 0; i < m * n; i++) {
		if ((i + 1) % n == 0) {
			cout << *(ptr + i) << endl;
		}
		else {
			cout << *(ptr + i) << " ";
		}
	}
}

int main() {
	int a[] = { 1, 2, 3, 4, 5 ,6 ,7 ,8 };
	int m = 2, n = 4;
	showMatrix(a, m, n);
	matrixRotate(a, m, n);
	cout << endl;
	showMatrix(a, n, m);
	return 0;
}