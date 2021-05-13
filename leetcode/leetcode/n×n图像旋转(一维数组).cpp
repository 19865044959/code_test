//给定一个n * n的一维图像，你能够原地旋转90°吗？
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//顺时针旋转90度
/*
	等于转置 + 列变换
	(i, j) -- > (j, i) -- > (j, n - 1 - i)
	∴(i, j) - > (n - 1 - i, j) - > (n - 1 - i, n - 1 - j) - > (n - 1 - j, i) - > (i, j)形成循环
*/
void rotateMatrix(int* ptr, int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - 1 - i; j++) {
			int tmp = *(ptr + i * n + j);
			*(ptr + i * n + j) = *(ptr + (n - 1 - j) * n + i);
			*(ptr + (n - 1 - j) * n + i) = *(ptr + (n - 1 - i) * n + n - 1 - j);
			*(ptr + (n - 1 - i) * n + n - 1 - j) = *(ptr + j * n + (n - 1 - i));
			*(ptr + j * n + (n - 1 - i)) = tmp;
		}
	}
}

void showMatrix(int* ptr, int n) {
	for (int i = 0; i < n * n; i++) {
		if ((i + 1) % n == 0) {
			cout << *(ptr + i) << endl;
		}
		else {
			cout << *(ptr + i) << " ";
		}
	}
}

int main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* ptr = a;
	showMatrix(ptr, 3);
	rotateMatrix(ptr, 3);
	cout << endl;
	showMatrix(ptr, 3);

	return 0;
}