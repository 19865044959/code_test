#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：分为两种状态：一种是不操作，第二种是：当身上有股票，卖出；当身上没股票，买入

时间复杂度与空间复杂度：O(2^n), O(n)

涉及到的知识点：

***********************************************************************************************************/
//暴力法
//分为两种状态：一种是不操作，第二种是：当身上有股票，卖出；当身上没股票，买入
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dfs(prices, 0, 0, 0);
        return res;
    }
private:
    int res = 0;
    int n;
    /*
    @param prices:数组
    @param index:代表天数，从0开始
    @param profit:获利
    @param status:0代表不持有，1代表持有股票
    */
    void dfs(vector<int>& prices, int index, int profit, int status) {
        if (n == index) {
            res = max(res, profit);
            return;
        }
        dfs(prices, index + 1, profit, status);//第一种情况递归，注意：如果不写这个递归，那么就会少了不操作的情况，整个系统只能买或者不买，这显然是不对的
        //第二种情况，由两个小情况组成：
        if (status == 0) {
            //转至持有股票,status = 1
            dfs(prices, index + 1, profit - prices[index], 1);
        }
        else {
            //转至卖出股票，status = 0
            dfs(prices, index + 1, profit + prices[index], 0);
        }
    }
};


/**********************************************************************************************************
方法：贪心算法

说明：
    差分思想
    未能理解

时间复杂度与空间复杂度：O(n), O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            //res += prices[i] - prices[i-1] > 0 ? (prices[i] - prices[i-1]) : 0;
            int temp = prices[i] - prices[i - 1];
            if (temp > 0) res += temp;
        }
        return res;
    }
};