#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������������C++ϰ��10_9�����֪ʶ

˵�����������˼�˵ɾ��ĳЩ�ַ����õ�����ʾ��ÿ�����ֵ��ַ�����Ҫ����˳��

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺
    1.lambda���ʽ
***********************************************************************************************************/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), greater<string>());//���ֵ���
        stable_sort(d.begin(), d.end(), [](string a, string b) {return a.size() < b.size();});//���ַ�����С�������򣬲��Ҳ��������ֵ���

        vector<int> barrel(26, 0); //Ͱ����
        for (auto i : s) {
            barrel[i - 'a']++;
        }
        string ans = "";
        for (int i = d.size() - 1; i >= 0; i--) {
            vector<int> temp(barrel);
            int flag = 1;
            for (auto j : d[i]) {
                if (temp[j - 'a']) {
                    temp[j - 'a']--;
                    continue;
                }
                flag = 0;
                break;
            }
            if (flag) {
                ans = d[i];
                break;
            }
        }
        return ans;
    }
};

/**********************************************************************************************************
������

˵�������⣬���ǵ���˳��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(mn)������m = s.size(), n = d.size()  �ռ临�Ӷȣ�O(m)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (auto str : d) {
            int j = 0;
            for (int i = 0; i < s.size() && j < str.size(); i++) {
                if (s[i] == str[j]) j++;
            }
            if (j == str.size()) {
                if (str.size() > ans.size() || (str.size() == ans.size() && (ans[0] - str[0] > 0))) {
                    ans = str;
                }
            }
        }
        return ans;
    }
};