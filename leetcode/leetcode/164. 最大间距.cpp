#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：利用内置函数sort排序

说明：

时间复杂度与空间复杂度：O(nlogn)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int maximumGap(vector<int>& nums) {
         if(nums.size() == 0 || nums.size() == 1) return 0;
         sort(nums.begin(), nums.end());
         int maxInterval = 0;
         for(int i = 0; i < nums.size() - 1; i++){
             if(nums[i+1] - nums[i] > maxInterval){
                 maxInterval = nums[i+1] - nums[i];
             }
         }
         return maxInterval;
     }
 };


 /**********************************************************************************************************
方法：利用桶排序

说明：
    1. 桶的大小选取是有讲究的，桶的大小bucketSize应该在 (max - min)  / (n - 1) <= bucketSize <= n
    因为min与max是数列的区间两端，共有n个数，那么他们之间有n - 1个间隔，这n - 1个间隔正好可以
    看做是桶的范围，如果桶大小小于了这个范围，说明肯定一定有桶没有用到，那么桶也就浪费了
    比如说：{100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}这10个元素，那么bucketSize >= (1000 - 100)/(10 -1) = 100
    如果bucketSize  = 1，那么从100 - 1000至少需要1000 - 100 +1个桶，并且从101-199等这些桶都是浪费的
    2. 若桶大小设为(max - min) / (n - 1)，且ai与ai+1之间是相邻元素且差值最大，那么ai与ai+1一定
    放到了不同桶之中，并且是不同桶的最大与最小值
    可以这样理解：假设a1,a2,...an是等差数列，即相邻元素差值相同，那么假设桶的大小为t = (max - min) / (n - 1)，
    那么每个桶里面有且仅有一个元素。如果说a1,a2...an是任一序列，且ai与ai+1存在最大差值，那么一定有
    ai+1 - ai > t，也就是说被放到了不同的桶子里面。而相邻两桶子的ti-1的最大值与ti的最小值正好是相邻量元素
    证毕

时间复杂度与空间复杂度：O(n+b)  O(2b)

涉及到的知识点：桶排序源码

***********************************************************************************************************/
 class Solution {
 public:
     //桶结构，记录着这个桶是否被访问过、桶内最大值与最小值，已有类内初始值
     class Bucket {
     public:
         bool meet = false;
         int maxval = INT_MIN;
         int minval = INT_MAX;
     };

     int maximumGap(vector<int>& nums) {
         int n = nums.size();
         if (n < 2) return 0;

         //求nums中的最大最小值
         int maxv = nums[0];
         int minv = nums[0];
         for (int i = 0; i < n; i++) {
             maxv = (maxv > nums[i] ? maxv : nums[i]);
             minv = (minv < nums[i] ? minv : nums[i]);
         }
         //计算桶大小与桶个数
         int bucketSize = max((maxv - minv) / (n - 1), 1); //这句话必加，有很多情况会出现(maxv - minv) / (n - 1) = 0，此时需要设定bucketSize最小是1
         int bucketNum = (maxv - minv) / bucketSize + 1;
         vector<Bucket> bucket(bucketNum);

         //将nums中的元素放入对应的桶内，并且更新桶信息
         int bucketIndex;
         for (auto&& i : nums) {
             bucketIndex = (i - minv) / bucketSize;
             bucket[bucketIndex].meet = true;
             bucket[bucketIndex].maxval = max(bucket[bucketIndex].maxval, i);
             bucket[bucketIndex].minval = min(bucket[bucketIndex].minval, i);
         }

         //记录前面一个桶内的最大值，初始值为所有nums元素中的最小值
         int preMax = minv;
         int ans = 0;
         for (auto&& j : bucket) {
             if (!j.meet) continue; //如果是空桶，那么需要跳过
             ans = max(ans, j.minval - preMax); //更新相邻桶之间的i+1桶的最小值 - i桶的最大值的差的最大值
             preMax = j.maxval; //更新前面一个桶的最大值
         }
         return ans;
     }
 };