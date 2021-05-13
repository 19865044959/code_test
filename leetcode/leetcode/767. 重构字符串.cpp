#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������������

˵��������������Ϣ��������ͨ�������𲽱��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        if (n == 1) return S;

        vector<int> hash(26, 0);
        int maxLength = 0;
        int id;
        for (int i = 0; i < n; i++) {
            if (maxLength < ++hash[S[i] - 'a']) {
                maxLength = hash[S[i] - 'a'];
                id = S[i] - 'a';
            }
        }
        /*
        �����������˵����
        ����Ϊ����ʱ��aaabc��  aaaaabc�� ��a��maxnumΪint((length + 1) / 2)
        ����Ϊż��ʱ��aabc��   aaaabc��  ��a��maxnumΪint((length + 1) / 2)
        ���ϣ���maxLength > int((length + 1) / 2)ʱ��һ���޷��ع�
        */
        if (maxLength > int((n + 1) / 2)) return "";

        /*
        ʣ�µ�һ���ǿ��Խ����ع��ģ�����һ�������maxLength��ӦԪ�ر���Ҫ��ż��λ�ã���Ϊaaabc��
        ��Ҫ�ų�abaca��bc�ɻ�����
        ��ô������������������˵����nΪ��������maxLength =int((length + 1) / 2)�����������������žͺ���
        */
        int even = 0;
        int odd = 1;
        string ans(n, ' ');  //�����Ƿ�����Ż�����д�ɣ�string ans(n)�޷�ͨ��
        //�������
        if (n % 2 && maxLength == int((n + 1) / 2)) {
            while (hash[id]) {
                hash[id]--;
                ans[even] = char(id + 'a');
                even += 2;
            }
            for (int i = 0; i < 26; i++) {
                //��ʣ���ȫ���ŵ�����λ��
                while (hash[i] && odd < n) {
                    hash[i]--;
                    ans[odd] = char(i + 'a');
                    odd += 2;
                }
            }
        }
        //�����������������������ȫ������žͺ�
        else {
            for (int i = 0; i < 26; i++) {
                while (hash[i] && even < n) {
                    hash[i]--;
                    ans[even] = char(i + 'a');
                    even += 2;
                }
                while (hash[i] && odd < n) {
                    hash[i]--;
                    ans[odd] = char(i + 'a');
                    odd += 2;
                }
            }
        }
        return ans;
    }
};
