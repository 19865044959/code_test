#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：仿二叉树遍历

说明：
    超时
时间复杂度与空间复杂度：	O(C(m + n - 2)(n - 1))     O(C(m + n - 2)(n - 1))

涉及到的知识点：
	二叉树遍历

***********************************************************************************************************/
 class Solution {
 public:
     long long uniquePaths(int m, int n) {
         dfs(m, n, 1, 1);
         return res;
     }
 private:
     long long res = 0;
     void dfs(int m, int n, int i, int j){
         if(i > m || j > n){
             return;
         }
         if(i == m && j == n){
             res++;
         }
         dfs(m, n, i + 1, j);
         dfs(m, n, i, j + 1);
         return;
     }
 };

 /**********************************************************************************************************
方法2：排列组合

说明：
    公式：C(m + n - 2)(m - 1)

时间复杂度与空间复杂度：O(1)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     long long uniquePaths(int m, int n) {
         long long temp = 1;
         int j = 1;
         for (int i = n; i <= m + n - 2; i++) {
             temp *= i;

             //优化1：每次相除，一定会除开没有余数，可以举例子，至于为什么，我不会证明
             // if(j <= m - 1 && temp % j == 0){
             //     temp /= j;
             //     j++;
             // }

             temp /= j;
             j++;
         }

         // 优化2：上面的循环，[n, m + n - 2]共有 m - 1个数，正好j也循环了m - 1次到达 m，while是多余的
         // while(j <= m - 1){
         //     temp /= j;
         //     j++;
         // }

         return temp;
     }
 };

 /**********************************************************************************************************
方法：动态规划

说明：见不同路径2，DP里面

时间复杂度与空间复杂度：O(m * n)  O(m * n)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     long long uniquePaths(int m, int n) {
         vector<vector<int>> dp(n, vector<int>(m, 0));
         int row = n;
         int column = m;
         for (int i = 0; i < row; i++) {
             dp[i][0] = 1;
         }
         for (int j = 0; j < column; j++) {
             dp[0][j] = 1;
         }
         for (int i = 1; i < row; i++) {
             for (int j = 1; j < column; j++) {
                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
             }
         }
         return dp[row - 1][column - 1];
     }
 };
