#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������ԭ��(������)

˵����
    1. ѡ�����һλ����nums[n-1]��������֮����Ĵ���nums[n-1]����������ҵ�������������nums[k1]��index = k1
    2. ѡ�����ڶ�λ����nums[n-2]��������֮����Ĵ���nums[n-2]����������ҵ�������������nums[k2-1]��index = k2
    3. �ظ��������̣�ֱ��nums������λȫ�����������õ����Ϊk1 k2 k3 ... kn-1
    4. kchose = max(k1, k2, k3 ... kn-1)
    5. ����kchose���Ӧ��λp��ֵ
    6. ˳������nums[kchose+1]  nums[kchose+2] ... nums[end - 1]��
    7. ��������жϣ����kchose == -1��˵��һ��kֵ��û�У���ʱnums�����ֵ����Ҫ��ת���鼴��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    //�����������ã�Ѱ���ڵ�kλǰ��С��nums[k]�����Ҳ�ֵ
    int tempfcn(vector<int>& nums, int k) {
        for (int i = k - 1; i >= 0; i--) {
            if (nums[i] < nums[k]) {
                return i;
            }
        }
        return k; //��ζ��nums[k]����Сֵ
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        int maxindex = -1;
        int p = -1;
        for (i = n - 1; i >= 0; i--) {
            int res = tempfcn(nums, i);
            if (res == i) continue;
            else {
                if (maxindex < res) {
                    maxindex = res;
                    p = i;
                }
            }
        }
        if (maxindex != -1) {
            int temp = nums[maxindex];
            nums[maxindex] = nums[p];
            nums[p] = temp;
            sort(nums.begin() + maxindex + 1, nums.end());
        }
        else {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        }
    }
};