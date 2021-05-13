/*
	二分查找难点在于边界条件的判断，常见的有：
	while(left <= right) / while(left < right)
	left = mid + 1 / left = mid
	right = mid - 1 / right = mid
	说明：
	1. 无论是while(left <= right)还是while(left < right)，只要写了left = mid或者right = mid这种循环条件，就有可能出现死循环（有可能一直原地踏步）
	2. 只要写了left = mid + 1或者right = mid - 1，一定不会出现死循环（因为每一步都会有缩减，而不是原地踏步）
	3. while(left < right)出来后，i == j是一定的
	4. while(left <= right)出来后， right一定跑到了left的后面一个单位，也就是说，right - left = -1
*/