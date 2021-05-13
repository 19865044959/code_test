#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1���¶���������

˵����
    ��ʱ
ʱ�临�Ӷ���ռ临�Ӷȣ�	O(C(m + n - 2)(n - 1))     O(C(m + n - 2)(n - 1))

�漰����֪ʶ�㣺
	����������

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
����2���������

˵����
    ��ʽ��C(m + n - 2)(m - 1)

ʱ�临�Ӷ���ռ临�Ӷȣ�O(1)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     long long uniquePaths(int m, int n) {
         long long temp = 1;
         int j = 1;
         for (int i = n; i <= m + n - 2; i++) {
             temp *= i;

             //�Ż�1��ÿ�������һ�������û�����������Ծ����ӣ�����Ϊʲô���Ҳ���֤��
             // if(j <= m - 1 && temp % j == 0){
             //     temp /= j;
             //     j++;
             // }

             temp /= j;
             j++;
         }

         // �Ż�2�������ѭ����[n, m + n - 2]���� m - 1����������jҲѭ����m - 1�ε��� m��while�Ƕ����
         // while(j <= m - 1){
         //     temp /= j;
         //     j++;
         // }

         return temp;
     }
 };

 /**********************************************************************************************************
��������̬�滮

˵��������ͬ·��2��DP����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m * n)  O(m * n)

�漰����֪ʶ�㣺

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
