#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<set>
using namespace std;


/*
    1. ״̬ѹ����2ά��1ά��ѹ�������ͱ���ˣ�Ѱ��һ����������������У������� <= k
    2. ǰ׺�ͣ���һ����������������б��������ǰ׺�͵Ĳ c[l + 1] + c[l + 2] + ... + c[r] = s[r] - s[l]������s[k] = c[0] + c[1] + ... + c[k]
    3. ״̬ת����sr - sl <= k  <==> sr - k <= sl����sr - sl�����ܱƽ�kʱ����ôsl��Ҫ������С����sl�ܹ�ͨ������srʱ������������Set�洢������
       �����ö��ֲ��ң������ҵ���һ��>= sr - k��sl
    4. ע��㣺sl����Ϊ0�������Ҫ��0�������򼯺�Set֮��
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        //�ϱ߽�
        for (int i = 0; i < m; i++) { //ע1������߽���m������m - 1
            vector<int> c(n, 0);
            //�±߽�
            for (int j = i; j < m; j++) {
                //״̬ѹ��
                for (int k = 0; k < n; k++) {
                    c[k] += matrix[j][k];
                }
                int sr = 0;
                set<int> Set({ 0 });//ע2��0����˼�ǣ�slʲô����ѡ����sr = c[0] + c[1] + c[2] + ... + c[k]
                for (auto num : c) {
                    sr += num;
                    auto iter = Set.lower_bound(sr - k);
                    if (iter != Set.end()) { //�ҵ�һ������Ҫ���
                        maxSize = max(maxSize, sr - *iter);
                    }
                    Set.insert(sr);
                }
            }
        }
        return maxSize;
    }
private:
    int maxSize = INT_MIN;
};