#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



typedef struct imformation
{
	char name[10];
	char sex;
	unsigned int age;
	char tel[13];
	char addr[20];
}linkman;

void create_new_link(linkman* dst[]);//��������ϵ��
void copy_link(linkman* dst[]);//���ı��д�����ϵ��
void delete_link(char name[], linkman* dst[]);//ɾ����ϵ��
void find_link(char name[], linkman* dst[]);
void modify_link(char name[], linkman* dst[]);
void my_print(linkman* dst[]);
void free_all(linkman* dst[]);
void sort(linkman* dst[]);
void print_to_txt(linkman* dst[]);//��ӡ���ı�

int num = 0;

int main()
{
	linkman *link[1000];
	int choice = 0;
	int i = 0;
	char name[10];
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
			printf("===========================\n");
			printf("          ����ѡ��         \n");
			printf("===========================\n");
			printf("    ����ѡ�\n");
			printf("       0---�˳��޸�\n");
			printf("       1---ֱ�Ӵ���\n");
			printf("       2---���ı��ж�ȡ\n");
			printf("===========================\n");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				create_new_link(link);
				break;
			case 2:
				copy_link(link);
				break;
			}
			break;
		case 2:
			scanf("%s", name);
			delete_link(name, link);
			break;
		case 3:
			scanf("%s", name);
			find_link(name, link);
			break;
		case 4:
			scanf("%s", name);
			modify_link(name, link);
			break;
		case 5:
			my_print(link);
			break;
		case 6:
			free_all(link);
			break;
		case 7:
			sort(link);
			break;
		case 0:
			print_to_txt(link);
			free_all(link);
			break;//�˳�ѡ��
		}
	} while (choice != 0);
	printf("��лʹ�ñ�ϵͳ\n");
	return 0;
}

void create_new_link(linkman* dst[])
{
	char choice;
	do
	{
		dst[num] = (linkman*)malloc(sizeof(linkman));
		if (NULL == dst[num])
		{
			perror("error:");
			return;
		}
		printf("�����������Ա����䡢�绰����ַ:> ");
		scanf("%s %c %d %s %s", dst[num]->name, &dst[num]->sex, &dst[num]->age, dst[num]->tel, dst[num]->addr);
		getchar();
		num++;
		printf("�Ƿ������������y/n��:");
		scanf("%c", &choice);
	} while ('y' == choice);
}

void copy_link(linkman* dst[])
{
	FILE *fp;
	fp = fopen("link.txt", "r");
	while (!feof(fp))
	{
		dst[num] = (linkman*)malloc(sizeof(linkman));
		if (NULL == dst[num])
		{
			perror("error:");
			return;
		}
		fscanf(fp, "%s %c %d %s %s", dst[num]->name, &dst[num]->sex, &dst[num]->age, dst[num]->tel, dst[num]->addr);
		num++;
	}
	fclose(fp);
	printf("��ȡ��ɡ�����������\n");
}

void delete_link(char name[], linkman* dst[])
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (0 == strcmp(dst[i]->name, name))
		{
			int j = 0;
			free(dst[i]);
			for (j = i; j < num; j++)
			{
				dst[j] = dst[j + 1];
			}
			num--;
			printf("delete success!");
			return;
		}
	}
	printf("delete fail!");
}

void find_link(char name[], linkman* dst[])
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (0 == strcmp(dst[i]->name, name))
		{
			printf("find success!\n");
			printf("����\t�Ա�\t����\t�绰\t��ַ\n");
			printf("%s  %c  %d  %s  %s\n", dst[i]->name, dst[i]->sex, dst[i]->age, dst[i]->tel, dst[i]->addr);
			return;
		}
	}
	printf("search fail!");
}

void modify_link(char name[], linkman* dst[])
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (0 == strcmp(dst[i]->name, name))
		{
			int choice = 0;
			printf("���ҳɹ�!\n");
			do
			{
				printf("===========================\n");
				printf("          �޸�ѡ��         \n");
				printf("===========================\n");
				printf("    ����ѡ�\n");
				printf("       0---�˳��޸�\n");
				printf("       1---�޸�����\n");
				printf("       2---�޸��Ա�\n");
				printf("       3---�޸�����\n");
				printf("       4---�޸ĵ绰\n");
				printf("       5---�޸ĵ�ַ\n");
				printf("===========================\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 0:
					return;
				case 1:
					printf("��������:");
					scanf("%s", dst[num]->name);
					break;
				case 2:
					printf("�����Ա�:");
					scanf("%c", &dst[num]->sex);
					break;
				case 3:
					printf("��������:");
					scanf("%d", &dst[num]->age);
					break;
				case 4:
					printf("����绰:");
					scanf("%s", dst[num]->tel);
					break;
				case 5:
					printf("�����ַ:");
					scanf("%s", dst[num]->addr);
					break;
				}
			} while (1);
		}
	}
	printf("����ʧ�ܣ�\n");
}

void my_print(linkman* dst[])
{
	int i = 0;
	printf("����\t�Ա�\t����\t�绰\t��ַ\n");
	for (i = 0; i < num; i++)
	{
		printf("  %s  %c  %d  %s  %s\n", dst[i]->name, dst[i]->sex, dst[i]->age, dst[i]->tel, dst[i]->addr);
	}
}

void free_all(linkman* dst[])
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		free(dst[i]);
		dst[i] = NULL;
	}
}

void sort(linkman* dst[])
{
	int i = 0, j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = i; j < num - 1; j++)
		{
			if (strcmp(dst[j]->name, dst[j+1]->name) > 0)
			{
				linkman* tmp = dst[j];
				dst[j] = dst[j + 1];
				dst[j + 1] = tmp;
			}
		}
	}
}

void print_to_txt(linkman* dst[])
{
	int i = 0;
	FILE *fp;
	fp = fopen("link.txt", "w");
	for (i = 0; i < num; i++)
	{
		fprintf(fp, "  %s  %c  %d  %s  %s\n", dst[i]->name, dst[i]->sex, dst[i]->age, dst[i]->tel, dst[i]->addr);
	}
	fclose(fp);
}