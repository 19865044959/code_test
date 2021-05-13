#include <iostream>
#include <vector>
using std::vector;
using std::swap;

/**********************************************************************************************************
������������

˵����
	�����������low ��high��������ֵ��low = 0;  high = c.size() - 1
	������������ǳ���n����n = c.size()

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)  O(1)

�漰����֪ʶ�㣺
	1. ��������ݽṹ�����������ͬ�����������Ҷ��Ӵ���˫�׽ڵ㣬�����С��˫�׽ڵ�
		��ʵ�ֵ��ǣ����׽ڵ��ϸ�����ӽڵ�(�󶥶�)/���׽ڵ��ϸ�С���ӽڵ�(С����)
	2. ��ȫ�������ļ������ʣ�
		����֪һ������nums����Ԫ����һ����ȫ�������Ĳ����������ô��
		���һ���ڵ㣬��Ӧ�±�Ϊi����ô��
			��i == 0 ˵���Ǹ��ڵ㣬û��˫�׽�㡣
			�ڳ��ˢ����⣬��˫�׽ڵ�Ϊi / 2����������ʿ��Էǳ������ҳ����һ���к��ӵĽڵ㣺(n - 1) / 2
	
		���һ���ڵ��±�Ϊi����ô��
			��if(2 * i + 1 < n)�����±�i�������±�Ϊ2 * i + 1
			��if(2 * i + 2 < n)�����±�i���Һ����±�Ϊ2 * i + 2
***********************************************************************************************************/
//�Ѵ���������˵����ѡ��a[i]��Ϊ���ڵ㣬�����������һ��Ѵ�����
void heapify(vector<int>& a, int i, int n) {
	int tmp = a[i];
	for (int j = 2 * i + 1; j < n; j = 2 * i + 1) {
		if (j + 1 < n && a[j] < a[j + 1]) j++;
		if (tmp >= a[j]) break;
		a[i] = a[j];
		i = j;
	}
	a[i] = tmp;
}

void heapSort(vector<int>& a, int n) {
	//����󶥶�
	for (int i = (n - 1) / 2; i >= 0; i--) { // i = floor(n / 2) - 1�Ǻ��ӽڵ�����ֵ����ÿ���к��ӵĽڵ㿪ʼ�����жѴ�����
		heapify(a, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, 0, i); //ע��������i������i-1��ԭ����i = n - 1����heapify�������ǳ���n�������������n - 1
	}
}

int main() {
	vector<int> a{ 4,2,14,661,443,224,11243,2,44 }; //�������Ĳ������
	heapSort(a, a.size());
	return 0;
}

