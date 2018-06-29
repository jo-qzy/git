#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1.	添加联系人信息
//2.	删除指定联系人信息
//3.	查找指定联系人信息
//4.	修改指定联系人信息
//5.	显示所有联系人信息
//6.	清空所有联系人
//7.	以名字排序所有联系人



typedef struct imformation
{
	char name[10];
	char sex;
	unsigned int age;
	char tel[13];
	char addr[20];
}linkman;

void create_new_link(linkman* dst[]);//创建新联系人
void copy_link(linkman* dst[]);//从文本中创建联系人
void delete_link(char name[], linkman* dst[]);//删除联系人
void find_link(char name[], linkman* dst[]);
void modify_link(char name[], linkman* dst[]);
void my_print(linkman* dst[]);
void free_all(linkman* dst[]);
void sort(linkman* dst[]);
void print_to_txt(linkman* dst[]);//打印至文本

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
		printf("             通讯录管理系统             \n");
		printf("========================================\n");
		printf("      功能选项：\n");
		printf("            0---退出\n");
		printf("            1---添加联系人信息\n");
		printf("            2---删除指定联系人\n");
		printf("            3---查找指定联系人\n");
		printf("            4---修改指定联系人\n");
		printf("            5---显示所有联系人\n");
		printf("            6---清空所有联系人\n");
		printf("            7---以名字排序所有联系人\n");
		printf("========================================\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("===========================\n");
			printf("          创建选项         \n");
			printf("===========================\n");
			printf("    功能选项：\n");
			printf("       0---退出修改\n");
			printf("       1---直接创建\n");
			printf("       2---从文本中读取\n");
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
			break;//退出选项
		}
	} while (choice != 0);
	printf("感谢使用本系统\n");
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
		printf("输入姓名、性别、年龄、电话、地址:> ");
		scanf("%s %c %d %s %s", dst[num]->name, &dst[num]->sex, &dst[num]->age, dst[num]->tel, dst[num]->addr);
		getchar();
		num++;
		printf("是否继续创建？（y/n）:");
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
	printf("读取完成………………\n");
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
			printf("姓名\t性别\t年龄\t电话\t地址\n");
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
			printf("查找成功!\n");
			do
			{
				printf("===========================\n");
				printf("          修改选项         \n");
				printf("===========================\n");
				printf("    功能选项：\n");
				printf("       0---退出修改\n");
				printf("       1---修改姓名\n");
				printf("       2---修改性别\n");
				printf("       3---修改年龄\n");
				printf("       4---修改电话\n");
				printf("       5---修改地址\n");
				printf("===========================\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 0:
					return;
				case 1:
					printf("输入姓名:");
					scanf("%s", dst[num]->name);
					break;
				case 2:
					printf("输入性别:");
					scanf("%c", &dst[num]->sex);
					break;
				case 3:
					printf("输入年龄:");
					scanf("%d", &dst[num]->age);
					break;
				case 4:
					printf("输入电话:");
					scanf("%s", dst[num]->tel);
					break;
				case 5:
					printf("输入地址:");
					scanf("%s", dst[num]->addr);
					break;
				}
			} while (1);
		}
	}
	printf("查找失败！\n");
}

void my_print(linkman* dst[])
{
	int i = 0;
	printf("姓名\t性别\t年龄\t电话\t地址\n");
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