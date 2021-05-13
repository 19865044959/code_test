#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1��������/̰�ģ� �ж��ֹ����ĵط�flowerbed[i] == 1�Ӷ������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         int cnt = 0;
         bool flag = false;
         int flag1 = -1;
         int flag2 = -1;
         for(int i = 0; i < flowerbed.size(); i++){
             if(flowerbed[i]){
                 if(!flag){ //����0 0 1 0 1 0 0 0��[0,0,1]���ֲ�ֵ
                     cnt += (i - 0) / 2;
                     flag = true;
                 }
                 flag1 = flag2;
                 flag2 = i;
                 if(flag1 >= 0 && flag2 >= 0){
                     cnt += (flag2 - flag1) / 2 - 1;
                     if(cnt >= n) return true;
                 }
             }
         }
         if(flag2 >= 0){
             cnt += (flowerbed.size() - flag2 - 1) / 2; //����0 0 1 0 1 0 0 0��[1, 0, 0, 0]���ֲ�ֵ
         }
         else{//˵��ȫ��0
             cnt += (flowerbed.size() + 1) / 2;
         }
         return cnt >= n;
     }
 };


 /**********************************************************************************************************
����2��������/̰�ģ� �ж�û�ֹ����ĵط�flowerbed[i] == 0�Ӷ������

˵���� 

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         for (int i = 0; i < flowerbed.size(); i += 2) {
             if (!flowerbed[i]) {
                 if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                     n--; //˵�����Բ廨
                 }
                 else {
                     i++; //��������л��ĵط����´�i += 2�Ļ��Ϳ���ֻ�ܺ����Ƿ��Ż�������ǰ���Ƿ��Ż���(��Ϊǰ��һ�����ᰤ��)
                 }
             }
         }
         return n <= 0;
     }
 };