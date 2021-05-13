#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;
using std::cout;
using std::endl;
using std::cin;
using std::max;

/**********************************************************************************************************
������Ͱ����

˵����
	1. ��n�����ݷֱ�ŵ�m��Ͱ֮�У���ÿ��Ͱ���ݽ��п��ţ������1��m��Ͱ������ȡ�����ݼ���������
	2. �����Ƚ����ݵ�max��min���
	3. ͨ��max - min������Ͱ�ĳߴ� bucket_size
	4. (max - min) /  bucket_size ����Ͱ����bucket_num��׼��bucket_num��vector<int>����vector<vector<int>> bucket(bucket_num, vector<int>(xx, 0));
	5. ͨ��(i - min) / bucket_size���a[i]���ڵ�����ֵindex����a[i]���뵽bucket[index]֮��
	6. ͨ��forѭ�����ظ�����5
	7. ͨ��forѭ�������ÿ�����m��bucket[index]����
	8. ˳���������

ע�⣺
	1. Լ�����������ݷֲ��Ͼ��ȣ����ֵ��Сֵ�����ˣ�����Ͱ����Ч�������ã�������˵���������е�����ȫ���ֵ�һ��Ͱ���棬��ô�˻������Ÿ��Ӷ�O(nlogn)
	2. Ͱ�������ó�����ʹ�����ⲿ����https://www.jianshu.com/p/7feeebc54d92 д�Ĳ������Ա�׼�𰸣�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)
	�Ƶ�ʱ�临�Ӷ�O(n): n�����ݷ���m��Ͱ�У�ƽ��ÿ��Ͱ��n/m�����ݣ���ÿ������n/m�����ݵ�m��Ͱ���п��ţ���ʱ�临�Ӷȣ�m * n/m * log(n/m) = nlog(n/m)
	��m�ȽϽӽ�nʱ�������Ǽ����Ĺ�ϵ����ôlog(n/m) = c������O(cn) =: O(n)
�漰����֪ʶ�㣺

***********************************************************************************************************/
void bucketSort(vector<int>& a) {
	//���max��min
	int maxNum = a[0];
	int minNum = a[0];
	for (int i = 1; i < a.size(); i++) {
		maxNum = (maxNum > a[i] ? maxNum : a[i]);
		minNum = (minNum < a[i] ? minNum : a[i]);
	}
	//���bucket_size
	int bucket_size = max((maxNum - minNum) / (int)(a.size() - 1), 1);  //ע�⣬bucket_size��С����С��1����a.size()����ֵ��size_type�����޷���������Ҫת����int���ܽ�������
	//���bucket_num
	int bucket_num = (maxNum - minNum) / bucket_size + 1;
	vector<vector<int>> bucket(bucket_num);
	//�����е�a[i]�ŵ�Ͱ��
	for (int i = 0; i < a.size(); i++) {
		int index = (a[i] - minNum) / bucket_size;
		bucket[index].push_back(a[i]);
	}
	//�ֱ𽫸���Ͱ�������������
	for (int i = 0; i < bucket.size(); i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	//���ź�������ݷŻ�a[i]֮��
	int cnt = 0;
	for (int i = 0; i < bucket.size(); i++) {
		for (int j = 0; j < bucket[i].size(); j++) {
			a[cnt] = bucket[i][j];
			cnt++;
			cout << "Ͱ" << i << "���������Ϊ  " << bucket[i][j] << endl; //������
		}
	}
}

//������
int main() {
	vector<int> a{ 13, 7, 12, 7, 8, 14, 3, 10, 1, 13, 0, 0, 4, 3, 5 };
	bucketSort(a);
	return 0;
}