#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//有一序列：2/1，3/2，5/3，8/5，13/8……求解20个数的和

#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int i = 0;
	float sum = 0;
	float arr[2] = { 2,1 };
	for (i = 0; i < 20; i++)
	{
		float tmp = arr[0];
		sum += arr[0] / arr[1];
		arr[0] = arr[0] + arr[1];
		arr[1] = tmp;
	}
	printf("sum : %f\n", sum);
	system("pause");
	return 0;
}