//����һ��n * n��һάͼ�����ܹ�ԭ����ת90����
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//˳ʱ����ת90��
/*
	����ת�� + �б任
	(i, j) -- > (j, i) -- > (j, n - 1 - i)
	��(i, j) - > (n - 1 - i, j) - > (n - 1 - i, n - 1 - j) - > (n - 1 - j, i) - > (i, j)�γ�ѭ��
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