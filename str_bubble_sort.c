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
	//׼������������
	char* ret = dest;//���ó�ʼָ�뷽�㷵��
	int len = 0;//�洢dest�ַ�������
	va_list pstr;//ָ���ַ�����ָ��
	va_start(pstr, dest);//�ɱ������ʼ��
	while (num--)//�������ַ���ͳһ����dest�ڷ�������
	{
		strcpy(dest, va_arg(pstr, char*));
		while (*dest)//dest��ָ��'\0'
		{
			dest++;//ָ����ƣ�ֱ��ָ��'\0'
		}
	}
	va_end(pstr);//�����ɱ����ʹ��
	//���򲿷�
	dest = ret;
	len = strlen(dest);//�����ַ�������dest�ڣ���dest����һ����Ҫ����Ĵ���Ϊ�ַ�������
	while (len--)
	{
		dest = ret;//��destָ��ͷ��
		int size = 0;//�����ڲ�forѭ������
		int flag = 0;//flag��Ϊ��������ļ�����
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
		if (flag == 0)//���ַ����Ѿ������ˣ���ô�����ʱ��flag�Ͳ���Ϊ0��ֱ�ӷ���
		{
			return ret;
		}
	}
	return ret;
}