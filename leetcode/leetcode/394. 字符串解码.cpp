#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

/**********************************************************************************************************
���������ö�ջ��������

˵����
    �ѵ㣺̫�����ˣ���ʹ�������ʵ��Ҳ�������أ����׳���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺
    �����ÿһ�����Ǿ�����
***********************************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string ans = "";
        stack<pair<int, string>>sta; //����������֮ǰѧϰ��pair����(int,string)�����һ�𣬱��ڹ���
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num *= 10; //����ΪʲôҪ��10����Ϊ���num��2λ�������ϣ�����382[a]����ô��Ҫ3*100 + 8*10 + 2��a
                num += s[i] - '0';
            }
            else if (s[i] == '[') {
                sta.push({ num, ans }); //s.push(pair<int, string>{num, ans})��s.push(make_pair(num, ans))����
                num = 0; //�������num��ans�Ƿǳ����׺��Եģ�
                ans = "";
            }
            else if (s[i] == ']') {
                int tempNum = sta.top().first;
                string tempStr = sta.top().second;
                sta.pop();
                //ע�⣺������tempNum��ans�ӵ�tempStr����
                for (int j = 0; j < tempNum; j++) {
                    tempStr += ans;
                }
                ans = tempStr; //��ans���tempStr
            }
            else if (isalpha(s[i])) {
                ans += s[i];
            }
        }
        return ans;
    }
};

/**********************************************************************************************************
������������������ԭ����������ԣ����õݹ�������

˵����
     b3[a2[c]]--> ǰ�����ַ��ǣ�b3��������'['ʱ�� a2��b3���������ԣ���������'['ʱ��c��a2��b3���������ԣ���˱�����Եݹ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺
    �����ÿһ�����Ǿ�����
***********************************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
    string dfs(string& s, int& i) {
        string res;
        int multi = 0;
        for (;i < s.length(); ++i) {
            if ('0' <= s[i] && '9' >= s[i]) {
                multi = multi * 10 + int(s[i] - '0');
            }
            else if (s[i] == '[') {
                string temp1, temp2 = dfs(s, ++i);
                while (multi != 0) {
                    temp1.append(temp2);
                    --multi;
                }
                res += temp1;
            }
            else if (s[i] == ']') {
                return res;
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};