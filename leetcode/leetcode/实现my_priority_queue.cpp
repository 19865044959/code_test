#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<set>
#include<map>
#include <stack>
using namespace std;

//利用vector实现一个小型的优先级队列 --大顶堆
class myPQ {
public:
	int top() {
		if (a.empty()) return -1;
		return a[0];
	}

	void push(int x) {
		a.push_back(x);
		int n = a.size();
		int i = n - 1;
		int j;
		for (j = i / 2; j > 0; j = i / 2) {
			if (a[j] >= a[i]) break;
			swap(a[j], a[i]);
			i = j;
		}
		if (a[j] < a[i]) swap(a[i], a[j]);
	}

	void pop() {
		int n = a.size();
		swap(a[0], a[n - 1]);
		a.pop_back();
		n--;
		int i = 0;
		for (int j = 2 * i + 1; j < n; j = 2 * i + 1) {
			if (j + 1 < n && a[j] < a[j + 1]) j++;
			if (a[i] >= a[j]) break;
			swap(a[i], a[j]);
			i = j;
		}
	}

	int size() {
		return a.size();
	}

private:
	vector<int> a;
};
int main() {
	myPQ pq;
	for (int i = 0; i < 10; i++) {
		pq.push(10 * i);
	}
	int n = pq.size();
	for (int i = 0; i < n; i++) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}