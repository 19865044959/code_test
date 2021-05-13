#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();
         for(int i = 0; i < n - 1; i++){
             for(int j = i + 1; j < n; j++){
                 if(nums[i] + nums[j] == target){
                     return {i, j};
                 }
             }
         }
         return {};
     }
 };



 /**********************************************************************************************************
 ��������ϣ��

 ˵����
    �ÿռ�ȥ��ʱ��

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/
 class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> a;
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             a[nums[i]] = i;
         }
         for (int i = 0; i < n; i++) {
             int temp = target - nums[i];
             if (a.find(temp) != a.end() && a[temp] != i) {
                 return { i, a[temp] }; //ע�����������д��return {a[nums[i]],a[temp]}�Ļ���Щ�������޷�ͨ���ģ�����
                                                 //�������飺nums = {3, 3}, target = 6;����{0, 1},�������������ظ���Ԫ�ػḲ��ǰһ��
                                                 //��valueֵ����˷��ص���{1, 1}���´���
             }
         }
         return {};
     }
 };