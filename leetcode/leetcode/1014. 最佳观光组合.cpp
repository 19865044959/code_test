#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：暴力法

说明：超时

时间复杂度与空间复杂度：O(n^2)  O(1)

涉及到的知识点：

***********************************************************************************************************/
 class Solution {
 public:
     int maxScoreSightseeingPair(vector<int>& A) {
         if(A.size() == 0) return 0;
         if(A.size() == 1) return A[0];

         int maxPoint = INT_MIN;

         for(int i = 0; i < A.size() - 1; i++){
             for(int j = i + 1; j < A.size(); j++){
                 if(A[i] + A[j] + i - j > maxPoint){
                     maxPoint = A[i] + A[j] + i - j;
                 }
             }
         }
         return maxPoint;
     }
 };


 /**********************************************************************************************************
 方法：转换法

 说明： 
    A[i] + A[j] + i - j (j > i) <=> A[i] + i + A[j] - j (j > i)
    其中A[j] - j是固定的，那么问题等价于
    求解max(A[i] + i)，再加上A[j] - j，再在 1 <= j <= n - 1中找到最大的就完事儿

 时间复杂度与空间复杂度：O(n)  O(1)

 涉及到的知识点：

 ***********************************************************************************************************/
 class Solution {
 public:
     int maxScoreSightseeingPair(vector<int>& A) {
        if(A.size() == 1) return A[0];
        int maxPoint = INT_MIN;
        int maxAii = A[0];
        for(int j = 1; j < A.size(); j++){
            maxPoint = max(maxPoint, maxAii + A[j] - j);
            maxAii = max(maxAii, A[j] + j);
        }
        return maxPoint;
     }
 };