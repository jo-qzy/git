#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit(unsigned int value);

int main()
{
	unsigned int num = 0;
	printf("输入要倒转的数:");
	scanf("%d", &num);
	printf("\n%u\n", reverse_bit(num));
	system("pause");
	return 0;
}

unsigned int reverse_bit(unsigned int value)
{
	unsigned char *a;
	unsigned int arr[32] = { 0 };
	int i = 0, j = 31;
	unsigned int ret = 0;
	a = &(unsigned char *)value;//取出要倒序的数的地址，为了优化速度，这里使用char，一次处理8个比特位
	for (i = 0; i < 4; i++)
	{

		if (*a == 0)//优化速度，当该字节为0，直接跳过下面取位
		{
			a++;
			break;
		}
		for (j = 8 * i; j < 8 * (i + 1); j++)//非0，与1来&按位取出二进制串
		{
			if (((*a) & 1) == 1)
			{
				arr[j] = 1;
			}
			*a = *a >> 1;
		}
		a++;
	}
	printf("倒转的二进制序列:\n");
	for (i = 0; i < 32; i++)
	{
		printf("%d", arr[i]);
		if (i % 8 == 7)
			printf(" ");
	}
	for (i = 0; i < 31; i++)//将数组里存的二进制序列转成无符号数
	{
		ret = ret + arr[i];
		ret = ret * 2;//此处之所以只循环31次，若循环32次，第一位会丢失
	}
	ret = ret + arr[i];//加上最后一位二进制序列
	return ret;
}