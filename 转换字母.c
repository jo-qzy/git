#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//输入a，输出Z

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>


int main()
{
	char cha;
	while(1)
	{
		scanf("%c", &cha);
		getchar();//这个地方不写getchar()有未知错误，不知道为什么
		if (cha == '0')
		{
			break;
		}
		printf("%c\n",'Z' - cha + 'a');
	}
	system("pause");
	return 0;
}