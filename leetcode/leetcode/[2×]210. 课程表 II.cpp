#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：拓扑排序源码

说明：将此题与拓扑排序模板、207题细细比较

时间复杂度与空间复杂度：O(n+m)  O(n+m)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> a(numCourses);
        vector<int> ans;
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) { //注意我这里第一遍写成了numCourses，这是不对的，因为prerequisites.size()是边数，而numCourses是节点数，不相等
            a[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && dfs(a, ans, visited, i) == false) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool dfs(vector<vector<int>>& a, vector<int>& ans, vector<int>& visited, int i) {
        visited[i] = -1; //正在遍历
        for (auto j : a[i]) {
            if (visited[j] == -1) return false;
            else if (visited[j] == 0 && dfs(a, ans, visited, j) == false) return false;
            else if (visited[j] == 1); //什么都不做
        }
        visited[i] = 1;
        ans.push_back(i);
        return true;
    }
};