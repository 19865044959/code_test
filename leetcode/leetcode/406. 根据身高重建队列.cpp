#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：贪心算法

说明：
    以vector<int>index == 0从高到低重排，重排后再进行处理，高到低重排好处：
    1. 高可以迁就低，但是低无法迁就高，举例：[2,0] [1,1] [2,1]如果按照高低排序，[2,0] [2,1] [1,0]，那么即使将[1,0]放到高的前面，也不会改变[2,0] [2,1]这两个已排好序的vector，即[1,0] [2,0] [1,0]
    2. 第二个元素储存的是>=，也可以侧面推出要高到低

时间复杂度与空间复杂度：O(n^2) 用于排序  O(n^2)

涉及到的知识点：
    用到了lambda表达式

***********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return (v1[0] > v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]); //有明确的return值，前面不需要写return type
            });
        vector<vector<int>> ans;
        for (auto person : people) {
            ans.insert(ans.begin() + person[1], person);//当上面写错成 v1[1] > v2[1]，这里就会报错，原因是ans指针超出ans范围
        }
        return ans;
    }
};
