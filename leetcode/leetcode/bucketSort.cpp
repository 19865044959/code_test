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
方法：桶排序

说明：
	1. 将n个数据分别放到m个桶之中，将每个桶数据进行快排，最后在1到m个桶中依次取出数据即是有序结果
	2. 首先先将数据的max与min求出
	3. 通过max - min，估计桶的尺寸 bucket_size
	4. (max - min) /  bucket_size 就是桶个数bucket_num，准备bucket_num个vector<int>，以vector<vector<int>> bucket(bucket_num, vector<int>(xx, 0));
	5. 通过(i - min) / bucket_size求出a[i]所在的索引值index，将a[i]加入到bucket[index]之中
	6. 通过for循环，重复步骤5
	7. 通过for循环，利用快排求m个bucket[index]排序
	8. 顺序输出即可

注意：
	1. 约束条件是数据分布较均匀，最大值最小值不极端，否则桶排序效果并不好，如果极端的情况，所有的数据全部分到一个桶里面，那么退化到快排复杂度O(nlogn)
	2. 桶排序适用场景：使用与外部排序，https://www.jianshu.com/p/7feeebc54d92 写的不错（面试标准答案）

时间复杂度与空间复杂度：O(n)  O(n)
	推导时间复杂度O(n): n个数据放入m个桶中，平均每个桶有n/m个数据，将每个含有n/m个数据的m个桶进行快排，有时间复杂度：m * n/m * log(n/m) = nlog(n/m)
	当m比较接近n时，比如是几倍的关系，那么log(n/m) = c，故有O(cn) =: O(n)
涉及到的知识点：

***********************************************************************************************************/
void bucketSort(vector<int>& a) {
	//求出max与min
	int maxNum = a[0];
	int minNum = a[0];
	for (int i = 1; i < a.size(); i++) {
		maxNum = (maxNum > a[i] ? maxNum : a[i]);
		minNum = (minNum < a[i] ? minNum : a[i]);
	}
	//求出bucket_size
	int bucket_size = max((maxNum - minNum) / (int)(a.size() - 1), 1);  //注意，bucket_size最小不能小过1，且a.size()返回值是size_type，是无符号数，需要转换成int才能进行运算
	//求出bucket_num
	int bucket_num = (maxNum - minNum) / bucket_size + 1;
	vector<vector<int>> bucket(bucket_num);
	//将所有的a[i]放到桶里
	for (int i = 0; i < a.size(); i++) {
		int index = (a[i] - minNum) / bucket_size;
		bucket[index].push_back(a[i]);
	}
	//分别将各个桶里面的数据排序
	for (int i = 0; i < bucket.size(); i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	//将排好序的数据放回a[i]之中
	int cnt = 0;
	for (int i = 0; i < bucket.size(); i++) {
		for (int j = 0; j < bucket[i].size(); j++) {
			a[cnt] = bucket[i][j];
			cnt++;
			cout << "桶" << i << "里面的数据为  " << bucket[i][j] << endl; //测试用
		}
	}
}

//测试用
int main() {
	vector<int> a{ 13, 7, 12, 7, 8, 14, 3, 10, 1, 13, 0, 0, 4, 3, 5 };
	bucketSort(a);
	return 0;
}