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

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     string replaceSpace(string s) {
     string res;
     for(char ch : s){
         if(ch == ' ') res.append("%20");
         else res.push_back(ch);
     }
     return res;
     }
 };

 /**********************************************************************************************************
������ԭ���㷨

˵����
    1. ��ÿ���ո��Ϊ"%20"����ÿ���滻��s�ĳ��ȶ�Ҫ+2
    2. ͳ��s�пո�������Ϊcount����ô�ı�s�ĳ��ȣ�s.resize(length + 2 * count)
    3. �Ӻ���ǰ��������ָ�룬һ��ָ��ָ��length - 1��һ��ָ��ָ��s.size() - 1��ԭ���滻����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     string replaceSpace(string s) {
         int length = s.size();
         int count = 0;
         for (int i = 0; i < length; i++) {
             if (s[i] == ' ') count++;
         }
         s.resize(length + 2 * count);
         for (int i = length - 1, j = s.size() - 1; i >= 0; i--, j--) {
             if (s[i] == ' ') {
                 s[j] = '0';
                 s[j - 1] = '2';
                 s[j - 2] = '%';
                 j -= 2;
             }
             else {
                 s[j] = s[i];
             }
         }
         return s;
     }
 };
