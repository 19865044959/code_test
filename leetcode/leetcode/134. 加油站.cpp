#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：暴力法

说明：

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

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
 方法2：贪心

 说明：
    结论0：如果车最多能从x加油站走到y加油站，gas[x] + gas[x+1] + ... + gas[y] < cost[x] + cost[x+1] + ... + cost[y]
    结论1：如果车最多能从x加油站走到y加油站，走不完，那么从j加油站最多能走到y加油站，其中j = x, x+1, x+2 ... y;
    结论2：如果gas[0] + gas[1] + ... + gas[n-1] >= cost[0] + cost[1] + ... + cost[n-1]则该问题一定有解

 时间复杂度与空间复杂度：O(n) O(1)

 涉及到的知识点：

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