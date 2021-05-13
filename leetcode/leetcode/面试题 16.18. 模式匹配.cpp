#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
���������ݽ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m*n)?  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    bool patternMatching(string pattern, string value) {
        vector<int> cnt(2, 0);
        // ���������
        // 1. patternΪ��
        if (pattern.empty()) return value.empty();

        // 2. pattern��Ϊ��
        // 2.1 valueΪ��, �ж�pattern�Ƿ�ֻ��һ����ĸ���
        if (value.empty()) {
            for (int i = 1; i < pattern.size(); i++) {
                if (pattern[0] != pattern[i]) return false;
            }
            return true;
        }

        // 2.2 pattern��Ϊ�գ�value��Ϊ��
        int n = pattern.size(), m = value.size();
        //   Ԥ����ͳ��a, b��ĸ����cnt[0], cnt[1]
        for (int i = 0; i < n; i++) {
            cnt[pattern[i] - 'a']++;
        }
        //   �ж�cnt[0], cnt[1]�Ƿ���Ϊ0�����
        if (cnt[0] == 0) return helper(value, cnt[1]);
        else if (cnt[1] == 0) return helper(value, cnt[0]);

        //  2.2.1 ����ʹ��a,b����֮һΪ��, ������Ϊ0
        if (helper(value, cnt[0])) return true;
        else if (helper(value, cnt[1])) return true;

        // 2.2.2 a,b����Ϊ��; ö��a, bƥ��ĳ��ȣ�ʹ��a * len_a + b * len_b = m; len_aΨһȷ��len_b��ֻ��ö��len_a
        for (int len_a = 1; len_a * cnt[0] <= m - cnt[1]; len_a++) {
            if ((m - cnt[0] * len_a) % cnt[1] != 0) continue;
            int len_b = (m - cnt[0] * len_a) / cnt[1];
            if (check(pattern, value, len_a, len_b)) return true;
        }
        return false;
    }

    bool helper(string value, int k) { // pattern��Ϊ�գ�value��Ϊ��. �ж��Ƿ����k���з�value
        int m = value.size();
        if (m % k != 0) return false;
        int len = m / k;
        for (int i = len; i < m; i += len) {
            if (value.substr(0, len) != value.substr(i, len)) return false;
        }
        return true;
    }

    bool check(string pattern, string value, int len_a, int len_b) {
        vector<string> a{ "", "" };
        int m = pattern.size();
        for (int i = 0, j = 0; i < m; i++) {
            if (pattern[i] == 'a') {
                if (a[0] == "") a[0] = value.substr(j, len_a);
                else if (value.substr(j, len_a) != a[0]) return false;
                j += len_a;
            }
            else if (pattern[i] == 'b') {
                if (a[1] == "") a[1] = value.substr(j, len_b);
                else if (value.substr(j, len_b) != a[1]) return false;
                j += len_b;
            }
        }
        return true;
    }

};
