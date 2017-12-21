#define _CRT_SECURE_NO_WARNINGS 1

//1��ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//2��.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
//���磺
//����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd  �� s2 = ACBD������0
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

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
	//�����ת֮����ַ���
	printf("%d\n", CheckString(arr1, arr2, size1, size2));
	//�����Ƿ�����ת���ַ�������Ϊ1������Ϊ0
	system("pause");
	return 0;
}

char * RotateString(char *arr, int num, int size)
{
	char * p = (char*)malloc(sizeof(char)*size);//����n���ռ乩��ת������洢
	char * head = p;//ͷָ�룬����ͷ
	int i = 0;
	for (i = num; i < size-1; i++)
	{
		*p++ = *(arr + i);//����ת���ֵ�CD�ȴ���p
	}
	for (i = 0; i < num; i++)
	{
		*p++ = *(arr + i);//��ת����AB��������p
	}
	*p = '\0';//������\0��������
	return head;
}

int CheckString(char *arr1, char *arr2, int size1, int size2)
{
	char *p = arr1;//pָ��arr1��qָ��arr2
	char *q = arr2;
	while (*q != '\0')
	{
		if (*p == *q)
		{
			if (CheckCycle(p, q))//�ж��Ƿ���ת������ת����1
			{
				return 1;
			}
		}
		q++;
	}
	return 0;//���������˴���˵��û��ƥ����ת���ַ���������0
}

int CheckCycle(char *p, char *q)
{
	while (*q != '\0')
	{
		if (*p != *q)//����ֱ�ӷ���0����ȼ����ж�ֱ��qָ�����һ���ַ�
		{
			return 0;
		}
		p++;
		q++;
	}
	return 1;
}