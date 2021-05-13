/*
	股票问题通解：https://leetcode-cn.com/circle/article/qiAgHn/
	股票问题进阶解：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-chong-ji-yu-wqs-er-fen-de-you-xiu-zuo-x36r/

	试题包括：121、122、123、309、714共5题

	总结下：
	1. 只允许买卖一次：设dp[i]为第i天交易后，得到的最大利润，则dp[i] = max(dp[i - 1], prices[i] - min[0, i - 1])，即等于第i天卖与不卖
	2. 允许卖无限次/含有冷冻期/有手续费：设dp[i][j]为第i天交易后，状态为j时，得到的最大利润，j == 0表示持有金钱， j == 1表示持有股票
	3. 只允许卖k次：设dp[i][k][j]为第i天交易后，第k次，状态为j时的最大利润
*/