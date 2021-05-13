#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1����ϣ��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�
	O(n)
	O(n)��������ĿҪ��

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     int firstMissingPositive(vector<int>& nums) {
         unordered_map<int, int> hash;
         int n = nums.size();
         for(auto k : nums){
              hash[k]++;
         }
         for(int i = 1; i <= n; i++){
             if(hash.find(i) != hash.end()) continue;
             else return i;
         }
         return n + 1; //������һ��Ҳû�ҵ��������ʱ��Ӧ�ÿ��ǵ���nums�������еĶ���������������1-n����������Ǵ�ʱֻ��Ҫ����n+1���ɣ��������ӣ�[]��[1]��[3,1,2]�ȵ�
     }
 };


 /**********************************************************************************************************
 ����1��ԭ�ع�ϣ

 ˵����
    ���չ�ϣ��Ĵ��棬���������������ص㣬������i+1�ŵ�λ��i��

 ʱ�临�Ӷ���ռ临�Ӷȣ�
     O(n)
     O(1)

 �漰����֪ʶ�㣺
    ԭ���㷨��ԭ���㷨���ǲ����ö���Ŀռ䣨����˵��ʱ������ά��Ϊn�����飩����ԭ����������������ֱ���޸�����
    �Ӷ����ٿռ临�Ӷȵ��㷨
 ***********************************************************************************************************/

 class Solution {
 public:
     int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) { //����������������ȣ�����������ѭ��
                 swap(nums, i, nums[i] - 1);
             }
         }

         for (int i = 0; i < n; i++) {
             if (nums[i] - 1 != i) return i + 1;
         }
         return n + 1;
     }
 private:
     void swap(vector<int>& nums, int i, int j) {
         int temp = nums[i];
         nums[i] = nums[j];
         nums[j] = temp;
     }
 };