#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     string replaceSpace(string s) {
     string res;
     for(char ch : s){
         if(ch == ' ') res.append("%20");
         else res.push_back(ch);
     }
     return res;
     }
 };

 /**********************************************************************************************************
方法：原地算法

说明：
    1. 将每个空格变为"%20"，即每次替换，s的长度都要+2
    2. 统计s中空格数，记为count，那么改变s的长度，s.resize(length + 2 * count)
    3. 从后向前，用两个指针，一个指针指向length - 1，一个指针指向s.size() - 1，原地替换即可

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     string replaceSpace(string s) {
         int length = s.size();
         int count = 0;
         for (int i = 0; i < length; i++) {
             if (s[i] == ' ') count++;
         }
         s.resize(length + 2 * count);
         for (int i = length - 1, j = s.size() - 1; i >= 0; i--, j--) {
             if (s[i] == ' ') {
                 s[j] = '0';
                 s[j - 1] = '2';
                 s[j - 2] = '%';
                 j -= 2;
             }
             else {
                 s[j] = s[i];
             }
         }
         return s;
     }
 };
