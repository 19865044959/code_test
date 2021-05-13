#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：贪心

说明：注意end升序

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

class ActivityArrange {
public:
	vector<int> AcAr(vector<int>& startv, vector<int>& endv) {
		int length = startv.size();
		if (length == 0) return {};
		vector<int> res(1); //默认startv[0] endv[0]必选
		int tail = endv[0];
		for (int i = 0; i < length; i++) {
			if (startv[i] >= tail) {
				res.push_back(i); //局部最优：按照顺序找，只要找到大于tail的第一个startv，就选定了它，push入数组
				tail = endv[i];
			}
		}
		return res;
	}
};

int main() {
	vector<int> startv({ 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 });
	vector<int> endv({ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
	ActivityArrange a;
	auto res = a.AcAr(startv, endv);
	for (int i = 0; i < res.size(); i++) {
		cout << startv[res[i]] << "->" << endv[res[i]] << endl;
	}
	return 1;
}
