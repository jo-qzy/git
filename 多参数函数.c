#define _CRT_SECURE_NO_WARNINGS 1

//1.使用可变参数，实现函数，求函数参数的平均值。
//2.使用可变参数，实现函数，求函数参数的最大值。
//3.模拟实现printf函数，可完成下面的功能:
//print("s ccc d.\n","hello",'b','i','t'，100); 

#include <stdio.h>
#include <stdarg.h>

int Avg(int n, ...);//求平均数
int Max(int n, ...);//求最大值
int print(char *p, ...);//模拟实现printf
void print_num(int num);//打印数字函数，配合print使用

int main()
{
	int n = 6;
	printf("平均值函数：%d\n", Avg(n, 5, 7, 8, 9, 10, 3));
	printf("最大值函数：%d\n", Max(n, 5, 7, 8, 9, 10, 3));
	print("字符串输出测试：字符串：%s\n		字符：%c%c%c\n		数字：%d\n", "hello", 'b', 'i', 't', 100);
	system("pause");
	return 0;
}

int Avg(int n, ...)
{
	int i = 0;
	int sum = 0;
	va_list ptr;//定义一个char*的指针ptr
	va_start(ptr, n);//初始化指针位置，指针指向参数列表第一个参数也就是n
	for (i = 0; i < n;i++)
	{
		sum = sum + va_arg(ptr,int);//获取下一个数据
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
			case 's'://输出字符串
				q = va_arg(cha, char *);
				while (*q != '\0')
				{
					putchar(*q);
					q++;
					count++;
				}
				break;
			case 'c'://输出字符
				putchar(va_arg(cha, char));
				count++;
				break;
			case 'd':
				print_num(va_arg(cha, int));
				break;//如果你看到了并向到解决方法，可以私我
			case ' '://空格
				putchar(' ');
				break;
			case '\n'://换行
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


void print_num(int num)//引入一个打印数字的函数
{
	if (num > 9)
	{
		print_num(num / 10);
	}
	putchar((num % 10) + 48);//递归打印数字的每一个数
}