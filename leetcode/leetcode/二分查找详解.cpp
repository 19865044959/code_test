/*
	���ֲ����ѵ����ڱ߽��������жϣ��������У�
	while(left <= right) / while(left < right)
	left = mid + 1 / left = mid
	right = mid - 1 / right = mid
	˵����
	1. ������while(left <= right)����while(left < right)��ֻҪд��left = mid����right = mid����ѭ�����������п��ܳ�����ѭ�����п���һֱԭ��̤����
	2. ֻҪд��left = mid + 1����right = mid - 1��һ�����������ѭ������Ϊÿһ��������������������ԭ��̤����
	3. while(left < right)������i == j��һ����
	4. while(left <= right)������ rightһ���ܵ���left�ĺ���һ����λ��Ҳ����˵��right - left = -1
*/