#define _CRT_SECURE_NO_WARNINGS 1

//ģ��ʵ��string.hͷ�ļ����һЩ����
//������
//strlen
//strcpy
//strcat
//strstr
//memcpy
//memmove

#include <stdio.h>
#include <windows.h>
#include <assert.h>

void reset_string(char* str1, char* str2);//�����ַ����ͳ�ʼһ��
void print_arr(const int arr[], size_t len);//��ӡ���麯��
int my_strlen(char* src);//ģ��strlen
int my_strcmp(const char* str1, const char* str2);//ģ��strcmp
char* my_strcpy(char* dest, const char* src);//ģ��strcpy
char* my_strcat(char* dest, const char* src);//ģ��strcat
char* my_strstr(const char* dest, const char* src);//ģ��strstr
void* my_memcpy(void* dest, const void* src, size_t len);//ģ��memcpy
void* my_memmove(void* dest, const void* src, size_t len);//ģ��ʵ��memmove

int main()
{
	char str1[20] = "abcde";
	char str2[20] = "12345abcabcde";
	int arr1[20] = { 0 };
	int arr2[20] = { 1,2,3,4,5,6,7,8,9,0 };
	printf("ģ��ʵ��sstring.hͷ�ļ��е�һЩ�⺯��\n\n");
	printf("ʹ���ַ�����\n	str1��%s\n	str2��%s\n", str1, str2);
	printf("ʹ�����飺\n	arr1:");
	print_arr(arr1, 10);
	printf("	arr2:");
	print_arr(arr2, 10);
	printf("\n");
	printf("ģ��strlen(str1)��%d\n", my_strlen(str1));
	printf("ģ��strcmp(str1, str2)��%d\n", my_strcmp(str1, str2));
	printf("ģ��strcpy(str1, str2)��%s\n", my_strcpy(str1, str2));
	reset_string(str1, str2);
	printf("ģ��strcat(str1, str2)��%s\n", my_strcat(str1, str2));
	reset_string(str1, str2);
	printf("ģ��strcat(str1, str2)��%s\n", my_strstr(str1, str2));
	printf("ģ��strcat(str2, str1)��%s\n", my_strstr(str2, str1));
	my_memcpy(arr1, arr2, 40);
	printf("ģ��ʵ��memcpy��\n	ģ��memcpy(str1, str2, my_strlen(str2) + 1):%s\n", my_memcpy(str1, str2, my_strlen(str2) + 1));
	printf("	ģ��ʵ��memcpy(arr1, arr2, 40)��\n		arr1��");
	print_arr(arr1, 10);
	printf("		arr2��");
	print_arr(arr2, 10);
	reset_string(str1, str2);
	printf("ģ��ʵ��memmove��\n	ģ��memmove(str1, str2, my_strlen(str2) + 1):%s\n", my_memmove(str1, str2, my_strlen(str2) + 1));
	reset_string(str1, str2);
	printf("	ģ��memmove(str1 + 1, str1, my_strlen(str2) + 1) :%s\n", my_memmove(str1 + 1, str1, my_strlen(str1) + 1));
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

int my_strlen(const char* src)//ģ��strlen
{
	assert(src);
	char* end = src;
	while (*end++)//��endָ��\0�ĺ�һ��λ��
	{
	}
	return end - src - 1;//���س��Ȱ���'\0'�������Ȳ�����'\0'�����Լ�1
}

int my_strcmp(const char* str1, const char* str2)//ģ��strcmp
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

char* my_strcpy(char* dest, const char* src)//ģ��strcpy
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest++ = *src++)//δ����β����ֵ��ָ��++
	{
	}
	return ret;
}

char* my_strcat(char* dest, const char* src)//ģ��strcat
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest)
	{
		dest++;//dest�Ƶ��ַ���β����ָ��'\0'
	}
	while (*dest++ = *src++)//δ����β����ֵ��ָ��++
	{
	}
	return ret;
}

char* my_strstr(const char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* dest_start = NULL;//������whileѭ�����������
	char* src_start = src;//ͬdest_start������
	if (!(*src))//srcΪ���ַ�����û�б�Ҫ�Ƚϣ�ֱ�ӷ���NULL
	{
		return NULL;
	}
	while (*dest)//dest��Ϊ��
	{
		if (*dest == *src)
		{
			dest_start = dest;
			//Ѱ�ҵ�ƥ��ĵ�һ���ַ����Ƚ���dest_start
			//��whileѭ�����澡�����ı�ѭ�������õ��ı���
			while ((*dest_start == *src_start) && (*src_start) && (*dest_start))
			//�Ƚ�ʱ��Ҫ����Ȳ��ƶ�ָ�룬��src_start��dest_start��һ��Ϊ0���˳�
			{
				dest_start++;
				src_start++;
			}
			if (!(*src_start))//src_startָ��'\0'
			{
				return dest;//�ҵ������ص�ǰdestָ���λ��
			}
			else
			{
				src_start = src;//�����㣬src_start�ָ���ָ��src��ʼ
			}
		}
		dest++;//dest����ƶ�
	}
	return NULL;//������ɣ��������ַ���ֱ�ӷ���NULL
}

void* my_memcpy(void* dest, const void* src, size_t len)//ģ��memcpy
{
	assert(dest);
	assert(src);
	void* ret = dest;//����ֵret
	while (len--)//Ҫ�������ֽڸ������Ǵ���
	{
		*(char*)dest = *(char*)src;
		(char*)dest = (char*)dest + 1;
		(char*)src = (char*)src + 1;//void���͵�ָ�벻��ֱ��++��ֻ��ǿת+1
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t len)//ģ��ʵ��memmove
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (((char*)src + len <= (char*)dest) || ((char*)src > (char*)dest))//����������պ�memcpy����
	{
		while (len--)//����len��
		{
			*(char*)dest = *(char*)src;
			(char*)dest = (char*)dest + 1;//ָ�����
			(char*)src = (char*)src + 1;
		}
	}
	else//���������src��destǰ�棬��dest��src�н���
	//���������൱��if (((char*)src + len > (char*)dest) && ((char*)src < (char*)dest))
	{
		(char*)dest = (char*)dest + len - 1;
		(char*)src = (char*)src + len - 1;
		while (len--)//����len��
		{
			*(char*)dest = *(char*)src;
			(char*)dest = (char*)dest - 1;//ָ��ǰ��
			(char*)src = (char*)src - 1;
		}
	}
	return ret;
}