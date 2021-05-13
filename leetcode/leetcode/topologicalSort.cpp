#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************************************************
方法：拓扑排序

说明：
   1.  AOV网定义：用顶点(vertex)表示活动，用弧表示活动之间的优先关系，这样构成的网叫做AOV(activity on vertex network)网
        拓扑排序定义：设a(i, E)是一个具有n个顶点的有向图，顶点序列为v1、v2、v3...vn，满足若从顶点vi到顶点vj有一条路径，
        则顶点序列中顶点vi必在顶点vj之前，则我们称这样的一个顶点序列为拓扑序列，构造该序列的过程叫做拓扑排序
    2. 通过拓扑排序的定义，我们可以通过dfs来找到有向图的“终点”，即出度为0的点，按照逆序储存dfs经过的点，即是拓扑序列了
        因此，利用dfs可以很方便构建拓扑序列
    3. 将有向图的所有有向边均储存到一个vector<vector<int>>类型变量之中
    4. 用vector<int>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      visited来记录某个顶点是否被访问过
    5. 用ans输出

时间复杂度与空间复杂度：O(m)  O(n) 其中m为有向边数目， n为顶点数

涉及到的知识点：深度优先搜索dfs

***********************************************************************************************************/

bool dfs(vector<vector<int>>& a, vector<int>& visited, vector<int>& ans, int i)
{
    /*
       visited[i] =  0 --> 该顶点没有被访问
       visited[i] = -1 --> 该顶点正在dfs遍历中
       visited[i] =  1 --> 该顶点已经访问完成
   */
    visited[i] = -1;
    for (int u : a[i])
    {
        if (visited[u] == -1) return false; //产生回环
        else if (visited[u] == 0 && dfs(a, visited, ans, u) == false)  return false;//如果儿子节点出现回环，那么父亲节点也应该出现回环
        else if (visited[u] == 1); //啥也不干，这句话可以删除，但是为了思路清晰，就没删了
    }
    visited[i] = 1;
    ans.push_back(i);
    return true;
}

bool topological_sort(vector<vector<int>>& a)
{
    int n = a.size();
    vector<int> visited(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0 && dfs(a, visited, ans, i) == false) {
            cout << "Loop exists! ";
            return false;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return true;
}

int main()
{
    //若只给你边，比如只给了[0,1] [0,2] [1,2] 等等，该怎么办？先转换为邻接表，再进行下面的代码
    /*
    vector<vector<int>> L{ {0, 1}, {0, 2}, {1, 2}, {0, 3} };
    int vertexNum = 4;
    vector<vector<int>> a(vertexNum);
    for (int i = 0; i < L.size(); i++) {
    a[L[i][0]].push_back(L[i][1]);
    }
    */
    vector<vector<int>> a{ { 11,5,4 }, { 8,4,2 }, { 9,6,5 }, { 13,2 }, { 7 }, { 12,8 }, { 5 }, {}, { 7 }, { 11,10 }, { 13 }, {}, { 9 }, {} };
    //vector<vector<int>> a{ { 11,5,4 }, { 8,4,2 }, { 9,6,5 }, { 13,2 }, { 7 }, { 12,8 }, { 5 }, {}, { 7 }, { 11,10 }, { 13 }, {0}, { 9 }, {} }; //这里0->11与11->0会产生回环
    auto val = topological_sort(a);

    return val;
}
