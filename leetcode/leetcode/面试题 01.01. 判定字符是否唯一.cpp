#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：哈希表

说明：

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     bool isUnique(string astr) {
         vector<int> hash(26, 0);
         int n = astr.size();
         for(int i = 0; i < n; i++){
             if(++hash[astr[i] - 'a'] > 1) return false;
         }
         return true;
     }
 };


 /**********************************************************************************************************
方法：位运算

说明：
    用一个整型变量来模拟26个int类型的数组，每次将1向右位移astr[i] - 'a'，&运算int类型变量mark，
    当mark == 0时说明之前没有出现过这个字母，return false
    然后更新mark，让它对应的astr[i] - 'a'置1，说明该字母已经出现过
    再次出现就会return false

时间复杂度与空间复杂度：O(n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     bool isUnique(string astr) {
         int mark = 0;
         int n = astr.size();
         for (int i = 0; i < n; i++) {
             if ((mark & 1 << (astr[i] - 'a')) != 0) return false; //注意需要用括号括起来(mark & 1 << (astr[i] - 'a')) != 0，因为!=优先级高于&
             else mark = mark | 1 << (astr[i] - 'a');
         }
         return true;
     }
 };
