#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

// dfs，不存在备忘录
// O(n^2)  O(n)
 class Solution {
 public:
     int translateNum(int num) {
         s = to_string(num);
         n = s.size();
         int res = dfs(0);
         return res;
     }
     int dfs(int i){
         if(i >= n - 1) return 1;
         int num = 10 * (s[i] - '0') + s[i + 1] - '0';
         if(num >= 10 && num < 26){
             ans = dfs(i + 1) + dfs(i + 2);
         }
         else ans = dfs(i + 1);
         return ans; 
     }
 private:
     int n;
     string s;
     int ans;
 };


 //dfs，加备忘录，防止重复计算
 //O(n) O(n)
 class Solution {
 public:
     int translateNum(int num) {
         s = to_string(num);
         n = s.size();
         vector<int>memo(n, -1);
         int res = dfs(0, memo);
         return res;
     }
 private:
     int n;
     string s;
     int dfs(int i, vector<int>& memo){
         if(i >= n - 1) return 1;
         if(memo[i] != -1) return memo[i];
         int num = 10 * (s[i] - '0') + (s[i + 1] - '0');
         if(num >= 10 && num <= 25){
             memo[i] = dfs(i + 1, memo) + dfs(i + 2, memo);
         }
         else{
             memo[i] = dfs(i + 1, memo);
         }
         return memo[i];
     }
 };

 //dp
 //O(n) O(1)
 class Solution {
 public:
     int translateNum(int num) {
         string s = to_string(num);
         int n = s.size();
         int a = 1; //dp[0]
         int b = 1; //dp[1]
         int c = 1;
         for (int i = 2; i <= n; i++) {
             int num = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
             if (num >= 10 && num <= 25) c = a + b;
             else c = b;
             a = b;
             b = c;
         }
         return c;
     }
 };