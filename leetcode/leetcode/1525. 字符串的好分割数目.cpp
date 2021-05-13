#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1������������ʱ��

˵����
	1. ������n���ַ����ַ������ܹ��ָ��n-1�����оٳ�����ÿ�ζ���������ϣ��ͳ�Ƴ���ͬ���ַ�������
	��ͬ��ans++	
    2. 1 <= s.length <= 10^5��ʱ�临�Ӷȱ��뽵����O(n)����O(nlogn)������O(n)��ﵽ10^10����ʱ

ʱ�临�Ӷ���ռ临�Ӷȣ�
	O(n^2):����ÿ�ι�ϣ��ͳ�ƶ�Ҫ����O(n)����Ҫn-1��
	O(n):��ϣ��

�漰����֪ʶ�㣺

***********************************************************************************************************/


/**********************************************************************************************************
����2������ͳ��

˵����
    ������֮���Ի����O(n^2)���Ӷȣ�����Ϊÿ������ȫ���½���ϣ��ͳ��O(n)����ʵ���ϣ�ֻ��Ҫ����ϣ���Լ�ͳ��
    ��������+1����-1����O(1)�����磺aacaba  :  a  acaba  -->   aa cabaֻ��Ҫ������ϣ��a[0]++���Ҳ��ϣ��b[0]--
    �������Ƿ����a[0]��0��1��������Ƿ����b[0]��1��0������������������ʹ��num1++��num2--��������
    ��ȫû��Ҫ����ͳ�ƹ�ϣ��

ʱ�临�Ӷ���ռ临�Ӷȣ�
    O(n):����һ�ι�ϣ��
    O(n):��ϣ��

�漰����֪ʶ�㣺

***********************************************************************************************************/
//���Լ�д�ģ������߿�ʼ����ߡ��ұ߽�������������ϣ���ͳ�ƣ����������ܹ���㣬���Ǵ��븴��
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        if (n == 1) return 0;
        vector<int> a(26, 0);
        vector<int> b(a);
        int ans = 0;
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < int(n / 2); i++) {
            num1 += (a[s[i] - 'a'] == 0);
            a[s[i] - 'a']++;
        }
        for (int i = int(n / 2); i < n; i++) {
            num2 += (b[s[i] - 'a'] == 0);
            b[s[i] - 'a']++;
        }
        if (num1 == num2) ans++;
        vector<int>tempa(a);
        vector<int>tempb(b);
        int tempnum1 = num1;
        int tempnum2 = num2;
        for (int i = int(n / 2) - 1; i >= 0; i--) {
            if (!(--a[s[i] - 'a'])) num1--;
            if (!b[s[i] - 'a']) num2++;
            b[s[i] - 'a']++;
            if (num1 == num2) ans++;
        }

        a = tempa;
        b = tempb;
        num1 = tempnum1;
        num2 = tempnum2;
        for (int i = int(n / 2); i < n; i++) {
            if (!(--b[s[i] - 'a'])) num2--;
            if (!a[s[i] - 'a']) num1++;
            a[s[i] - 'a']++;
            if (num1 == num2) ans++;
        }
        return ans;
    }
};

//��Ϊ����д��
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> leftHash(26, 0);
        vector<int> rightHash(26, 0);
        int leftNum = 0;
        int rightNum = 0;
        int ans = 0;

        //�ǳ������һ��ѭ���͸㶨�˹�ϣ��Ĺ������ϣ���з���Ԫ�ظ�����ͳ��
        for (int i = 0; i < n; i++) {
            rightNum += (rightHash[s[i] - 'a'] == 0); //���ĳ����ĸ�ڹ�ϣ���е�һ�μ�¼����ôrightNum++
            rightHash[s[i] - 'a']++;
        }

        //�൱�ڴ��Ҳ���ַ���/��ϣ��ȡ��һ���ַ��͸�����ַ���/��ϣ�����鿴���Ҳ಻��ͬ���ַ����Ƿ���ͬ
        for (int i = 0; i < n; i++) {
            leftNum += (leftHash[s[i] - 'a'] == 0); //�ӵ�ʱ�����ж��Ƿ�Ϊ��һ�μ�¼������Ǿ�++
            leftHash[s[i] - 'a']++;
            rightHash[s[i] - 'a']--;
            rightNum -= (rightHash[s[i] - 'a'] == 0); //����ʱ������Ҫ�ȼ������жϼ�����Ԫ��hash���Ƿ�Ϊ0��Ϊ0˵��Ԫ����ʧ��--
            ans += (leftNum == rightNum); //���������һʯ����
        }
        return ans;
    }
};