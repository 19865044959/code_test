#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
���������ն������ݹ飬�������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(2^(n-1)) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         n = triangle.size();
         dfs(triangle, 0, 0, 0);
         return res;
     }
 private:
     int n;
     int res = INT_MAX;
     void dfs(vector<vector<int>>& triangle, int depth, int width, int sumVal){
         if(depth == n){
             res = min(res, sumVal);
             return;
         }
         dfs(triangle, depth + 1, width, sumVal + triangle[depth][width]);
         dfs(triangle, depth + 1, width + 1, sumVal + triangle[depth][width]);
     }
 };

 /**********************************************************************************************************
�����������Ǳ�����⣬ֱ�ӷ���ֵ

˵����
    f(i, j) = min(f(i+1, j), f(i+1, j+1)) + triangle[i][j]

ʱ�临�Ӷ���ռ临�Ӷȣ�ͬ��

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         n = triangle.size();
         return dfs(triangle, 0, 0);
     }
 private:
     int n;
     int dfs(vector<vector<int>>& triangle, int i, int j) {
         if (i == n) {
             return 0;
         }
         return min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
     }
 };

 /**********************************************************************************************************
����������������ݹ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         n = triangle.size();
         vector<vector<int>> temp(n, vector<int>(n, -1));
         return dfs(triangle, temp, 0, 0);        
     }
 private:
     int n;
     int dfs(vector<vector<int>>& triangle, vector<vector<int>>& temp, int i, int j){
         if(i == n){
             return 0;
         }
         if(temp[i][j] != -1) {
             return temp[i][j];
         }
         return temp[i][j] = min(dfs(triangle, temp, i + 1, j), dfs(triangle, temp, i + 1, j + 1)) + triangle[i][j];
     }
 };



 /**********************************************************************************************************
 ��������̬�滮

 ˵����
    dp[i][j]�������[i][j]����ײ����С����

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(n)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/

 class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
         vector<vector<int>> dp(n, vector<int>(n));
         dp[n - 1] = triangle[n - 1];
         for (int i = n - 2; i >= 0; i--) {
             for (int j = 0; j <= i; j++) {
                 dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
             }
         }
         return dp[0][0];
     }
 };