#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
��������̬�滮

˵����
	��������198���ϵ���չ��͵��������͵ֱ����Ψһ��ͬ��������ǣ�͵ֱ���ݿ��Ե�һ�������һ�����Ӷ�͵��
	����͵�����ݲ������һ�������һ����͵��Ҫ����һ����˿��Խ���Ŀ��Ϊ����͵��һ�䷿/��͵���һ�䷿��ֱ����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]); //��֤���洫��dpSolution�����ֵ����Ϊ2���������Ϳ��Զ�dp[0]��dp[1]��ʼ����
        int ans1 = dpSolution(nums.begin() + 1, nums.end());
        int ans2 = dpSolution(nums.begin(), nums.end() - 1);
        return max(ans1, ans2);
    }
private:
    int dpSolution(vector<int>::iterator iter1, vector<int>::iterator iter2) {
        vector<int> numCopy(iter1, iter2);

        //����Ĵ�����198һģһ��
        int n = numCopy.size();
        vector<int> dp(n, 0);
        dp[0] = numCopy[0]; //�������洫���ֵ����Ϊ2������˿���ֱ�Ӷ�dp[0]��dp[1]���г�ʼ��
        dp[1] = max(numCopy[0], numCopy[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + numCopy[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};