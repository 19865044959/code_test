#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
���������������������ڷ���

˵������ʱ��ע��nums.size()����ֵ��size_type����Ȼ˵����ת��Ϊint��������min����֮�У����Ǳ���Ҫ�ֶ���ת����int�����ٽ���min�Ƚ�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2)  O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
 class Solution {
 public:
     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         for(int i = 0;i < nums.size() - 1; i++){
             for(int j = i + 1; j < min(i + k + 1, int(nums.size())); j++){
                 if(abs(nums[i] - nums[j]) <= t) return true;
             }
         }
         return false;
     }
 };

 /**********************************************************************************************************
 ������Ͱ����

 ˵����

 ʱ�临�Ӷ���ռ临�Ӷȣ� O(n)   O(n)

 �漰����֪ʶ�㣺

 ***********************************************************************************************************/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        //t+1���ܻ����������Ҫ+ 1LL
        long long mod = t + 1LL;
        unordered_map<long long, long long> buck;
        for (int i = 0;i < nums.size();i++)
        {
            long long nth = nums[i] / mod;
            //����nums[i]Ϊ����������-4 / 5 �Լ� -4 / 5������0�����Ը���Ҫ�����ƶ�һλ
            if (nums[i] < 0) nth--;
            //����Ҫ��find ����ֱ��[],��Ϊ���ܱ���洢�����־�Ϊ0
            if (buck.find(nth) != buck.end())
                return true;
            else if (buck.find(nth - 1) != buck.end() && nums[i] - buck[nth - 1] <= t)
                return true;
            else if (buck.find(nth + 1) != buck.end() && buck[nth + 1] - nums[i] <= t)
                return true;
            buck[nth] = nums[i];
            if (i >= k)
            {
                buck.erase(nums[i - k] / mod);
            }
        }
        return false;
    }
};
