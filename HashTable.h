#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

typedef int HTDataType;

typedef enum Status
{
	EMPTY,
	EXIST,
	DELETE
}Status;

typedef struct HashTableNode
{
	HTDataType _data;
	Status _status;
}HTNode;

typedef struct HashTable
{
	HTNode* _table;
	size_t _size;
	size_t _capacity;
}Hash;

void HashInit(Hash* ht, size_t capacityy);//��ʼ��

//���ܸ�������
static size_t GetPrime(Hash* ht);//STL�������������ȡ����
static size_t HashFunc(HashTable* ht, HTDataType data);	//��ϣ����
static void CheckCapacity(HashTable* ht);//�ռ���
static void HashPrint(HashTable* ht);//��ӡ

//�������ܺ�������ɾ��
bool HashInsert(Hash* ht, HTDataType data);
bool HashRemove(Hash* ht, HTDataType data);
HTNode* HashFind(Hash* ht, HTDataType data);
void TestHashTable();//��������

void HashInit(Hash* ht, size_t capacity)
{
	assert(ht);
	ht->_size = 0;
	ht->_capacity = capacity;
	ht->_capacity = GetPrime(ht);
	ht->_table = (HTNode*)malloc(sizeof(HTNode) * ht->_capacity);
	assert(ht->_table);
	for (size_t i = 0; i < ht->_capacity; i++)
	{
		(*(ht->_table + i))._status = EMPTY;
	}
}

static size_t GetPrime(Hash* ht)
{
	const int _PrimeSize = 28;//������c++��ʹ��
	//�����ݶ��Ǿ�������˲��Ե��������ܹ��������󣬳�ͻ��С
	static const unsigned long _PrimeList[_PrimeSize] = {
		53ul,97ul,193ul,389ul,769ul,
		1543ul,3079ul,6151ul,12289ul,
		24593ul,49157ul,98317ul,196613ul,
		393241ul,786433ul,1572869ul,3145739ul,
		6291469ul,12582917ul,25165843ul,50331653ul,
		100663319ul,201326611ul,402653189ul,805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	int index = 0;
	while (index < _PrimeSize)
	{
		if (ht->_capacity < _PrimeList[index])
		{
			return _PrimeList[index];
		}
		index++;
	}
	return _PrimeList[_PrimeSize - 1];
}

static size_t HashFunc(HashTable* ht, HTDataType data)
{
	//����Ҫ�洢�������͵����ݣ���Ҫ�޸Ĵ˺�����Ѱַ����
	return data % ht->_capacity;
}

static void CheckCapacity(HashTable* ht)
{
	assert(ht);
	//���ռ䲻��������
	if (ht->_size * 10 / ht->_capacity >= 7)
	{
		HashTable newht;
		HashInit(&newht, ht->_capacity);
		for (int i = 0; i < ht->_capacity; i++)
		{
			if ((*(ht->_table + i))._status == EXIST)
			{
				HashInsert(&newht, (*(ht->_table + i))._data);//����Insert��������Ѱַ����
			}
		}
		free(ht->_table);
		ht->_table = newht._table;
		ht->_size = newht._size;
		ht->_capacity = newht._capacity;
	}
}

bool HashInsert(Hash* ht, HTDataType data)
{
	assert(ht);
	CheckCapacity(ht);

	size_t index = HashFunc(ht, data);
	size_t i = 1;
	while ((*(ht->_table + index))._status != EMPTY)
	{
		if ((*(ht->_table + index))._status == EXIST)
		{
			if ((*(ht->_table + index))._data == data)
			{
				return false;
			}
		}
		//index++;
		//if (index == ht->_capacity)
		//{
		//	index = 0;
		//}
		index = index + i * i;//����̽��Ѱַ
		index = index % ht->_capacity;
		i++;
	}
	(*(ht->_table + index))._data = data;
	(*(ht->_table + index))._status = EXIST;
	ht->_size++;
	return true;
}

bool HashRemove(Hash* ht, HTDataType data)
{
	HTNode* node = HashFind(ht, data);
	if (node)
	{
		node->_status = DELETE;
		return true;
	}
	return false;
}

HTNode* HashFind(Hash* ht, HTDataType data)
{
	assert(ht);
	size_t index = HashFunc(ht, data);
	size_t i = 1;
	while ((*(ht->_table + index))._status != EMPTY)
	{
		if ((*(ht->_table + index))._data == data)
		{
			if ((*(ht->_table + index))._status == EXIST)
			{
				return ht->_table + index;
			}
			else
			{
				return NULL;
			}
		}
		//index++;//����̽��Ѱַ��
		index = index + i * i;//����̽��Ѱַ
		index = index % ht->_capacity;
		i++;
	}
	return NULL;
}

static void HashDestroy(HashTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_size = 0;
	ht->_capacity = 0;
}

void HashPrint(HashTable* ht)
{
	//Ϊ�˲�����ʾ�õĴ�ӡ����
	for (int i = 0; i < ht->_capacity; i++)
	{
		if (i % 10 == 0 && i != 0)
		{
			printf("\n");
		}
		if ((*(ht->_table + i))._status == EXIST)
		{
			printf("%2d ", (*(ht->_table + i))._data);
		}
		else if((*(ht->_table + i))._status == DELETE)
		{
			printf(" D ");
		}
		else
		{
			printf(" N ");
		}
	}
	printf("\n");
}

void TestHashTable()
{
	Hash ht;
	HashInit(&ht, 0);
	//�������
	srand((unsigned)time(0));
	for (int i = 0; i < 100; i++)
	{
		HashInsert(&ht, rand() % 100);
	}
	HashPrint(&ht);
	printf("-------------------------------------------------\n");
	//ɾ������
	for (int i = 0; i < 100; i++)
	{
		HashRemove(&ht, rand() % 100);
	}

	HashPrint(&ht);
	HashDestroy(&ht);
}