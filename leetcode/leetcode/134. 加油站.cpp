#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1��������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n = gas.size();
         int sum;
         int flag;
         for(int i = 0; i < n; i++){
             flag = 1;
             sum = 0;
             for(int j = i; j < i + n; j++){
                 sum += gas[j % n] - cost[j % n];
                 if(sum < 0) {
                     flag = 0;
                     break;
                 }  
             }
             if(flag) return i;
         }
         return -1;
     }
 };


 /**********************************************************************************************************
 ����2��̰��

 ˵����
    ����0�����������ܴ�x����վ�ߵ�y����վ��gas[x] + gas[x+1] + ... + gas[y] < cost[x] + cost[x+1] + ... + cost[y]
    ����1�����������ܴ�x����վ�ߵ�y����վ���߲��꣬��ô��j����վ������ߵ�y����վ������j = x, x+1, x+2 ... y;
    ����2�����gas[0] + gas[1] + ... + gas[n-1] >= cost[0] + cost[1] + ... + cost[n-1]�������һ���н�

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/

 class Solution {
 public:
     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int sum = 0;
         int cur = 0;
         int p = 0;
         int n = gas.size();
         for (int i = 0; i < n; i++) {
             cur += gas[i] - cost[i];
             sum += gas[i] - cost[i];
             if (cur < 0) {
                 p = i + 1;
                 cur = 0;
             }
         }
         return sum < 0 ? -1 : p;
     }
 };