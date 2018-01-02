#define _CRT_SECURE_NO_WARNINGS 1

//使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“ - a”选项执行加法
//“ - s”选项执行减法，“ - m”选项执行乘法，“ - d”选项执行除法，后面两个参数为操作数。
//例如：命令行参数输入：test.exe - a 1 2
//执行1 + 2输出3

#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	//int num1 = atoi(argv[2]);//linux下可以直接写，编译时加入命令行参数
	//int num2 = atoi(argv[3]);//vs下这么写会报错，内存无法访问，原因缺失命令行参数
	if (argc != 4)
	{
		printf("输入参数有误");
		return 0;
	}
	if ((**(argv + 1)) == '-')
	{
		switch (*(*(argv + 1) + 1))//等效于*(argv[1] + 1)
		{
		case 'a':
			printf("%d\n", atoi(argv[2]) + atoi(argv[3]));
			break;
		case 's':
			printf("%d\n", atoi(argv[2]) - atoi(argv[3]));
			break;
		case 'm':
			printf("%d\n", atoi(argv[2]) * atoi(argv[3]));
			break;
		case 'd':
			printf("%d\n", atoi(argv[2]) / atoi(argv[3]));
			break;
		default:
			printf("无此命令，请重新运行\n");
			break;
		}
	}
	return 0;
}