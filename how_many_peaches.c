#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//��������10�����ӣ�ÿ���һ���һ�������һ��ֻʣ1�������ܹ���������

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int sum = 0;
	int days = 0;
	int i = 0;
	scanf("%d", &days);
	printf("�����%d������\n", all_peaches(days));
	system("pause");
	return 0;
}

int all_peaches(int days)
{
	int peaches = 1;
	while (days--)
	{
		peaches = (peaches + 1) * 2;
	}
	return peaches;
}