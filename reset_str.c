#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//字符串只有*和数字，令*在前面，数字在后面

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

char* reset_str(char* str);

int main()
{
	char arr[20] = "*159**6*8*985**";
	printf("%s\n", reset_str(arr));
	system("pause");
	return 0;
}

char* reset_str(char* str)
{
	char num[100] = { 0 };
	char star[100] = { 0 };
	char* start = str;
	char* p_num = num;
	char* p_star = star;
	while (*str)
	{
		if (*str == '*')
		{
			*p_star = *str;
			p_star++;
		}
		else
		{
			*p_num = *str;
			p_num++;
		}
		str++;
	}
	str = start;
	strcat(star, num);
	return strcpy(str, star);;
}