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
	超时

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     int maxArea(vector<int>& height) {
         int maxVol = 0;
         int n = height.size();
         for(int i = 0; i < n - 1; i++){
             for(int j = i + 1; j < n; j++){
                 int minHeight = min(height[i], height[j]);
                 maxVol = max(maxVol, minHeight * (j - i));
             }
         }
         return maxVol;
     }
 };

 /**********************************************************************************************************
方法：双指针法

说明：
    设i，j是两个指针（索引），那么有volumn = (j - i) * min(height[i], height[j])，可以看到，volumn不仅仅是
    取决于高度，还取决于宽度，若我们将指针设置在最左边处与最右边处，那么宽度有最大值，这时候通过移动
    最左侧指针++或者最右侧指针--可能实现宽度的减少，高度的增加，从而实现整体volumn的增加
    那么怎样去移动指针呢？
    1. 当移动左右指针中对应高度最小的那一边时，高度有可能会增加，宽度一定减少1，有可能出现整体volumn增加
    2. 当移动左右指针中对应高度最大的那一边时，高度一定不会增加（有可能不变），宽度一定减少1，这时候得到的volumn不可能比之前的大
    因此得到策略：
    1. 左右指针
    2. 比较两个高度，那个小就移动哪边
    3. 直到i < j不成立为止

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     int maxArea(vector<int>& height) {
         int n = height.size();
         int left = 0;
         int right = n - 1;
         int maxVol = 0;
         while (left < right) {
             maxVol = height[left] > height[right] ? max(maxVol, (right - left) * height[right--]) : max(maxVol, (right - left) * height[left++]);
         }
         return maxVol;
     }
 };