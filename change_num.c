#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//����������

#include <stdio.h>
#include <windows.h>
#include <math.h>

void change1(int* x, int* y);
void change2(int* x, int* y);
void change3(int* x, int* y);

int main()
{
	int x = 0, y = 0;
	printf("����������:");
	scanf("%d%d", &x, &y);
	change1(&x, &y);
	printf("������%d %d\n", x, y);
	system("pause");
	return 0;
}

void change1(int* x, int* y)//�Ƚϲ��õķ���
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void change2(int* x, int* y)//��õķ���
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void change3(int* x, int* y)//�Ƚ�����ķ���
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}