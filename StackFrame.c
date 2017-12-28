#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int a = 0xAAAAAAAA;
    int b = 0xBBBBBBBB;
    int c = add(a, b);
    system("pause");
    return 0;
}

//下面是一个非法调用的代码
//在下段程序中，没有使用任何进入bug函数的语句
//通过修改内存中的信息非法调用了bug函数
//要运行下面这段代码
//你需要将其放在vc++6.0环境下
//并将上面的代码屏蔽掉
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

//void* ret = NULL;

//void bug()
//{
//	int x = 0;
//	int *q = &x;
//	q = q + 2;//q指向ebp-4，而存储返回语句的地址的地址在ebp+4
//	*q = ret;//把返回的地址直接放入q
//	printf("bug : haha,you meet a bug!\n");
//}

//void test(int x)
//{
//	int *p = &x;//这里通过形参x的地址来找存储main函数里的汇编语句的地址
//	p--;//临时变量的前一个地址，存的是该函数结束后需要跳转的main函数语句的地址
//	ret = *p;//把该函数结束时本来要跳转的语句的地址记录下来
//	*p = bug;//令p指向bug函数的地址
//	printf("test : you get in test!\n");
//}

//int main()
//{
//	int a = 1;
//	printf("main : test begin!\n");
//	test(a);
//	__asm//插入一段汇编代码
//	{
//		sub esp,4//没有这一部分，程序可以运行但是会报错
//	}
//	printf("main : finish run test code!\n");
//	system("pause");
//	return 0;
//}
