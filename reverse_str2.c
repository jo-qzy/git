#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//逆转student am i

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

char* reverse_str(char *dst);//逆转字符串函数
void reverse(char* start, char* end);//辅助逆转函数

int main()
{
	char str[] = "stdudent am i";
	printf("%s\n", reverse_str(str));
	system("pause");
	return 0;
}

char* reverse_str(char* dst)
{
	char* start = dst;
	char* end = dst;
	while (1)
	{
		if (*end == ' ')
		{
			reverse(start, end - 1);//每次要逆转的部分为start到end - 1之间的内容
			start = end + 1;
		}
		if (*end == '\0')
		{
			reverse(start, end - 1);
			break;
		}
		end++;
	}
	reverse(dst, end - 1);
	return dst;
}

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++, end--;
	}
}