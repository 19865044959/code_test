#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：递归法

说明：
	此题很容易产生思路混乱，要分清本次喝光了numBottles剩下的空瓶数、上次未能变成numBottles的空瓶数

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        iteration(numBottles, 0, ans, numExchange);
        return ans;
    }
    void iteration(int numBottles, int emptyBottles, int& ans, int numExchange) {
        if (numBottles == 0) return;
        ans += numBottles;
        iteration((numBottles + emptyBottles) / numExchange, (numBottles + emptyBottles) % numExchange, ans, numExchange);
    }
};

/**********************************************************************************************************
方法：迭代法
说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            ans += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return ans;
    }
};