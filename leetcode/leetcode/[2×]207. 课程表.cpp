#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
��������������

˵��������������������ģ�塢210��ϸϸ�Ƚ�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n + m)   O(n + m) ����n�Ǳ����� m�Ƕ������

�漰����֪ʶ�㣺��������Դ��

***********************************************************************************************************/

//visiting = 1 ���ڷ���  = -1 �������  = 0 δ���ʹ�
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.size() == 0) return true;
        vector<vector<int>> constraints(numCourses);
        vector<int>visiting(numCourses, 0);
        //����Լ����ϵ
        for (int i = 0; i < prerequisites.size(); i++) {
            constraints[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //��ѭ��
        for (int i = 0; i < numCourses; i++) {
            res *= dfs(visiting, constraints, i);
            if (!res)break; //��ǰ��֦
        }
        return res;
    }

private:
    bool res = true;
    bool dfs(vector<int>& visiting, vector<vector<int>>& constraints, int i) {
        visiting[i] = 1;
        for (auto course : constraints[i]) {
            if (visiting[course] == 1) return false; //�����˻ػ�
            else if (visiting[course] == -1) continue; //��ǰ��֦�����ü����ж���
            else { //course˵��δ���ʹ�
                res *= dfs(visiting, constraints, course);
            }
            if (!res) break; //��ǰ��֦
        }
        visiting[i] = -1; //�������
        return res;
    }
};
