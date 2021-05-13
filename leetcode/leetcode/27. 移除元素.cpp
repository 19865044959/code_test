#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
��������������

˵����
    �ռ临�Ӷȳ�Ԥ��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> numsCopy(nums);
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (numsCopy[i] == val) continue;
            nums[j] = numsCopy[i];
            j++;
        }
        return j;
    }
};

/**********************************************************************************************************
����2��C++ STL

˵����
    erase��remove����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
//��һ��
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         int i;
         for(i = 0; i < nums.size(); i++){ //ע�����ﲻ�ܽ�size���浽n�У���Ϊ����sizeһֱ�ڱ仯��
             if(nums[i] == val){
                 nums.erase(nums.begin() + i);
                 i--;
             }
         }
         return nums.size();
     }
 };

 //�ڶ���
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         auto iter = remove(nums.begin(), nums.end(), val);
         return iter - nums.begin();
     }
 };