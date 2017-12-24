#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdarg.h>

int Avg(int n, ...)
{
	int i = 0;
	int sum = 0;
	va_list num;
	va_start(num, n);//��ʼ��ָ��λ�ã�ָ���ڵ�һ�������ĵ�ַ�ĺ�һ�������ĳ�ʼ��ַ
	for (i = 0; i < n;i++)
	{
		sum = sum + va_arg(num,int);
	}
	va_end(num);
	return sum / n;
}

int Max(int n, ...)
{
	int max = 0;
	int i = 0;
	va_list num;
	va_start(num, n);
	max = va_arg(num, int);
	for (i = 1; i < n; i++)
	{
		int tmp = va_arg(num, int);
		if (max < tmp)
			max = tmp;
	}
	return max;
}



int main()
{
	int n = 6;
	printf("ƽ��ֵ������%d\n", Avg(n, 5, 7, 8, 9, 10, 3));
	printf("���ֵ������%d\n", Max(n, 5, 7, 8, 9, 10, 3));
	system("pause");
	return 0;
}