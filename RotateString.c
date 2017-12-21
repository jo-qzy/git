#define _CRT_SECURE_NO_WARNINGS 1

//1、实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//2、.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
//例如：
//给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd  和 s2 = ACBD，返回0
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char * RotateString(char *arr, int num, int size);
int CheckString(char *arr1, char *arr2, int size1, int size2);
int CheckCycle(char *p, char *q);

int main()
{
	char arr1[] = "ABCDEFG";
	char arr2[] = "CDEFGAB";
	int num = 5;
	int size1 = sizeof(arr1);
	int size2 = sizeof(arr1);
	printf("%s\n", RotateString(arr1, num, size1));
	//输出旋转之后的字符串
	printf("%d\n", CheckString(arr1, arr2, size1, size2));
	//返回是否是旋转的字符串，是为1，不是为0
	system("pause");
	return 0;
}

char * RotateString(char *arr, int num, int size)
{
	char * p = (char*)malloc(sizeof(char)*size);//分配n个空间供旋转后数组存储
	char * head = p;//头指针，保存头
	int i = 0;
	for (i = num; i < size-1; i++)
	{
		*p++ = *(arr + i);//不旋转部分的CD先存入p
	}
	for (i = 0; i < num; i++)
	{
		*p++ = *(arr + i);//旋转部分AB存入数组p
	}
	*p = '\0';//最后给个\0结束数组
	return head;
}

int CheckString(char *arr1, char *arr2, int size1, int size2)
{
	char *p = arr1;//p指向arr1，q指向arr2
	char *q = arr2;
	while (*q != '\0')
	{
		if (*p == *q)
		{
			if (CheckCycle(p, q))//判断是否旋转，若旋转返回1
			{
				return 1;
			}
		}
		q++;
	}
	return 0;//若运行至此处，说明没有匹配旋转的字符串，返回0
}

int CheckCycle(char *p, char *q)
{
	while (*q != '\0')
	{
		if (*p != *q)//不等直接返回0，相等继续判断直到q指向最后一个字符
		{
			return 0;
		}
		p++;
		q++;
	}
	return 1;
}