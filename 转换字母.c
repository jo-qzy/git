#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

// ‰»Îa£¨ ‰≥ˆZ

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

void print(char cha);

int main()
{
	char cha;
	while(1)
	{
		cha = getchar();
		if (cha == '0')
		{
			break;
		}
		print(cha);
		fflush(stdin);
	}
	system("pause");
	return 0;
}

void print(char dst)
{
	putchar('Z' - dst + 'a');
}