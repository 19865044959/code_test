#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
�����������㷨

˵����
	1. ���鸴ϰlabuladong�㷨С��P50����
    2. δ�㶮������ֹ������ʲô

ʱ�临�Ӷ���ռ临�Ӷȣ�O(2^n) O(2^n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
private:
    vector<vector<int>>res;
    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        //���в���
        res.push_back(track);
        //����N��������
        for (int i = start; i < nums.size(); i++) {
            //��ѡ�񲢼���·��
            track.push_back(nums[i]);
            //����
            backtrack(nums, i + 1, track);
            //����ѡ��
            track.pop_back();
        }
    }
};


/**********************************************************************************************************
������������

˵����
    ˼�룺��������һ������{1, 2, 3}����ô�𰸻��������ģ�
    {[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]}
    ������ʼ����һ�������飬������ÿ�ΰ�nums�����Ԫ���ó���һ��nums[i]������res�����Ԫ�أ���nums[i] push_back��res�����Ԫ�أ��ٷŻ�res����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(2^n) O(2^n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();
         vector<int> subset;
         vector<vector<int>> res;
         res.push_back(subset);
         for(int i = 0; i < n; i++){
             int m = res.size(); //����ע��һ����Ҫint m = res.size()����ǰ��res���ȼ�¼�������������ѭ������Ϊres������������
             for(int j = 0; j < m; j++){//�����Ҳ�̫���Ϊʲôauto k : res�����ԣ�Ӧ���ǳ��������ˣ�������ָ�뷢���˱仯
                 subset = res[j];
                 subset.push_back(nums[i]);
                 res.push_back(subset);
             }
         }
         return res;
     }
 };