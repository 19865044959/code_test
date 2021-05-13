#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
����ָ�� + ����
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

 //��̬�滮
/*
    ��dp[j]Ϊ��j��β�����ͬ�ַ��ĳ��ȣ�
    �������뵽�ĵ㣺��s[i] = s[j]����i�����j����j����ͬ�ַ����±�
    ��dp[j - 1] < j - 1 - i + 1 = j - iʱ��˵��i����֮ǰ��Ĳ�ͬ�ַ����ַ����ڣ���ôdp[j] = dp[j - 1] + 1;
    ����dp[j] = j - i;
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