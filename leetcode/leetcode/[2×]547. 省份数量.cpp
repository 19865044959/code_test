#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
方法：dfs源码（邻接矩阵的dfs图的遍历）

说明：

时间复杂度与空间复杂度：
	O(n^2)
		1. 不同于dfs的源码，这里是用邻接矩阵，dfs源码还忽略了没有连接的点，因此复杂度有所不同
		2. 每个节点进行遍历，每个节点对其他n个节点再遍历，所以是n^2
	O(n)
		1. visited数组
		2. 递归最多为n次，此时图退化为链，且所有点均相连

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        n = M.size();
        if (n == 0) return 0;

        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
private:
    int n;
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) { //这里没有引用直接错！！！注意啊！
        visited[i] = 1;
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                dfs(M, visited, j);
            }
        }
    }
};
