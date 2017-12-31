#define _CRT_SECURE_NO_WARNINGS 1

//模拟实现string.h头文件里的一些函数
//包括：
//strlen
//strcpy
//strcat
//strstr
//memcpy
//memmove

#include <stdio.h>
#include <windows.h>
#include <assert.h>

void reset_string(char* str1, char* str2);//重置字符串和初始一样
void print_arr(const int arr[], size_t len);//打印数组函数
int my_strlen(char* src);//模拟strlen
int my_strcmp(const char* str1, const char* str2);//模拟strcmp
char* my_strcpy(char* dest, const char* src);//模拟strcpy
char* my_strcat(char* dest, const char* src);//模拟strcat
char* my_strstr(const char* dest, const char* src);//模拟strstr
void* my_memcpy(void* dest, const void* src, size_t len);//模拟memcpy
void* my_memmove(void* dest, const void* src, size_t len);//模拟实现memmove

int main()
{
	char str1[20] = "abcde";
	char str2[20] = "12345abcabcde";
	int arr1[20] = { 0 };
	int arr2[20] = { 1,2,3,4,5,6,7,8,9,0 };
	printf("模拟实现sstring.h头文件中的一些库函数\n\n");
	printf("使用字符串：\n	str1：%s\n	str2：%s\n", str1, str2);
	printf("使用数组：\n	arr1:");
	print_arr(arr1, 10);
	printf("	arr2:");
	print_arr(arr2, 10);
	printf("\n");
	printf("模拟strlen(str1)：%d\n", my_strlen(str1));
	printf("模拟strcmp(str1, str2)：%d\n", my_strcmp(str1, str2));
	printf("模拟strcpy(str1, str2)：%s\n", my_strcpy(str1, str2));
	reset_string(str1, str2);
	printf("模拟strcat(str1, str2)：%s\n", my_strcat(str1, str2));
	reset_string(str1, str2);
	printf("模拟strcat(str1, str2)：%s\n", my_strstr(str1, str2));
	printf("模拟strcat(str2, str1)：%s\n", my_strstr(str2, str1));
	my_memcpy(arr1, arr2, 40);
	printf("模拟实现memcpy：\n	模拟memcpy(str1, str2, my_strlen(str2) + 1):%s\n", my_memcpy(str1, str2, my_strlen(str2) + 1));
	printf("	模拟实现memcpy(arr1, arr2, 40)：\n		arr1：");
	print_arr(arr1, 10);
	printf("		arr2：");
	print_arr(arr2, 10);
	reset_string(str1, str2);
	printf("模拟实现memmove：\n	模拟memmove(str1, str2, my_strlen(str2) + 1):%s\n", my_memmove(str1, str2, my_strlen(str2) + 1));
	reset_string(str1, str2);
	printf("	模拟memmove(str1 + 1, str1, my_strlen(str2) + 1) :%s\n", my_memmove(str1 + 1, str1, my_strlen(str1) + 1));
	system("pause");
	return 0;
}

void reset_string(char* str1, char* str2)
{
	my_strcpy(str1, "abcde");
	my_strcpy(str2, "12345abcabcde");
}

void print_arr(const int arr[], size_t len)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int my_strlen(const char* src)//模拟strlen
{
	assert(src);
	char* end = src;
	while (*end++)//令end指向\0的后一个位置
	{
	}
	return end - src - 1;//返回长度包括'\0'，而长度不包括'\0'，所以减1
}

int my_strcmp(const char* str1, const char* str2)//模拟strcmp
{
	assert(str1);
	assert(str2);
	while (*str1 == *str2)
	{
		str1++, str2++;
	}
	if ((unsigned)*str1 > (unsigned)*str2)
	{
		return 1;
	}
	if ((unsigned)*str1 < (unsigned)*str2)
	{
		return -1;
	}
	return 0;
}

char* my_strcpy(char* dest, const char* src)//模拟strcpy
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest++ = *src++)//未到结尾，赋值，指针++
	{
	}
	return ret;
}

char* my_strcat(char* dest, const char* src)//模拟strcat
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest)
	{
		dest++;//dest移到字符串尾部，指向'\0'
	}
	while (*dest++ = *src++)//未到结尾，赋值，指针++
	{
	}
	return ret;
}

char* my_strstr(const char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* dest_start = NULL;//用来在while循环里面遍历用
	char* src_start = src;//同dest_start的作用
	if (!(*src))//src为空字符串，没有必要比较，直接返回NULL
	{
		return NULL;
	}
	while (*dest)//dest不为空
	{
		if (*dest == *src)
		{
			dest_start = dest;
			//寻找到匹配的第一个字符，比较用dest_start
			//在while循环里面尽量不改变循环条件用到的变量
			while ((*dest_start == *src_start) && (*src_start) && (*dest_start))
			//比较时候要求相等才移动指针，且src_start和dest_start有一个为0即退出
			{
				dest_start++;
				src_start++;
			}
			if (!(*src_start))//src_start指向'\0'
			{
				return dest;//找到，返回当前dest指向的位置
			}
			else
			{
				src_start = src;//不满足，src_start恢复到指向src开始
			}
		}
		dest++;//dest向后移动
	}
	return NULL;//遍历完成，无满足字符串直接返回NULL
}

void* my_memcpy(void* dest, const void* src, size_t len)//模拟memcpy
{
	assert(dest);
	assert(src);
	void* ret = dest;//返回值ret
	while (len--)//要拷贝的字节个数就是次数
	{
		*(char*)dest = *(char*)src;
		(char*)dest = (char*)dest + 1;
		(char*)src = (char*)src + 1;//void类型的指针不能直接++，只能强转+1
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t len)//模拟实现memmove
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (((char*)src + len <= (char*)dest) || ((char*)src > (char*)dest))//此种情况按照和memcpy处理
	{
		while (len--)//拷贝len次
		{
			*(char*)dest = *(char*)src;
			(char*)dest = (char*)dest + 1;//指针后移
			(char*)src = (char*)src + 1;
		}
	}
	else//此种情况是src在dest前面，且dest和src有交集
	//这里条件相当于if (((char*)src + len > (char*)dest) && ((char*)src < (char*)dest))
	{
		(char*)dest = (char*)dest + len - 1;
		(char*)src = (char*)src + len - 1;
		while (len--)//拷贝len次
		{
			*(char*)dest = *(char*)src;
			(char*)dest = (char*)dest - 1;//指针前移
			(char*)src = (char*)src - 1;
		}
	}
	return ret;
}