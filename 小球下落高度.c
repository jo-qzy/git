#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//�������¾����ĳ��ȣ���100�����£�ÿ�ε�һ��

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
	printf("%d�κ󾭹�·��Ϊ%f�������߶�Ϊ%f", times, sum, height);
	system("pause");
	return 0;
}