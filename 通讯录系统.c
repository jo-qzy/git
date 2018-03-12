#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

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
			break;//退出选项
		}
	} while (choice != 0);
	printf("感谢使用本系统\n");
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