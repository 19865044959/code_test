#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
��������������Դ��

˵��������������������ģ�塢207��ϸϸ�Ƚ�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n+m)  O(n+m)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> a(numCourses);
        vector<int> ans;
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) { //ע���������һ��д����numCourses�����ǲ��Եģ���Ϊprerequisites.size()�Ǳ�������numCourses�ǽڵ����������
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
        visited[i] = -1; //���ڱ���
        for (auto j : a[i]) {
            if (visited[j] == -1) return false;
            else if (visited[j] == 0 && dfs(a, ans, visited, j) == false) return false;
            else if (visited[j] == 1); //ʲô������
        }
        visited[i] = 1;
        ans.push_back(i);
        return true;
    }
};