#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//������������С������
//��С������ = ����֮�� / ���Լ��

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int x = 0, y = 0;
	int GCD, LCM;//���Լ������С������
	printf("input two nums:");
	scanf("%d%d", &x, &y);
	GCD = find_GCD(x, y);
	LCM = x * y / GCD;
	printf("���Լ����%d\n��С��������%d\n", GCD, LCM);
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