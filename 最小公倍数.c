#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//求两个数的最小公倍数
//最小公倍数 = 两数之积 / 最大公约数

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int x = 0, y = 0;
	int GCD, LCM;//最大公约数、最小公倍数
	printf("input two nums:");
	scanf("%d%d", &x, &y);
	GCD = find_GCD(x, y);
	LCM = x * y / GCD;
	printf("最大公约数：%d\n最小公倍数：%d\n", GCD, LCM);
	system("pause");
	return 0;
}

int find_GCD(int num1, int num2)
{
	if (num1 % num2 == 0)
	{
		return num2;
	}
	else
	{
		return find_GCD(num2, num1 % num2);
	}
}