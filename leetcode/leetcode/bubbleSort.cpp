#include <iostream>
#include <vector>
using std::vector;
using std::swap;
/**********************************************************************************************************
方法：冒泡法

说明：加入了flag优化

时间复杂度与空间复杂度：O(n^2)  O(1)

涉及到的知识点：

***********************************************************************************************************/

void bubbleSort(vector<int> &a) {
	int flag;
	for (int i = 0; i < a.size() - 1; i++) {
		flag = 0;
		for (int j = a.size() - 1; j > i; j--) {
			if (a[j - 1] > a[j]) swap(a[j-1], a[j]);
			flag = 1;
		}
		if (flag == 0) break;
	}
}

int main() {
	vector<int> a{ 4,2,14,661,443,224,11243,2,44 };
	bubbleSort(a);
	return 0;
}