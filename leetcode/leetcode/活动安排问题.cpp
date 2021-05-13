#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������̰��

˵����ע��end����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class ActivityArrange {
public:
	vector<int> AcAr(vector<int>& startv, vector<int>& endv) {
		int length = startv.size();
		if (length == 0) return {};
		vector<int> res(1); //Ĭ��startv[0] endv[0]��ѡ
		int tail = endv[0];
		for (int i = 0; i < length; i++) {
			if (startv[i] >= tail) {
				res.push_back(i); //�ֲ����ţ�����˳���ң�ֻҪ�ҵ�����tail�ĵ�һ��startv����ѡ��������push������
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
