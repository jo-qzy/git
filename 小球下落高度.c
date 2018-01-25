#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//求球落下经过的长度，从100米落下，每次弹一半

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	float height = 100;
	float sum = 0;
	int times = 0;
	int i = 0;
	scanf("%d", &times);
	for (i = 0;i<times;i++)
	{
		sum += height;
		height /= 2;
	}
	printf("%d次后经过路程为%f，反弹高度为%f", times, sum, height);
	system("pause");
	return 0;
}