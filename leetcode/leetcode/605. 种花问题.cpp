#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：分析法/贪心： 判断种过花的地方flowerbed[i] == 1从而计算答案

说明：

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         int cnt = 0;
         bool flag = false;
         int flag1 = -1;
         int flag2 = -1;
         for(int i = 0; i < flowerbed.size(); i++){
             if(flowerbed[i]){
                 if(!flag){ //计算0 0 1 0 1 0 0 0的[0,0,1]部分插值
                     cnt += (i - 0) / 2;
                     flag = true;
                 }
                 flag1 = flag2;
                 flag2 = i;
                 if(flag1 >= 0 && flag2 >= 0){
                     cnt += (flag2 - flag1) / 2 - 1;
                     if(cnt >= n) return true;
                 }
             }
         }
         if(flag2 >= 0){
             cnt += (flowerbed.size() - flag2 - 1) / 2; //计算0 0 1 0 1 0 0 0的[1, 0, 0, 0]部分插值
         }
         else{//说明全是0
             cnt += (flowerbed.size() + 1) / 2;
         }
         return cnt >= n;
     }
 };


 /**********************************************************************************************************
方法2：分析法/贪心： 判断没种过花的地方flowerbed[i] == 0从而计算答案

说明： 

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         for (int i = 0; i < flowerbed.size(); i += 2) {
             if (!flowerbed[i]) {
                 if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                     n--; //说明可以插花
                 }
                 else {
                     i++; //跳到这个有花的地方，下次i += 2的话就可以只管后面是否挨着花，不管前面是否挨着花了(因为前面一定不会挨着)
                 }
             }
         }
         return n <= 0;
     }
 };