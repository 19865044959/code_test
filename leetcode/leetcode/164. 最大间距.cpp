#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
�������������ú���sort����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)  O(1)

�漰����֪ʶ�㣺

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
����������Ͱ����

˵����
    1. Ͱ�Ĵ�Сѡȡ���н����ģ�Ͱ�Ĵ�СbucketSizeӦ���� (max - min)  / (n - 1) <= bucketSize <= n
    ��Ϊmin��max�����е��������ˣ�����n��������ô����֮����n - 1���������n - 1��������ÿ���
    ������Ͱ�ķ�Χ�����Ͱ��СС���������Χ��˵���϶�һ����Ͱû���õ�����ôͰҲ���˷���
    ����˵��{100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}��10��Ԫ�أ���ôbucketSize >= (1000 - 100)/(10 -1) = 100
    ���bucketSize  = 1����ô��100 - 1000������Ҫ1000 - 100 +1��Ͱ�����Ҵ�101-199����ЩͰ�����˷ѵ�
    2. ��Ͱ��С��Ϊ(max - min) / (n - 1)����ai��ai+1֮��������Ԫ���Ҳ�ֵ�����ôai��ai+1һ��
    �ŵ��˲�ͬͰ֮�У������ǲ�ͬͰ���������Сֵ
    ����������⣺����a1,a2,...an�ǵȲ����У�������Ԫ�ز�ֵ��ͬ����ô����Ͱ�Ĵ�СΪt = (max - min) / (n - 1)��
    ��ôÿ��Ͱ�������ҽ���һ��Ԫ�ء����˵a1,a2...an����һ���У���ai��ai+1��������ֵ����ôһ����
    ai+1 - ai > t��Ҳ����˵���ŵ��˲�ͬ��Ͱ�����档��������Ͱ�ӵ�ti-1�����ֵ��ti����Сֵ������������Ԫ��
    ֤��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n+b)  O(2b)

�漰����֪ʶ�㣺Ͱ����Դ��

***********************************************************************************************************/
 class Solution {
 public:
     //Ͱ�ṹ����¼�����Ͱ�Ƿ񱻷��ʹ���Ͱ�����ֵ����Сֵ���������ڳ�ʼֵ
     class Bucket {
     public:
         bool meet = false;
         int maxval = INT_MIN;
         int minval = INT_MAX;
     };

     int maximumGap(vector<int>& nums) {
         int n = nums.size();
         if (n < 2) return 0;

         //��nums�е������Сֵ
         int maxv = nums[0];
         int minv = nums[0];
         for (int i = 0; i < n; i++) {
             maxv = (maxv > nums[i] ? maxv : nums[i]);
             minv = (minv < nums[i] ? minv : nums[i]);
         }
         //����Ͱ��С��Ͱ����
         int bucketSize = max((maxv - minv) / (n - 1), 1); //��仰�ؼӣ��кܶ���������(maxv - minv) / (n - 1) = 0����ʱ��Ҫ�趨bucketSize��С��1
         int bucketNum = (maxv - minv) / bucketSize + 1;
         vector<Bucket> bucket(bucketNum);

         //��nums�е�Ԫ�ط����Ӧ��Ͱ�ڣ����Ҹ���Ͱ��Ϣ
         int bucketIndex;
         for (auto&& i : nums) {
             bucketIndex = (i - minv) / bucketSize;
             bucket[bucketIndex].meet = true;
             bucket[bucketIndex].maxval = max(bucket[bucketIndex].maxval, i);
             bucket[bucketIndex].minval = min(bucket[bucketIndex].minval, i);
         }

         //��¼ǰ��һ��Ͱ�ڵ����ֵ����ʼֵΪ����numsԪ���е���Сֵ
         int preMax = minv;
         int ans = 0;
         for (auto&& j : bucket) {
             if (!j.meet) continue; //����ǿ�Ͱ����ô��Ҫ����
             ans = max(ans, j.minval - preMax); //��������Ͱ֮���i+1Ͱ����Сֵ - iͰ�����ֵ�Ĳ�����ֵ
             preMax = j.maxval; //����ǰ��һ��Ͱ�����ֵ
         }
         return ans;
     }
 };