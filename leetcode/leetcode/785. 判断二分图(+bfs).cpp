#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

/**********************************************************************************************************
方法：利用dfs的染色法

说明：
        0. 染色法：将每一个边的两个顶点都染成不同的颜色（以不同的数字代表，1与-1），若循环所有节点后，
            发现所有的边都被染成不同颜色，那么说明就是二分图，如果出现了一条边有两个相同颜色的顶点，说明
            不是二分图
        1. 邻接表≠边表，邻接表的size就等于顶点个数
        2. 使用了visited记录顶点是否被遍历过，类似于拓扑排序
        3. 类似：拓扑排序源码

时间复杂度与空间复杂度：O(N + M) O(N) 其中N是无向图顶点数，M是无向图的边数

涉及到的知识点：
    1. 二分图：若无向图G=(V,E) 的顶点集V可以分割为两个互不相交的子集，
    且图中每条边的两个顶点分别属于不同的子集，则称图 GG 为一个二分图。

***********************************************************************************************************/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && dfs(graph, visited, 1, i) == false) return false; //只要有一条边的颜色相同，那么就是false
        }
        return true;//必须所有边的两个顶点颜色都不同，才是true
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int color, int i) {
        if (visited[i] != 0) return visited[i] == color; //在染色前先判断是否已经染过色了，若染过，判断欲染颜色与已染颜色是否相同
        visited[i] = color;
        for (auto k : graph[i]) {
            if (dfs(graph, visited, -color, k) == false) return false; //只要有一条边的颜色相同，那么就是false
        }
        return true;//必须所有边的两个顶点颜色都不同，才是true
    }
};


/**********************************************************************************************************
方法：利用bfs的染色法

说明：
    

时间复杂度与空间复杂度：O(N + M) O(N) 其中N是无向图顶点数，M是无向图的边数

涉及到的知识点：
    1. 二分图：若无向图G=(V,E) 的顶点集V可以分割为两个互不相交的子集，
    且图中每条边的两个顶点分别属于不同的子集，则称图 GG 为一个二分图。

***********************************************************************************************************/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (visited[i] != 0) continue;
            visited[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int temp = q.front();
                q.pop();
                for (auto k : graph[temp]) {
                    if (visited[k] == visited[temp]) return false;
                    if (visited[k] == 0) {
                        visited[k] = -visited[temp];
                        q.push(k);
                    }
                }
            }
        }
        return true;
    }
};