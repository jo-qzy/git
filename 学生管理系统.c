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

struct Stu
{
	char name[10];
	char sex;
	unsigned int age;
	char tel[13];
	char addr[20];
};

int main()
{
	struct Stu *stu[1000] = (struct Stu*)malloc(sizeof(struct Stu) * 1000);
	int choice = 0;
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
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			break;//�˳�ѡ��
		}
	} while (choice != 0);
	printf("��лʹ�ñ�ϵͳ\n");
	return 0;
}