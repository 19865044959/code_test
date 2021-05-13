#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：按行计算

说明：
	超时(314/315)

时间复杂度与空间复杂度：O(n * height) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxHeight = INT_MIN;

        //找到最大高度
        for (int i = 0; i < n; i++) {
            maxHeight = max(maxHeight, height[i]);
        }
        int ans = 0;
        for (int i = 1; i <= maxHeight; i++) {
            int j = 0;
            int temp = 0;
            //找到第一个高度 >= i的点，开始循环
            while (j < n && height[j] < i) j++;
            //主循环，当高度 >= i 时， ans += temp，当高度 < i时， temp++储存雨水
            while (j < n) {
                if (height[j] >= i) {
                    ans += temp;
                    temp = 0;
                }
                else {
                    temp++;
                }
                j++;
            }
        }
        return ans;
    }
};

/**********************************************************************************************************
方法2：按列计算

说明：
    险过

时间复杂度与空间复杂度：O(n^2) O(1)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMaxHeight = INT_MIN;
        int rightMaxHeight;
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {//除去最左边与最右边的列
            leftMaxHeight = max(leftMaxHeight, height[i - 1]);
            rightMaxHeight = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                rightMaxHeight = max(rightMaxHeight, height[j]);
            }
            int minVal = min(leftMaxHeight, rightMaxHeight);
            sum += height[i] > minVal ? 0 : (minVal - height[i]);
        }
        return sum;
    }
};

/**********************************************************************************************************
方法3：按列计算 + 空间换时间

说明：
    将rightMaxHeight储存到一个数组之中，而leftMaxHeight就直接更新即可

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMaxHeight = INT_MIN;
        vector<int> rightMaxHeight(n, 0);
        //用空间换时间，将rightMaxHeight值存入数组，注意是从高到低，并且rightMaxHeight[i]不包括height[i]元素
        for (int i = n - 2; i >= 1; i--) {
            rightMaxHeight[i] = max(height[i + 1], rightMaxHeight[i + 1]);
        }
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            leftMaxHeight = max(leftMaxHeight, height[i - 1]); //左边直接更新
            int minVal = min(leftMaxHeight, rightMaxHeight[i]); //右边直接用储存好值的数组
            sum += height[i] >= minVal ? 0 : (minVal - height[i]);
        }
        return sum;
    }
};