#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**********************************************************************************************************
��������̬�滮

˵����
	1. ʵ�ֶ�̬�滮���ĸ����裺
		(1). ����������
			�����ⶨ�壺��ԭ�������ƣ�ֻ������ģ��С���������⣬����dfs֮�еݹ�ʱ�Ľṹ
			������Ҫ��
				��ԭ����������������ʾ����
				��������Ľ�����ɸ�С�������������
			��Ŀ��ԭ��������ȫ����������͵����������ô����������ǰk����������͵����������dp[k]����ʾ
		(2). д��������ĵ��ƹ�ϵ
			��һ���ǹؼ����ڣ�Ҳ�����޷��ڴ��������ֳ���һ�������ڱ��⣺
			dp[k] = max(nums[k] + dp[k-2], dp[k-1])
		(3). ȷ��dp����ļ���˳��
			*���Ե����ϣ�ʹ��dp����ѭ��
			���Զ����£�ʹ�ñ���¼�ݹ鷽��
		(4). �ռ��Ż�			

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n)  O(n)

�漰����֪ʶ�㣺
	��̬�滮��⣺
	https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/
***********************************************************************************************************/

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		if (n == 1) return nums[0];

		vector<int> dp(n, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[n - 1];
	}
};