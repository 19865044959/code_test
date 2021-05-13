#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������̰���㷨

˵����
    ��vector<int>index == 0�Ӹߵ������ţ����ź��ٽ��д����ߵ������źô���
    1. �߿���Ǩ�͵ͣ����ǵ��޷�Ǩ�͸ߣ�������[2,0] [1,1] [2,1]������ոߵ�����[2,0] [2,1] [1,0]����ô��ʹ��[1,0]�ŵ��ߵ�ǰ�棬Ҳ����ı�[2,0] [2,1]���������ź����vector����[1,0] [2,0] [1,0]
    2. �ڶ���Ԫ�ش������>=��Ҳ���Բ����Ƴ�Ҫ�ߵ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) ��������  O(n^2)

�漰����֪ʶ�㣺
    �õ���lambda���ʽ

***********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return (v1[0] > v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]); //����ȷ��returnֵ��ǰ�治��Ҫдreturn type
            });
        vector<vector<int>> ans;
        for (auto person : people) {
            ans.insert(ans.begin() + person[1], person);//������д��� v1[1] > v2[1]������ͻᱨ��ԭ����ansָ�볬��ans��Χ
        }
        return ans;
    }
};
