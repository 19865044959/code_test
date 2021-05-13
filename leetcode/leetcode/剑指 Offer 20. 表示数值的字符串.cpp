#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������

˵���� 
            ˼·��һ����4���ַ����ֱ��ǣ�
                1. ����
                2. .
                3. e/E
                4. +-
            ����ֻ��Ҫ������һ�ֳ��ֺ������᲻���Ѿ����֣����磺
            .�ĳ���֮ǰ�����ֿ���û�г���/�г���
                        .���ܳ���
                        e/E���ܳ���
                        +-�ſ��Գ���Ҳ���Բ�����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺
    �ַ���ɾ��ǰ��ո���Trim
***********************************************************************************************************/

class Solution {
public:
    bool isNumber(string s) {
        /*
            ˼·��һ����4���ַ����ֱ��ǣ�
                1. ����
                2. .
                3. e/E
                4. +-
            ����ֻ��Ҫ������һ�ֳ��ֺ������᲻���Ѿ����֣����磺
            .�ĳ���֮ǰ�����ֿ���û�г���/�г���
                        .���ܳ���
                        e/E���ܳ���
                        +-�ſ��Գ���Ҳ���Բ�����
        */
        bool numFlag = false;
        bool dotFlag = false;
        bool eorEFlag = false;
        bool symbolFlag = false;

        //ȥ��ͷ�ո���β�ո�
        trim(s);

        for (int i = 0; i < s.size(); i++) {
            //���+-�ţ�+-�ų��ֵ��������ڿ�ͷ��i == 0 ������eǰ�棺s[i-1] == 'e/E'
            if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E'));

            //�������
            else if (s[i] >= '0' && s[i] <= '9') numFlag = true;

            //���.��.һ����Ҫ��e/e֮ǰ���֣�����ֻ�ܳ���һ��.
            else if (s[i] == '.' && eorEFlag == false && dotFlag == false) dotFlag = true;

            //���e/E:��֮ǰһ��Ҫ�������֣�����ֻ�ܳ���һ��e/E
            else if ((s[i] == 'e' || s[i] == 'E') && numFlag == true && eorEFlag == false) {
                eorEFlag = true;
                numFlag = false; //��ֹ123Eͨ��
            }
            else {
                return false;
            }
        }
        return numFlag;
    }

    void trim(string& s) {
        if (!s.empty() && (s[0] == ' ' || s[s.size() - 1] == ' ')) {
            s.erase(0, s.find_first_not_of(' '));
            s.erase(s.find_last_not_of(' ') + 1);
        }
    }
};