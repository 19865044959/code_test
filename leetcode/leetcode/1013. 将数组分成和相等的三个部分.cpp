#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：求和切分法

说明：

时间复杂度与空间复杂度：O(n)	O(1)

涉及到的知识点：

***********************************************************************************************************/

//法1：求出每一份的值，从而求出切分点
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