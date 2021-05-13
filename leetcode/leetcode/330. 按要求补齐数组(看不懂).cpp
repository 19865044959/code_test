#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

/**********************************************************************************************************
������̰��

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

/*�ҵ�˼·��
    ����֤������С���ܹ���[1,x]ȫ����ʾ����������Ϊ1 2 4 8 ... 2^n
    ���Բ���nums�����û��1 2 4 ... ��ô�Ͳ����������
    ���ǰ��������뷨������[1 3]  6 ͨ������ԭ���ǣ�ֻ��Ҫ����2���ɰ�1 2 3 4 5 6ȫ����ʾ����
    ���ǰ����������㣬����Ҫ���� 2 4
*/
// class Solution {
// public:
//     int minPatches(vector<int>& nums, int n) {
//         int k = floor(log(n) - log(2)) + 1;
//         int count = 0;
//         int length = nums.size();
//         for(int i = 0; i <= k; i++){
//             if(find(nums.begin(), nums.end(), 1 << i) != nums.end()) continue;
//             count++;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            }
            else {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};