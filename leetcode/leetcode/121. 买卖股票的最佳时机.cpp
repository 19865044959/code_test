#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1��������

˵������ʱ

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         int n = prices.size();
         vector<int> dp(n);
         dp[0] = prices[0];
         int maxVal = dp[0];
         for(int i = 1; i < n; i++){
             dp[i] = max(prices[i] - prices[i-1], prices[i] + dp[i-1] - prices[i-1]);
             maxVal = max(maxVal, dp[i]);
         }
         if(maxVal < 0) return 0;
         else{
             return maxVal;
         }
     }
 };


 /**********************************************************************************************************
����2��һ�α���

˵����
    ���Ʊ�϶�������͵�����ߵ���������͵㲻һ����������ߵ��ǰ�棬������ǿ���������
    1. ʱ��ά��һ�����������������0 -- i-1��Ԫ�ص���Сֵ
    2. prices[i] - min ��ȡ�ڵ�i����ʱ��������߼۸�
    3. max(maxVal, prices[i] - min) ά��ǰi���Ʊ���������
    4. ����0 - n -1,���maxVal

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         int n = prices.size();
         int minVal = INT_MAX;
         int maxPro = 0;
         for (int i = 0; i < n; i++) {
             maxPro = max(maxPro, prices[i] - minVal);
             minVal = min(prices[i], minVal);
         }
         return maxPro;
     }
 };

 //��д����һ����ʽ

 class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         int n = prices.size();
         int maxVal = INT_MIN;
         int maxPro = 0;
         for (int i = n - 2; i >= 0; i--) {
             maxVal = max(maxVal, prices[i + 1]);
             maxPro = max(maxPro, maxVal - prices[i]);
         }
         return maxPro;
     }
 };