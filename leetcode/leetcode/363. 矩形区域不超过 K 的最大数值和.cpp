#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<set>
using namespace std;


/*
    1. 状态压缩，2维变1维，压缩后的题就变成了：寻找一个数组的连续子序列，其最大和 <= k
    2. 前缀和：将一个数组的连续子序列变成了两个前缀和的差： c[l + 1] + c[l + 2] + ... + c[r] = s[r] - s[l]，其中s[k] = c[0] + c[1] + ... + c[k]
    3. 状态转换：sr - sl <= k  <==> sr - k <= sl，当sr - sl尽可能逼近k时，那么sl就要尽可能小，而sl能够通过遍历sr时利用升序容器Set存储起来，
       并且用二分查找，可以找到第一个>= sr - k的sl
    4. 注意点：sl可以为0，因此需要将0放入排序集合Set之中
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        //上边界
        for (int i = 0; i < m; i++) { //注1：这里边界是m而不是m - 1
            vector<int> c(n, 0);
            //下边界
            for (int j = i; j < m; j++) {
                //状态压缩
                for (int k = 0; k < n; k++) {
                    c[k] += matrix[j][k];
                }
                int sr = 0;
                set<int> Set({ 0 });//注2：0的意思是，sl什么都不选，即sr = c[0] + c[1] + c[2] + ... + c[k]
                for (auto num : c) {
                    sr += num;
                    auto iter = Set.lower_bound(sr - k);
                    if (iter != Set.end()) { //找到一个符合要求的
                        maxSize = max(maxSize, sr - *iter);
                    }
                    Set.insert(sr);
                }
            }
        }
        return maxSize;
    }
private:
    int maxSize = INT_MIN;
};