#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������Ͱ����

˵����������hash��ֻҪ����Ŀ������ȷ���߰�ʾ˵����ΪСд/��д��ĸ����Ϊ����(�ҷ�Χ����)�����Կ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺
    1.string�ķ�Χforѭ��ȡ���������ַ����ַ�����ͨ���Ӽ�ĳ�������������һ���ַ������ɾ���ascii��
    ���磺
            string temp{'a' + 2, 'c' - 1, 'd'}; //�Ϸ���temp = "cbd"
    ע�⣺�ַ������������Ӽ������"a" - 2���Ǿ��Դ���ģ�

***********************************************************************************************************/
class Solution {
public:
    string sortString(string s) {
        vector<int> barrel(26, 0);
        for (auto i : s) {
            barrel[i - 'a']++;
        }
        string ans;
        while (ans.size() != s.size()) {
            for (int i = 0; i < barrel.size(); i++) {
                addChar(barrel, ans, i);
            }
            for (int j = barrel.size() - 1; j >= 0; j--) {
                addChar(barrel, ans, j);
            }
        }
        return ans;
    }
private:
    void addChar(vector<int>& barrel, string& ans, int i) {
        if (barrel[i]) {
            barrel[i]--;
            ans.push_back(i + 'a');
        }
    }
};