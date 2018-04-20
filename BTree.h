#pragma once 

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef int BTreeDataType;

//typedef struct TreeNode 
//{ 
//	BTreeDataType _data; 
//	struct TreeNode* _firstChild; 
//	struct TreeNode* _nextBrother; 
//}TreeNode; 

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTreeDataType _data;
}BTNode;

#include "queue.h"

BTNode* BuyBTNode(BTreeDataType x);//����ռ�
BTNode* CreateBTree(BTreeDataType* a, size_t* pIndex, BTreeDataType invalid);//����������
void BTreePrevOrder(BTNode* root);//�ݹ�ǰ�����
void BTreeInOrder(BTNode* root);//�ݹ��������
void BTreePostOrder(BTNode* root);//�ݹ�������

size_t BTreeSize(BTNode* root);//���ڵ����
size_t BTreeLeafSize(BTNode* root);//��Ҷ�ӽڵ����
size_t BTreeKLevelSize(BTNode* root, size_t k);//��k��ڵ����
size_t BTreeDepth(BTNode* root);//�������
BTNode* BTreeFind(BTNode* root, BTreeDataType x);//Ѱ��ָ���ڵ�
void BTreeLevelOrder(BTNode* root);//�������
// �ж���ȫ������ 
int IsCompleteBTree(BTNode* root);
int IsCompleteBTree1(BTNode* root); // flag�ķ�ʽ�ж� 
								   // �ǵݹ���� 
void BTreePrevOrderNonR(BTNode* root);
void BTreeInOrderNonR(BTNode* root);
void BTreePostOrderNonR(BTNode* root);

BTNode* BuyBTNode(BTreeDataType x)
{
	BTNode* new_node = (BTNode*)malloc(sizeof(BTNode));
	new_node->_data = x;
	new_node->_left = NULL;
	new_node->_right = NULL;
	return new_node;
}

BTNode* CreateBTree(BTreeDataType* a, size_t* pIndex, BTreeDataType invalid)
{
	BTNode* root = NULL;
	if (*(a + *pIndex) != invalid)
	{
		root = BuyBTNode(*(a + *pIndex));
		(*pIndex)++;
		root->_left = CreateBTree(a, pIndex, invalid);
		(*pIndex)++;
		root->_right = CreateBTree(a, pIndex, invalid);
	}
	return root;
}

void BTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}

void BTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTreeInOrder(root->_left);
	printf("%d ", root->_data);
	BTreeInOrder(root->_right);
}

void BTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTreePostOrder(root->_left);
	BTreePostOrder(root->_right);
	printf("%d ", root->_data);
}

size_t BTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//��ǰ�ڵ�������������ڵ�
	return 1 + BTreeSize(root->_left) + BTreeSize(root->_right);
}

size_t BTreeLeafSize(BTNode* root)
{
	static int count = 0;
	if (root == NULL)//���пճ���
	{
		return 0;
	}
	else if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BTreeLeafSize(root->_left) + BTreeLeafSize(root->_right);
}

size_t BTreeKLevelSize(BTNode* root, size_t k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	//���k��ڵ��൱����
	//������k-1��ڵ��������k-1��ڵ�
	return BTreeKLevelSize(root->_left, k - 1) + BTreeKLevelSize(root->_right, k - 1);
}

size_t BTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	size_t left = BTreeDepth(root->_left);
	size_t right = BTreeDepth(root->_right);
	return 1 + (left < right ? right : left);//�������������нϴ����ȼӵ�ǰ��
}

BTNode* BTreeFind(BTNode* root, BTreeDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* left = BTreeFind(root->_left, x);
	BTNode* right = BTreeFind(root->_right, x);
	//�����пգ�����һ����Ϊ�գ�˵���ҵ������ظõ�ַ���ϲ�
	if (left != NULL)
	{
		return left;
	}
	if (right != NULL)
	{
		return right;
	}
	return NULL;//δ�ҵ����ؿ�
}

void BTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue* q = QueueInit();
	QueuePush(q, root);
	while (QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		QueuePop(q);
		printf("%d ", cur->_data);
		if (cur->_left != NULL)
		{
			QueuePush(q, cur->_left);
		}
		if (cur->_right != NULL)
		{
			QueuePush(q, cur->_right);
		}
		
	}
	printf("\n");
	QueueDestroy(q);
}

void TestBinaryTree()
{
	int a[] = { 1, 2, 3, '#', '#',4,'#', '#', 5, 6,'#' ,'#' ,'#' };
	size_t index = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	BTreePrevOrder(tree);
	printf("\n");
	//BTreePrevOrderNonR(tree);
	BTreeInOrder(tree);
	printf("\n");
	BTreePostOrder(tree);
	printf("\n");

	printf("BTreeSize:%d\n", BTreeSize(tree));
	printf("BTreeLeafSize:%d\n", BTreeLeafSize(tree));
	printf("BTreeKLevelSize:%d\n", BTreeKLevelSize(tree, 2));
	printf("BTreeDepth:%d\n", BTreeDepth(tree));
	printf("Node 5:%#p\n", tree->_right->_left);
	printf("BTreeFind:%#p\n", BTreeFind(tree, 6));
	//printf("IsCompleteBTree?%d\n", IsCompleteBTree1(tree));
	BTreeLevelOrder(tree);
}