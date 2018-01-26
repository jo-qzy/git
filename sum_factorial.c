#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//求阶乘的和

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("前%d个数的阶乘的和为为：%d\n", num, sum_factorial(num));
	system("pause");
	return 0;
}

int  sum_factorial(int num)
{
	int sum = 1;
	int i = 1;
	num--;
	while (num--)
	{
		i = i * (i + 1);
		sum += i;
	}
	return sum;
}