#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

// ‰»Îa£¨ ‰≥ˆZ

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
		getchar();
		if (cha == '0')
		{
			break;
		}
		printf("%c\n",'Z' - cha + 'a');
	}
	system("pause");
	return 0;
}