/*
	求两个数的最大公约数
	定理：a与b的公约数 == b与a%b的公约数
	那么，递归下去，当b== 0时，说明上次的b, a % b里的a % b等于零，即最大公约数就是b
*/
//递归
int gcd(int a, int b) {	
	if (b == 0) return a;
	return gcd(b, a % b);
}
//迭代
int gcd(int a, int b) {
	while (a % b) {
		int temp = a;
		a = b;
		b = temp % b;
	}
	return b;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}