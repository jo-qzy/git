#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit(unsigned int value);

int main()
{
	unsigned int num = 0;
	printf("����Ҫ��ת����:");
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
	a = &(unsigned char *)value;//ȡ��Ҫ��������ĵ�ַ��Ϊ���Ż��ٶȣ�����ʹ��char��һ�δ���8������λ
	for (i = 0; i < 4; i++)
	{

		if (*a == 0)//�Ż��ٶȣ������ֽ�Ϊ0��ֱ����������ȡλ
		{
			a++;
			break;
		}
		for (j = 8 * i; j < 8 * (i + 1); j++)//��0����1��&��λȡ�������ƴ�
		{
			if (((*a) & 1) == 1)
			{
				arr[j] = 1;
			}
			*a = *a >> 1;
		}
		a++;
	}
	printf("��ת�Ķ���������:\n");
	for (i = 0; i < 32; i++)
	{
		printf("%d", arr[i]);
		if (i % 8 == 7)
			printf(" ");
	}
	for (i = 0; i < 31; i++)//���������Ķ���������ת���޷�����
	{
		ret = ret + arr[i];
		ret = ret * 2;//�˴�֮����ֻѭ��31�Σ���ѭ��32�Σ���һλ�ᶪʧ
	}
	ret = ret + arr[i];//�������һλ����������
	return ret;
}