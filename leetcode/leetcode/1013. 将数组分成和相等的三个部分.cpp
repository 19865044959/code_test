#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����������зַ�

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)	O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

//��1�����ÿһ�ݵ�ֵ���Ӷ�����зֵ�
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sumVal = 0;
        for (int i = 0; i < n; i++) {
            sumVal += A[i];
        }
        if (sumVal % 3 != 0) return false;
        int pieceVal = sumVal / 3;
        sumVal = 0;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            sumVal += A[i];
            if (sumVal == pieceVal) {
                flag++;
                sumVal = 0;
            }
        }
        if ((flag == 3) || (flag > 3 && pieceVal == 0)) return true;
        else return false;
    }
};