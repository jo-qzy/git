#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdarg.h>

char* Bubble(int num, char* dest, ...);

int main()
{
	char str[100] = { 0 };
	char str1[10] = "badcfighj";
	char str2[10] = "175032694";
	char str3[10] = "a2bs6df";
	int num = 3;
	Bubble(num, str, str1, str2, str3);
	printf("%s\n", str);
	system("pause");
	return 0;
}

char* Bubble(int num, char* dest, ...)
{
	//准备工作不部分
	char* ret = dest;//设置初始指针方便返回
	int len = 0;//存储dest字符串长度
	va_list pstr;//指向字符串的指针
	va_start(pstr, dest);//可变参数初始化
	while (num--)//将所有字符串统一放在dest内方便排序
	{
		strcpy(dest, va_arg(pstr, char*));
		while (*dest)//dest不指向'\0'
		{
			dest++;//指针后移，直至指向'\0'
		}
	}
	va_end(pstr);//结束可变参数使用
	//排序部分
	dest = ret;
	len = strlen(dest);//所有字符串都在dest内，对dest排序，一共需要排序的次数为字符串长度
	while (len--)
	{
		dest = ret;//令dest指向头部
		int size = 0;//控制内部for循环次数
		int flag = 0;//flag作为监视排序的监视哨
		for (size = 0; size < len; size++)
		{
			if (*dest > *(dest + 1))
			{
				*dest ^= *(dest + 1);
				*(dest + 1) ^= *dest;
				*dest ^= *(dest + 1);
				flag++;
			}
			dest++;
		}
		if (flag == 0)//若字符串已经有序了，那么排序的时候flag就不会为0，直接返回
		{
			return ret;
		}
	}
	return ret;
}