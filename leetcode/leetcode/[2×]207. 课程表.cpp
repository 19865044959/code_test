#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：拓扑排序

说明：将此题与拓扑排序模板、210题细细比较

时间复杂度与空间复杂度：O(n + m)   O(n + m) 其中n是边数， m是顶点个数

涉及到的知识点：拓扑排序源码

***********************************************************************************************************/

//visiting = 1 正在访问  = -1 访问完毕  = 0 未访问过
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.size() == 0) return true;
        vector<vector<int>> constraints(numCourses);
        vector<int>visiting(numCourses, 0);
        //构建约束关系
        for (int i = 0; i < prerequisites.size(); i++) {
            constraints[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //主循环
        for (int i = 0; i < numCourses; i++) {
            res *= dfs(visiting, constraints, i);
            if (!res)break; //提前剪枝
        }
        return res;
    }

private:
    bool res = true;
    bool dfs(vector<int>& visiting, vector<vector<int>>& constraints, int i) {
        visiting[i] = 1;
        for (auto course : constraints[i]) {
            if (visiting[course] == 1) return false; //产生了回环
            else if (visiting[course] == -1) continue; //提前剪枝，不用继续判断了
            else { //course说明未访问过
                res *= dfs(visiting, constraints, course);
            }
            if (!res) break; //提前剪枝
        }
        visiting[i] = -1; //访问完毕
        return res;
    }
};
