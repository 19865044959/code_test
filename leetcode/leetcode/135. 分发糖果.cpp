#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：贪心

说明：见题解，说的非常棒

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int count = 0;
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 0; i < n - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                left[i + 1] = left[i] + 1;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (ratings[i - 1] > ratings[i]) {
                right[i - 1] = right[i] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            count += max(left[i], right[i]);
        }
        return count;
    }
};