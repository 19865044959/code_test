#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
������dfsԴ�루�ڽӾ����dfsͼ�ı�����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�
	O(n^2)
		1. ��ͬ��dfs��Դ�룬���������ڽӾ���dfsԴ�뻹������û�����ӵĵ㣬��˸��Ӷ�������ͬ
		2. ÿ���ڵ���б�����ÿ���ڵ������n���ڵ��ٱ�����������n^2
	O(n)
		1. visited����
		2. �ݹ����Ϊn�Σ���ʱͼ�˻�Ϊ���������е������

�漰����֪ʶ�㣺

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
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) { //����û������ֱ�Ӵ�����ע�Ⱑ��
        visited[i] = 1;
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                dfs(M, visited, j);
            }
        }
    }
};
