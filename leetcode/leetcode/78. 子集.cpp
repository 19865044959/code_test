#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：回溯算法

说明：
	1. 建议复习labuladong算法小抄P50内容
    2. 未搞懂它的终止条件是什么

时间复杂度与空间复杂度：O(2^n) O(2^n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
private:
    vector<vector<int>>res;
    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        //进行操作
        res.push_back(track);
        //类似N叉树遍历
        for (int i = start; i < nums.size(); i++) {
            //做选择并加入路径
            track.push_back(nums[i]);
            //回溯
            backtrack(nums, i + 1, track);
            //撤销选择
            track.pop_back();
        }
    }
};


/**********************************************************************************************************
方法：迭代法

说明：
    思想：假如我有一个数组{1, 2, 3}，那么答案会是这样的：
    {[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]}
    即：开始存入一个空数组，接下来每次把nums里面的元素拿出来一个nums[i]，遍历res里面的元素，将nums[i] push_back到res里面的元素，再放回res里面

时间复杂度与空间复杂度：O(2^n) O(2^n)

涉及到的知识点：

***********************************************************************************************************/

 class Solution {
 public:
     vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();
         vector<int> subset;
         vector<vector<int>> res;
         res.push_back(subset);
         for(int i = 0; i < n; i++){
             int m = res.size(); //这里注意一定是要int m = res.size()将当前的res长度记录下来，否则会死循环（因为res长度在增长）
             for(int j = 0; j < m; j++){//这里我不太清楚为什么auto k : res不可以，应该是长度增加了，迭代器指针发生了变化
                 subset = res[j];
                 subset.push_back(nums[i]);
                 res.push_back(subset);
             }
         }
         return res;
     }
 };