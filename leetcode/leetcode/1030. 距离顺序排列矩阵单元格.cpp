#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)   O(n)  ����n=R*C

�漰����֪ʶ�㣺
    1. ����vector<int>����ʾ�����꣬ע��һ�������vector�������ǵ㣬��vector��������Ӧ��ֵ���������꣬(x,y,z...)�������л��ڼ����������پ���
    2. ����vector<int>����ʾһ������ע�������vector������index����row���ڲ���vector����index����column����Ӧ��ֵ�Ǿ����(row,column)������Ӧ��ֵ
    3. ����vector<vector<int>>�����ķ���
    4. lambda���ʽ��sort����������
    5. ˳������ɾ��Ԫ�صķ�����c.erase(iter)��c.pop_back()�� c.pop_front()
***********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R * C, vector<int>(3, 0));
        int cnt = 0;
        for (int i = 0; i < R; i++) { //�����ķ���
            for (int j = 0; j < C; j++) {
                ans[cnt][0] = i;
                ans[cnt][1] = j;
                ans[cnt][2] = abs(r0 - i) + abs(c0 - j);
                cnt++;
            }
        }
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});
        for (int n = 0; n < ans.size(); n++) {
            ans[n].pop_back();
        }
        return ans;
    }
};