#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int factorial(int num)//��׳˵ĺ���
{
	int i = 1;
	if (num == 0)
		return 1;
	else
	{
		int sum = 1;
		for (int i = 1; i <= num; i++)
			sum *= i;
		return sum;
	}
}

void function(int rowNum)//��ӡ����
{
	int num = 0;
	int i = 1;
	int j = 1;
	for (int n = 1; n <= rowNum; ++n)//��ӡÿ�пո�
	{
		for (i = 0; i <= rowNum - n; i++)  
			printf(" ");
		for (j = 1; j <= n; j++)  //��ӡÿ�е�ÿ����
		{
			num = factorial(n - 1) / (factorial(j - 1)*factorial(n - j));
			printf("%d ", num);
		}
		printf("\n");
	}
}

int main()
{
	int line = 0;
	scanf("%d", &line);
	function(line);
	system("pause");
	return 0;
}