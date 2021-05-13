#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：O(nlogn)   O(n)  其中n=R*C

涉及到的知识点：
    1. 利用vector<int>来表示点坐标，注意一个最外的vector的索引是点，内vector的索引对应的值代表点的坐标，(x,y,z...)，本题中还在加入了曼哈顿距离
    2. 利用vector<int>来表示一个矩阵，注意最外的vector的索引index是行row，内部的vector索引index是列column，对应的值是矩阵的(row,column)点所对应的值
    3. 利用vector<vector<int>>构造点的方法
    4. lambda表达式，sort第三个参数
    5. 顺序容器删除元素的方法：c.erase(iter)、c.pop_back()、 c.pop_front()
***********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R * C, vector<int>(3, 0));
        int cnt = 0;
        for (int i = 0; i < R; i++) { //构造点的方法
            for (int j = 0; j < C; j++) {
                ans[cnt][0] = i;
                ans[cnt][1] = j;
                ans[cnt][2] = abs(r0 - i) + abs(c0 - j);
                cnt++;
            }
        }
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});
        for (int n = 0; n < ans.size(); n++) {
            ans[n].pop_back();
        }
        return ans;
    }
};