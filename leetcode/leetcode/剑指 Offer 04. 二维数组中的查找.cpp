#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������Ѱ������Ԫ�أ����Ͻ�/���½�

˵����
	��ά���飺�Խ��ߡ�4���Ƕ����ܳ�Ϊ����Ľ���Կ��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(row + column) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)  return false;
        int column = matrix[0].size();
        int i = row - 1;
        int j = 0;
        while (i >= 0 && j < column) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) i--;
            else j++;
        }
        return false;
    }
};
