/*
	��Ʊ����ͨ�⣺https://leetcode-cn.com/circle/article/qiAgHn/
	��Ʊ������׽⣺https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-chong-ji-yu-wqs-er-fen-de-you-xiu-zuo-x36r/

	���������121��122��123��309��714��5��

	�ܽ��£�
	1. ֻ��������һ�Σ���dp[i]Ϊ��i�콻�׺󣬵õ������������dp[i] = max(dp[i - 1], prices[i] - min[0, i - 1])�������ڵ�i�����벻��
	2. ���������޴�/�����䶳��/�������ѣ���dp[i][j]Ϊ��i�콻�׺�״̬Ϊjʱ���õ����������j == 0��ʾ���н�Ǯ�� j == 1��ʾ���й�Ʊ
	3. ֻ������k�Σ���dp[i][k][j]Ϊ��i�콻�׺󣬵�k�Σ�״̬Ϊjʱ���������
*/