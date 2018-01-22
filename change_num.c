#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//交换两个数

#include <stdio.h>
#include <windows.h>
#include <math.h>

void change1(int* x, int* y);
void change2(int* x, int* y);
void change3(int* x, int* y);

int main()
{
	int x = 0, y = 0;
	printf("输入两个数:");
	scanf("%d%d", &x, &y);
	change1(&x, &y);
	printf("交换后：%d %d\n", x, y);
	system("pause");
	return 0;
}

void change1(int* x, int* y)//比较不好的方法
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void change2(int* x, int* y)//最好的方法
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void change3(int* x, int* y)//比较巧妙的方法
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}