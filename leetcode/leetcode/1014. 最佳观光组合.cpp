#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
������������

˵������ʱ

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2)  O(1)

�漰����֪ʶ�㣺

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
 ������ת����

 ˵���� 
    A[i] + A[j] + i - j (j > i) <=> A[i] + i + A[j] - j (j > i)
    ����A[j] - j�ǹ̶��ģ���ô����ȼ���
    ���max(A[i] + i)���ټ���A[j] - j������ 1 <= j <= n - 1���ҵ����ľ����¶�

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(1)

 �漰����֪ʶ�㣺

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