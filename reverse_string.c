//��һ���ַ����������Ϊ:"student a am i"
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯����
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char * ReverseString(char arr[]);

int main()
{
	char arr[] = "I am a stdudent.";
	printf("ԭ�ַ���:%s\n", arr);
	printf("��ת��:%s\n", ReverseString(arr));
	system("pause");
	return 0;
}

char * ReverseString(char arr[])
{
	char *head,*tail;
	char tmp = 0;
	head = arr;
	tail = arr;
	while (*tail != '\0')
	{
		tail++;
	}
	tail--;
	while (tail - head > 0)
	{
		tmp = *tail;
		*tail = *head;
		*head = tmp;
		head++;
		tail--;
	}
	return arr;
}