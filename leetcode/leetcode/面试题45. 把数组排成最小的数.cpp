#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
�漰����֪ʶ�㣺
1.sort������ʵ��3��������ǰ���������������������һ��������������һ��������Ҫ��
    (1)�ú�������ֵbool���ͣ��ҽ�����������
    (2)���ú���returnֵΪtrue����˵����һ���������ݵ�Ԫ��<�ڶ�����������Ԫ��
    (3)ֻ��Ҫ���ݺ�������������Ҫ����

2.�Ǿ�̬��Ա����������Ĭ�ϲ���thisָ�룬������stringValueDefine����static�Ļ�����3�������Ӷ�����

3.static�ؼ�����c++�е����ã�
    (1)���������ڣ���̬��Ա�������߾�̬�����������еĳ�Ա�������������������ǳ�����������ڣ����Ա�޹�
    (2)���������⣬����ȫ�ֱ��������ߺ�������ô�������ߺ���ֻ���ڱ��ļ���ʹ�ã��޷�����extern�������ļ��е��ã�
    ��˿�������static��һ������֮�еĲ�ͬԴ�ļ�֮������ͬ�����������ᷢ���ض������
    (��������Һ�Ȩ�������processState�������ظ�����)

4.string֮��������ַ�����ƴ�Ӳ���

5.c++֮�У��ַ������бȽ��ǱȽϵ�һ������ͬ��ĸ��ascii�룬��ascii��������<��д��ĸ<Сд��ĸҪע��

6.����to_string(��stringͷ�ļ�֮��)����ʵ��int -> string
***********************************************************************************************************/
class Solution_45 {
public:
    string minNumber(vector<int>& nums) {
        vector<string> temp;
        for (auto i : nums) {
            temp.push_back(to_string(i));
        }
        sort(temp.begin(), temp.end(), stringValueDefine);
        string ans = "";
        for (auto i : temp) {
            ans += i;
        }
        return ans;
    }

private:
    static bool stringValueDefine(string& str1, string& str2) {
        return str1 + str2 < str2 + str1;
    }
};