#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
快慢指针 + 集合
O(n) O(1)
*/
 class Solution {
 public:
     int lengthOfLongestSubstring(string s) {
         int n = s.size();
         if(n == 0) return 0;
         int slow = 0;
         int fast = 0;
         int maxSize = 0;
         unordered_set<char> numSet;
         while(fast != n){
             while(fast != n && numSet.find(s[fast]) == numSet.end()){
                 numSet.insert(s[fast]);
                 fast++;
             }
             maxSize = max(maxSize, fast - slow);
             while(slow < fast && numSet.find(s[fast]) != numSet.end()){
                 numSet.erase(s[slow]);
                 slow++;
             }
         }
         return maxSize;
     }
 };

 //动态规划
/*
    设dp[j]为以j结尾的最长不同字符的长度，
    不容易想到的点：设s[i] = s[j]，即i是最靠近j的与j的相同字符的下标
    当dp[j - 1] < j - 1 - i + 1 = j - i时，说明i不在之前最长的不同字符的字符串内，那么dp[j] = dp[j - 1] + 1;
    否则，dp[j] = j - i;
    O(n) O(1)
*/
 class Solution {
 public:
     int lengthOfLongestSubstring(string s) {
         int n = s.size();
         if (n == 0) return 0;
         int maxSize = 0;
         int dpi = 0;
         unordered_map<char, int> hash;
         for (int j = 0; j < n; j++) {
             int i = hash.find(s[j]) == hash.end() ? -1 : hash[s[j]];
             dpi = j - i > dpi ? dpi + 1 : j - i;
             maxSize = max(dpi, maxSize);
             hash[s[j]] = j;
         }
         return maxSize;
     }
 };