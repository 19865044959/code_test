#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺
1. ��������45
2. ""��������ַ�������''��������ַ���string[i]���ص����ַ��������ַ������������Ҫ�õ����Ŷ�����˫����

***********************************************************************************************************/
class Solution_179 {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for (auto i : nums) {
            temp.push_back(to_string(i));
        }
        sort(temp.begin(), temp.end(), findMax);
        string ans = "";
        for (auto i : temp) {
            ans += i;
            if (ans[0] == '0') break;//ע�⣡������д��"0"����Ϊ""���ַ�������ans[0]���ص����ַ���
        }
        return ans;
    }

private:
    static bool findMax(string str1, string str2) {
        return str1 + str2 > str2 + str1;
    }
};