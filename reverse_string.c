//��һ���ַ����������Ϊ:"student a am i"
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯����
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>//Ϊ����isspace������is space���ǿո�

char * Search(char arr[]);
void ReverseString(char *head, char *tail);

int main()
{
	char arr[] = "stdudent a am I";//ԭʼ�ַ���
	printf("ԭ�ַ���:%s\n", arr);
	printf("��ת��:%s\n", Search(arr));
	system("pause");
	return 0;
}

char * Search(char arr[])
{
	assert(arr != '\0');
	char *head, *tail;
	head = arr;
	tail = arr;
	while (*tail != '\0')
	{
		if (isspace(*tail))//����תÿ������
		{
			ReverseString(head, tail - 1);
			head = tail + 1;//ͷָ��Ҫָ�򵥴���λ
		}
		tail++;
	}
	ReverseString(arr, tail - 1);//��ת��������
	return arr;
}

void ReverseString(char *head, char *tail)
{
	char tmp = 0;
	while (tail - head > 0)//�����Ľ�������
	{
		tmp = *tail;
		*tail = *head;
		*head = tmp;
		head++;
		tail--;
	}
}