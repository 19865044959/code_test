/*
	�������������Լ��
	����a��b�Ĺ�Լ�� == b��a%b�Ĺ�Լ��
	��ô���ݹ���ȥ����b== 0ʱ��˵���ϴε�b, a % b���a % b�����㣬�����Լ������b
*/
//�ݹ�
int gcd(int a, int b) {	
	if (b == 0) return a;
	return gcd(b, a % b);
}
//����
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