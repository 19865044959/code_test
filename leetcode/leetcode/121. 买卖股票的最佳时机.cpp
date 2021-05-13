#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：暴力法

说明：超时

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

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
方法2：一次遍历

说明：
    买股票肯定想在最低点买，最高点卖，但最低点不一定出现在最高点的前面，因此我们可以这样：
    1. 时刻维护一个变量，这个变量是0 -- i-1个元素的最小值
    2. prices[i] - min 获取在第i天卖时卖出的最高价格
    3. max(maxVal, prices[i] - min) 维护前i天股票的最高收益
    4. 遍历0 - n -1,输出maxVal

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

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

 //我写的另一种形式

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