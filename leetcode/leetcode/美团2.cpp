#include<iostream>
#include<assert.h>
#include <vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>nDist(n, 0);
		vector<int>mDist(m, 0);
		for (int i = 0; i < n; i++) {
			cin >> nDist[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> mDist[i];
		}
		sort(nDist.begin(), nDist.end());
		sort(mDist.begin(), mDist.end());
		int minVal = min(nDist[0], mDist[0]) - 1;
		int maxVal = max(nDist[n - 1], mDist[m - 1]);
		int nNow = 2 * n;
		int mNow = 2 * m;
		int MaxDiff = mNow - nNow;
		int ptrn = 0;
		int ptrm = 0;
		for (int i = minVal; i <= maxVal; i++) {
			while (ptrn < n && nDist[ptrn] < i) ptrn++;
			while (ptrn < n && nDist[ptrn] == i) {
				ptrn++;
				nNow--;
			}
			while (ptrm < m && mDist[ptrm] < i) ptrm++;
			while (ptrm < m && mDist[ptrm] == i) {
				ptrm++;
				mNow--;
			}
			MaxDiff = max(MaxDiff, mNow - nNow);
		}
		cout << MaxDiff << endl;
	}
	return 0;
}