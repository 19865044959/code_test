#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：暴力法（滑动窗口法）

说明：超时，注意nums.size()返回值是size_type，虽然说可以转换为int，但是在min函数之中，我们必须要手动先转换成int类型再进行min比较

时间复杂度与空间复杂度：O(n^2)  O(1)

涉及到的知识点：

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
 方法：桶排序

 说明：

 时间复杂度与空间复杂度： O(n)   O(n)

 涉及到的知识点：

 ***********************************************************************************************************/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        //t+1可能会溢出，所以要+ 1LL
        long long mod = t + 1LL;
        unordered_map<long long, long long> buck;
        for (int i = 0;i < nums.size();i++)
        {
            long long nth = nums[i] / mod;
            //可能nums[i]为负数，比如-4 / 5 以及 -4 / 5都等于0，所以负数要向下移动一位
            if (nums[i] < 0) nth--;
            //这里要用find 不能直接[],因为可能本身存储的数字就为0
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
