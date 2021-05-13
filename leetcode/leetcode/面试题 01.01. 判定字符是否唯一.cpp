#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
��������ϣ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     bool isUnique(string astr) {
         vector<int> hash(26, 0);
         int n = astr.size();
         for(int i = 0; i < n; i++){
             if(++hash[astr[i] - 'a'] > 1) return false;
         }
         return true;
     }
 };


 /**********************************************************************************************************
������λ����

˵����
    ��һ�����ͱ�����ģ��26��int���͵����飬ÿ�ν�1����λ��astr[i] - 'a'��&����int���ͱ���mark��
    ��mark == 0ʱ˵��֮ǰû�г��ֹ������ĸ��return false
    Ȼ�����mark��������Ӧ��astr[i] - 'a'��1��˵������ĸ�Ѿ����ֹ�
    �ٴγ��־ͻ�return false

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     bool isUnique(string astr) {
         int mark = 0;
         int n = astr.size();
         for (int i = 0; i < n; i++) {
             if ((mark & 1 << (astr[i] - 'a')) != 0) return false; //ע����Ҫ������������(mark & 1 << (astr[i] - 'a')) != 0����Ϊ!=���ȼ�����&
             else mark = mark | 1 << (astr[i] - 'a');
         }
         return true;
     }
 };
