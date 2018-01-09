#define _CRT_SECURE_NO_WARNINGS 1

//题目：
//使用函数指针数组访问函数（转移表）
//实现一个简单的计算器


#include <stdio.h>
#include <windows.h>
#include <assert.h>

int my_add(int data1, int data2);
int my_sub(int data1, int data2);
int my_mul(int data1, int data2);
int my_div(int data1, int data2);

int main()
{
	int x = 0, y = 0;
	int choice = 0;
	int (*cal[5])(int, int) = { NULL, my_add, my_sub, my_mul, my_div };
	while (1)
	{
		printf("*********************************\n");
		printf("*      1、add        2、sub     *\n");
		printf("*      3、mul        4、div     *\n");
		printf("*                    0、exit    *\n");
		printf("*********************************\n");

		printf("input choice>");
		scanf("%d", &choice);
		if (choice <= 4 && choice > 0)
		{
			printf("input two data>");
			scanf("%d%d", &x, &y);
			if (choice == 4)
			{
				if (y == 0)
				{
					printf("data error!try again!\n");
					continue;
				}
			}
			printf("result:%d\n", cal[choice](x, y));//通过函数指针的形式访问函数
		}
		else if (choice == 0)
		{
			printf("thank you for using!bye bye!\n");
			break;
		}
		else
		{
			printf("you choose wrong option!try again!\n");
		}
	}
	system("pause");
	return 0;
}

int my_add(int data1, int data2)
{
	return data1 + data2;
}

int my_sub(int data1, int data2)
{
	return data1 - data2;
}

int my_mul(int data1, int data2)
{
	return data1 * data2;
}

int my_div(int data1, int data2)
{
	return data1 / data2;
}