#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

/**********************************************************************************************************
����������dfs��Ⱦɫ��

˵����
        0. Ⱦɫ������ÿһ���ߵ��������㶼Ⱦ�ɲ�ͬ����ɫ���Բ�ͬ�����ִ���1��-1������ѭ�����нڵ��
            �������еı߶���Ⱦ�ɲ�ͬ��ɫ����ô˵�����Ƕ���ͼ�����������һ������������ͬ��ɫ�Ķ��㣬˵��
            ���Ƕ���ͼ
        1. �ڽӱ�ٱ߱��ڽӱ��size�͵��ڶ������
        2. ʹ����visited��¼�����Ƿ񱻱���������������������
        3. ���ƣ���������Դ��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(N + M) O(N) ����N������ͼ��������M������ͼ�ı���

�漰����֪ʶ�㣺
    1. ����ͼ��������ͼG=(V,E) �Ķ��㼯V���Էָ�Ϊ���������ཻ���Ӽ���
    ��ͼ��ÿ���ߵ���������ֱ����ڲ�ͬ���Ӽ������ͼ GG Ϊһ������ͼ��

***********************************************************************************************************/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && dfs(graph, visited, 1, i) == false) return false; //ֻҪ��һ���ߵ���ɫ��ͬ����ô����false
        }
        return true;//�������бߵ�����������ɫ����ͬ������true
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int color, int i) {
        if (visited[i] != 0) return visited[i] == color; //��Ⱦɫǰ���ж��Ƿ��Ѿ�Ⱦ��ɫ�ˣ���Ⱦ�����ж���Ⱦ��ɫ����Ⱦ��ɫ�Ƿ���ͬ
        visited[i] = color;
        for (auto k : graph[i]) {
            if (dfs(graph, visited, -color, k) == false) return false; //ֻҪ��һ���ߵ���ɫ��ͬ����ô����false
        }
        return true;//�������бߵ�����������ɫ����ͬ������true
    }
};


/**********************************************************************************************************
����������bfs��Ⱦɫ��

˵����
    

ʱ�临�Ӷ���ռ临�Ӷȣ�O(N + M) O(N) ����N������ͼ��������M������ͼ�ı���

�漰����֪ʶ�㣺
    1. ����ͼ��������ͼG=(V,E) �Ķ��㼯V���Էָ�Ϊ���������ཻ���Ӽ���
    ��ͼ��ÿ���ߵ���������ֱ����ڲ�ͬ���Ӽ������ͼ GG Ϊһ������ͼ��

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