#include <iostream>
#include <vector>
using std::vector;
using std::swap;
/**********************************************************************************************************
������ð�ݷ�

˵����������flag�Ż�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2)  O(1)

�漰����֪ʶ�㣺

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