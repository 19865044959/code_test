/*
	�����Ӵ����⣺����һ�����֣���������Ӵ������ֵ
	��dp[i]����nums[i]��β�������Ӵ������ͣ����У�
	״̬ת�Ʒ��̣�dp[i] = max(dp[i - 1] + nums[i], nums[i])
	ʱ�䣺O(n) �ռ���Ż���O(1)

	https://www.nowcoder.com/test/28665338/summary ���ŵ�����
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//O(n) O(1)
int getBestDeli(vector<int>& vec) {
    int a = 0;
    int res1 = 0;
    int total = 0;
    for (int i = 1; i <= vec.size(); i++) {
        a = max(a + vec[i - 1], vec[i - 1]);
        res1 = max(res1, a);
        total += vec[i - 1];
    }
    a = INT_MAX / 2;
    int res2 = INT_MAX / 2;
    for (int i = 1; i <= vec.size(); i++) {
        a = min(a + vec[i - 1], vec[i - 1]);
        res2 = min(res2, a);
    }
    res2 = total - res2;
    return max(res1, res2);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        vector<int>vec(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        cout << getBestDeli(vec) << endl;
    }

    return 0;
}

//O(n^2) O(1)

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        vector<int>vec(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        int a;
        int res = 0;
        for (int p = 0; p < n; p++) {
            a = 0;
            for (int q = 1; q <= n; q++) {
                a = max(a + vec[(q - 1 + p) % n], vec[(q - 1 + p) % n]);
                res = max(res, a);
            }
        }
        cout << res << endl;
    }

    return 0;
}
