#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//
//�ṩ������
//1.	�����ϵ����Ϣ
//2.	ɾ��ָ����ϵ����Ϣ
//3.	����ָ����ϵ����Ϣ
//4.	�޸�ָ����ϵ����Ϣ
//5.	��ʾ������ϵ����Ϣ
//6.	���������ϵ��
//7.	����������������ϵ��



typedef struct Addr
{
	char name[10];
	char sex;
	unsigned int age;
	char tel[13];
	char addr[20];
}linkman;

void my_print(linkman* link[]);

int num = 0;

int main()
{
	linkman *link[1000];
	int choice = 0;
	int i = 0;
	do
	{
		printf("========================================\n");
		printf("             ͨѶ¼����ϵͳ             \n");
		printf("========================================\n");
		printf("      ����ѡ�\n");
		printf("            0---�˳�\n");
		printf("            1---�����ϵ����Ϣ\n");
		printf("            2---ɾ��ָ����ϵ��\n");
		printf("            3---����ָ����ϵ��\n");
		printf("            4---�޸�ָ����ϵ��\n");
		printf("            5---��ʾ������ϵ��\n");
		printf("            6---���������ϵ��\n");
		printf("            7---����������������ϵ��\n");
		printf("========================================\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			link[num] = (linkman*)malloc(sizeof(linkman));
			
			scanf("%s %c %d %s %s", link[num]->name, &link[num]->sex, &link[num]->age, link[num]->tel, link[num]->addr);
			num++;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			//my_print(link[1000]);
			for (i = 0; i < num; i++)
			{
				printf("  %s  %c  %d  %s  %s\n", link[i]->name, link[i]->sex, link[i]->age, link[i]->tel, link[i]->addr);
			}
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			break;//�˳�ѡ��
		}
	} while (choice != 0);
	printf("��лʹ�ñ�ϵͳ\n");
	return 0;
}

void my_print(linkman* dst[])
{
	int i = 0;
	printf("  name\tsex\tage\ttelephone\taddress\n");
	for (i = 0; i < num; i++)
	{
		printf("  %s  %c  %d  %s  %s\n", dst[i]->name, dst[i]->sex, dst[i]->age, dst[i]->tel, dst[i]->addr);
	}
}