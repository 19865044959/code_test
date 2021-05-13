#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：暴力法（超时）

说明：
	1. 将含有n个字符的字符串的总共分割方法n-1暴力列举出来，每次都用两个哈希表统计出不同的字符个数，
	相同则ans++	
    2. 1 <= s.length <= 10^5，时间复杂度必须降低至O(n)或者O(nlogn)，否则O(n)会达到10^10，超时

时间复杂度与空间复杂度：
	O(n^2):由于每次哈希表统计都要花费O(n)，需要n-1次
	O(n):哈希表

涉及到的知识点：

***********************************************************************************************************/


/**********************************************************************************************************
方法2：两边统计

说明：
    暴力法之所以会出现O(n^2)复杂度，是因为每次又完全重新将哈希表统计O(n)，而实际上，只需要将哈希表以及统计
    个数进行+1或者-1即可O(1)，比如：aacaba  :  a  acaba  -->   aa caba只需要向左侧哈希表a[0]++，右侧哈希表b[0]--
    并计算是否出现a[0]从0变1的情况、是否出现b[0]从1变0的情况（这两种情况会使得num1++，num2--）就行了
    完全没必要重新统计哈希表

时间复杂度与空间复杂度：
    O(n):构造一次哈希表
    O(n):哈希表

涉及到的知识点：

***********************************************************************************************************/
//我自己写的，从两边开始想左边、右边进行两次两个哈希表的统计，觉得这样能够快点，但是代码复杂
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        if (n == 1) return 0;
        vector<int> a(26, 0);
        vector<int> b(a);
        int ans = 0;
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < int(n / 2); i++) {
            num1 += (a[s[i] - 'a'] == 0);
            a[s[i] - 'a']++;
        }
        for (int i = int(n / 2); i < n; i++) {
            num2 += (b[s[i] - 'a'] == 0);
            b[s[i] - 'a']++;
        }
        if (num1 == num2) ans++;
        vector<int>tempa(a);
        vector<int>tempb(b);
        int tempnum1 = num1;
        int tempnum2 = num2;
        for (int i = int(n / 2) - 1; i >= 0; i--) {
            if (!(--a[s[i] - 'a'])) num1--;
            if (!b[s[i] - 'a']) num2++;
            b[s[i] - 'a']++;
            if (num1 == num2) ans++;
        }

        a = tempa;
        b = tempb;
        num1 = tempnum1;
        num2 = tempnum2;
        for (int i = int(n / 2); i < n; i++) {
            if (!(--b[s[i] - 'a'])) num2--;
            if (!a[s[i] - 'a']) num1++;
            a[s[i] - 'a']++;
            if (num1 == num2) ans++;
        }
        return ans;
    }
};

//较为简便的写法
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> leftHash(26, 0);
        vector<int> rightHash(26, 0);
        int leftNum = 0;
        int rightNum = 0;
        int ans = 0;

        //非常巧妙，用一次循环就搞定了哈希表的构建与哈希表中非零元素个数的统计
        for (int i = 0; i < n; i++) {
            rightNum += (rightHash[s[i] - 'a'] == 0); //如果某个字母在哈希表中第一次记录，那么rightNum++
            rightHash[s[i] - 'a']++;
        }

        //相当于从右侧的字符串/哈希表取出一个字符送给左侧字符串/哈希表，并查看左右侧不相同的字符数是否相同
        for (int i = 0; i < n; i++) {
            leftNum += (leftHash[s[i] - 'a'] == 0); //加的时候先判断是否为第一次记录，如果是就++
            leftHash[s[i] - 'a']++;
            rightHash[s[i] - 'a']--;
            rightNum -= (rightHash[s[i] - 'a'] == 0); //减的时候首先要先减，再判断减完后该元素hash表是否为0，为0说明元素消失，--
            ans += (leftNum == rightNum); //又是巧妙的一石二鸟
        }
        return ans;
    }
};