#define _CRT_SECURE_NO_WARNINGS 1

//找出0-100的素数

#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)

int main()
{
	int i = 0, x = 1;
	while (x <= 100)
	{
		for (i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				break;
			}
		}
		if (i > sqrt(x))//sqrt返回的是double类型，所以不能直接判断i是否等于sqrt+1
		{
			printf("%d ", x);
		}
		x++;
	}
	printf("\n");
	system("pause");
	return 0;
}