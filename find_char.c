#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//����ָ���ַ����״γ��ֵ�λ�ã���δ���֣�����NULL

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>

char* find_char(char dest, const char* src);

int main()
{
	char* src = "abc123def456ghj123";
	printf("%s\n", find_char('g', src));
	system("pause");
	return 0;
}

char* find_char(char dest, const char* src)
{
	while (*src != 0)
	{
		if (*src == dest)
		{
			return src;
		}
		src++;
	}
	return NULL;
}