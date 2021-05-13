#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************************************************
��������������

˵����
   1.  AOV�����壺�ö���(vertex)��ʾ����û���ʾ�֮������ȹ�ϵ���������ɵ�������AOV(activity on vertex network)��
        ���������壺��a(i, E)��һ������n�����������ͼ����������Ϊv1��v2��v3...vn���������Ӷ���vi������vj��һ��·����
        �򶥵������ж���vi���ڶ���vj֮ǰ�������ǳ�������һ����������Ϊ�������У���������еĹ��̽�����������
    2. ͨ����������Ķ��壬���ǿ���ͨ��dfs���ҵ�����ͼ�ġ��յ㡱��������Ϊ0�ĵ㣬�������򴢴�dfs�����ĵ㣬��������������
        ��ˣ�����dfs���Ժܷ��㹹����������
    3. ������ͼ����������߾����浽һ��vector<vector<int>>���ͱ���֮��
    4. ��vector<int>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      visited����¼ĳ�������Ƿ񱻷��ʹ�
    5. ��ans���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m)  O(n) ����mΪ�������Ŀ�� nΪ������

�漰����֪ʶ�㣺�����������dfs

***********************************************************************************************************/

bool dfs(vector<vector<int>>& a, vector<int>& visited, vector<int>& ans, int i)
{
    /*
       visited[i] =  0 --> �ö���û�б�����
       visited[i] = -1 --> �ö�������dfs������
       visited[i] =  1 --> �ö����Ѿ��������
   */
    visited[i] = -1;
    for (int u : a[i])
    {
        if (visited[u] == -1) return false; //�����ػ�
        else if (visited[u] == 0 && dfs(a, visited, ans, u) == false)  return false;//������ӽڵ���ֻػ�����ô���׽ڵ�ҲӦ�ó��ֻػ�
        else if (visited[u] == 1); //ɶҲ���ɣ���仰����ɾ��������Ϊ��˼·��������ûɾ��
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
    //��ֻ����ߣ�����ֻ����[0,1] [0,2] [1,2] �ȵȣ�����ô�죿��ת��Ϊ�ڽӱ��ٽ�������Ĵ���
    /*
    vector<vector<int>> L{ {0, 1}, {0, 2}, {1, 2}, {0, 3} };
    int vertexNum = 4;
    vector<vector<int>> a(vertexNum);
    for (int i = 0; i < L.size(); i++) {
    a[L[i][0]].push_back(L[i][1]);
    }
    */
    vector<vector<int>> a{ { 11,5,4 }, { 8,4,2 }, { 9,6,5 }, { 13,2 }, { 7 }, { 12,8 }, { 5 }, {}, { 7 }, { 11,10 }, { 13 }, {}, { 9 }, {} };
    //vector<vector<int>> a{ { 11,5,4 }, { 8,4,2 }, { 9,6,5 }, { 13,2 }, { 7 }, { 12,8 }, { 5 }, {}, { 7 }, { 11,10 }, { 13 }, {0}, { 9 }, {} }; //����0->11��11->0������ػ�
    auto val = topological_sort(a);

    return val;
}
