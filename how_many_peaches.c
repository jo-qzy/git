#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//猴子连吃10天桃子，每天吃一半多一个，最后一天只剩1个，求总共几个桃子

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int sum = 0;
	int days = 0;
	int i = 0;
	scanf("%d", &days);
	printf("最初有%d个桃子\n", all_peaches(days));
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