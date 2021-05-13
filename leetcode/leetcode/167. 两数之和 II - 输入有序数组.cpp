#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������

˵������ʱ

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
         for(int i = 0; i < n - 1; i++){
             for(int j = i + 1; j < n; j++){
                 if(numbers[i] + numbers[j] == target) return{i + 1, j + 1};
             }
         }
         return {-1, -1};
     }
 };


 /**********************************************************************************************************
���������߹�ϣ

˵����
    ��������е�����£��п���Ҫ��3��O(n)ѭ����ֻ��������֮��I��ʹ�ã���������ǿ��ʹ�ã����Ƽ�

ʱ�临�Ӷ���ռ临�Ӷȣ�
    O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
         unordered_map<int, int> hash;
         for(int i = 0; i < n; i++){
             hash[numbers[i]] = i;
         }
         for(int i = 0; i < n; i++){
             if(hash.find(target - numbers[i]) != hash.end() && hash[numbers[i]] != hash[target - numbers[i]]){
                 int lower, upper;
                 if(hash[numbers[i]] > hash[target - numbers[i]]){
                     lower = hash[target - numbers[i]];
                     upper = hash[numbers[i]];
                 }
                 else{
                     upper = hash[target - numbers[i]];
                     lower = hash[numbers[i]];
                 }
                 return {lower + 1, upper + 1};
             }
         }
         //��������һ�д���ͨ������ԭ���ǣ���ǰ�������֮�Ͳ�ͬ���ǣ���������ʹ����ͬԪ��֮�͵���target��ֻҪ��������ͬԪ���±겻ͬ����
         for(int i = 0; i < n - 1; i++){
             if(numbers[i] == numbers[i + 1] && 2 * numbers[i] == target) return {i + 1, i + 2};
         }
         return {-1, -1};
     }
 };


/**********************************************************************************************************
������˫ָ��

˵����
    �����������飬���Կ��ǹ�ϣ��
    �����������飬���Կ���˫ָ������ֲ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
         int left = 0;
         int right = n - 1;
         while (left < right) {//������ʹ����ͬλ�õ�Ԫ������
             if (target == numbers[left] + numbers[right]) return { left + 1, right + 1 };
             else if (target > numbers[left] + numbers[right]) {
                 left++;
             }
             else {
                 right--;
             }
         }
         return { -1, -1 };
     }
 };

