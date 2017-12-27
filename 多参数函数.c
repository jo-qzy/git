#define _CRT_SECURE_NO_WARNINGS 1

//1.ʹ�ÿɱ������ʵ�ֺ���������������ƽ��ֵ��
//2.ʹ�ÿɱ������ʵ�ֺ������������������ֵ��
//3.ģ��ʵ��printf���������������Ĺ���:
//print("s ccc d.\n","hello",'b','i','t'��100); 

#include <stdio.h>
#include <stdarg.h>

int Avg(int n, ...);//��ƽ����
int Max(int n, ...);//�����ֵ
int print(char *p, ...);//ģ��ʵ��printf
void print_num(int num);//��ӡ���ֺ��������printʹ��

int main()
{
	int n = 6;
	printf("ƽ��ֵ������%d\n", Avg(n, 5, 7, 8, 9, 10, 3));
	printf("���ֵ������%d\n", Max(n, 5, 7, 8, 9, 10, 3));
	print("�ַ���������ԣ��ַ�����%s\n		�ַ���%c%c%c\n		���֣�%d\n", "hello", 'b', 'i', 't', 100);
	system("pause");
	return 0;
}

int Avg(int n, ...)
{
	int i = 0;
	int sum = 0;
	va_list ptr;//����һ��char*��ָ��ptr
	va_start(ptr, n);//��ʼ��ָ��λ�ã�ָ��ָ������б��һ������Ҳ����n
	for (i = 0; i < n;i++)
	{
		sum = sum + va_arg(ptr,int);//��ȡ��һ������
	}
	va_end(ptr);
	return sum / n;
}

int Max(int n, ...)
{
	int max = 0;
	int i = 0;
	va_list ptr;
	va_start(ptr, n);
	max = va_arg(ptr, int);
	for (i = 1; i < n; i++)
	{
		int tmp = va_arg(ptr, int);
		if (max < tmp)
			max = tmp;
	}
	va_end(ptr);
	return max;
}

int print(char *p, ...)
{
	char *q = NULL;
	int count = 0;
	va_list cha;
	va_start(cha, p);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
			case 's'://����ַ���
				q = va_arg(cha, char *);
				while (*q != '\0')
				{
					putchar(*q);
					q++;
					count++;
				}
				break;
			case 'c'://����ַ�
				putchar(va_arg(cha, char));
				count++;
				break;
			case 'd':
				print_num(va_arg(cha, int));
				break;//����㿴���˲��򵽽������������˽��
			case ' '://�ո�
				putchar(' ');
				break;
			case '\n'://����
				putchar('\n');
				break;
			default:
				break;
			}
		}
		else
			putchar(*p);
		p++;
	}
	va_end(cha);
	return count;
}


void print_num(int num)//����һ����ӡ���ֵĺ���
{
	if (num > 9)
	{
		print_num(num / 10);
	}
	putchar((num % 10) + 48);//�ݹ��ӡ���ֵ�ÿһ����
}