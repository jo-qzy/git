#pragma once

#include <string.h>
#include <assert.h>

typedef int DataType;
#define N 10

typedef struct Seqlist
{
	DataType _data[10];
	size_t _size;
}Seqlist;

void SeqlistInit(Seqlist *pSeq);
void SeqlistInsert(Seqlist *pSeq, size_t pos, DataType data);
void SeqlistErase(Seqlist *pSeq, size_t pos, DataType data);
void SeqlistPushFront(Seqlist *pSeq, DataType data);
void SeqlistPushBack(Seqlist *pSeq, DataType data);
void SeqlistPopFront(Seqlist *pSeq);
void SeqlistPopBack(Seqlist *pSeq);

void SeqlistBubbleSort(Seqlist *pSeq);
void SeqlistSelectSort(Seqlist *pSeq);
void SeqlistBinarySearch(Seqlist *pSeq, DataType data);
void SeqlistRemove(Seqlist *pSeq, size_t pos);
void SeqlistRemoveAll(Seqlist *pSeq, DataType data);

void SeqlistPrint(Seqlist *pSeq);

void SeqlistInit(Seqlist *pSeq)
{
	memset(pSeq->_data, 0, sizeof(pSeq->_data));
	pSeq->_size = 0;
}

void SeqlistInsert(Seqlist *pSeq, size_t pos, DataType data)
{
	assert(pSeq);
	int end = pSeq->_size;
	while (end > (int)pos)
	{
		pSeq->_data[end] = pSeq->_data[end - 1];
		end--;
	}
	pSeq->_data[pos] = data;
	pSeq->_size--;
}

void SeqlistPushFront(Seqlist *pSeq, DataType data)
{
	SeqlistInsert(pSeq, 0, data);
}

void SeqlistPrint(Seqlist *pSeq)
{
	int i = 0;
	for (; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->_data[i]);
	}
	printf("\n");
}