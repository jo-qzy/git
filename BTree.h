#pragma once 

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef int BTreeDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTreeDataType _data;
}BTNode;

#include "queue.h"
#include "stack.h"

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

//������
void BTreeMirror(BTNode* root);
BTNode* BTreeFindLchild(BTNode* root, BTreeDataType x);

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
	//�����пգ�����һ����Ϊ�գ�˵���ҵ������ظõ�ַ���ϲ�
	if (left != NULL)
	{
		return left;
	}
	return BTreeFind(root->_right, x);//�����ң������Ƿ�Ϊ��
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
		BTNode* cur = QueueFront(q);//�漰���е�ʹ����Ҫ����д�Ķ������ʹ��
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

int IsCompleteBTree(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	Queue* q = QueueInit();
	QueuePush(q, root);
	while (QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		if (QueueFront(q) == NULL)
		{
			QueuePop(q);
			break;
		}
		if (cur != NULL)
		{
			QueuePush(q, cur->_left);
			QueuePush(q, cur->_right);
			QueuePop(q);
		}
	}
	while (QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		QueuePop(q);
		if (cur != NULL)
		{
			return 0;
		}
	}
	QueueDestroy(q);
	return 1;
}

int IsCompleteBTree1(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	Queue* q = QueueInit();
	QueuePush(q, root);
	int flag = 0;
	while (QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		QueuePop(q);
		if (cur != NULL && flag == 1)
		{
			return 0;
		}
		if (cur == NULL)
		{
			flag = 1;
		}
		else
		{
			QueuePush(q, cur->_left);
			QueuePush(q, cur->_right);
		}
	}
	QueueDestroy(q);
	return 1;
}

void BTreePrevOrderNonR(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Stack* s = StackInit();
	BTNode* cur = root;
	while (cur || (StackEmpty(s) != 0))
	{
		while (cur)
		{
			printf("%d ", cur->_data);
			StackPush(s, cur);
			cur = cur->_left;
		}
		BTNode* front = StackTop(s);
		StackPop(s);
		cur = front->_right;
	}
	StackDestroy(s);
	printf("\n");
}

void BTreeInOrderNonR(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Stack* s = StackInit();
	BTNode* cur = root;
	while (cur || (StackEmpty(s) != 0))
	{
		while (cur)
		{
			StackPush(s, cur);
			cur = cur->_left;
		}
		BTNode* front = StackTop(s);
		StackPop(s);
		printf("%d ", front->_data);
		cur = front->_right;
	}
	StackDestroy(s);
	printf("\n");
}

void BTreePostOrderNonR(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Stack* s = StackInit();
	BTNode* cur = root;
	BTNode* last = NULL;//���һ�����ʵĽڵ�
	while (cur || (StackEmpty(s) != 0))
	{
		while (cur)
		{
			StackPush(s, cur);
			cur = cur->_left;
		}
		BTNode* front = StackTop(s);
		if ((front->_right == NULL) || (front->_right == last))
		{
			printf("%d ", front->_data);
			StackPop(s);
			last = front;
		}
		else
		{
			cur = front->_right;
		}
	}
	printf("\n");
}

void BTreeMirror(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->_left == root->_right)
	{
		return;
	}
	BTNode* tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	BTreeMirror(root->_left);
	BTreeMirror(root->_right);
}

void BTreeMirrorNoR(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Stack* s = StackInit();
	BTNode* cur = root;
	StackPush(s, cur);
	while ((cur != NULL) || (StackEmpty(s) != 0))
	{
		while (cur)
		{
			BTNode* tmp = cur->_left;
			cur->_left = cur->_right;
			cur->_right = tmp;
			StackPush(s, cur);
			cur = cur->_right;
		}
		BTNode* front = StackTop(s);
		StackPop(s);
		cur = front->_left;
	}
}

BTNode* BTreeFindFather(BTNode* root, BTreeDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (((root->_left != NULL) && (root->_left->_data == x)) || ((root->_right != NULL) && (root->_right->_data == x)))
	{
		return root;
	}
	BTNode* left = BTreeFindFather(root->_left, x);
	if (left != NULL)
	{
		return left;
	}
	return BTreeFindFather(root->_right, x);
}

BTNode* TreeFindLChild(BTNode* root,BTreeDataType x)
{
	BTNode* cur = BTreeFind(root, x);
	if (cur != NULL)
	{
		return cur->_left;
	}
	return cur;
}

BTNode* TreeFindRChild(BTNode* root, BTreeDataType x)
{
	BTNode* cur = BTreeFind(root, x);
	if (cur != NULL)
	{
		return cur->_right;
	}
	return cur;
}

size_t BTreeDistance(BTNode* root, BTNode* dst)//��ڵ����
{
	if (root == NULL)
	{
		return 0;
	}
	if (root == dst)
	{
		return 1;
	}
	size_t left = BTreeDistance(root->_left, dst);
	size_t right = BTreeDistance(root->_right, dst);
	if (left != 0 || right != 0)
	{
		return 1 + (left < right ? right : left);
	}
	return 0;
}

BTNode* BTreeFindSameFather(BTNode* root, BTNode* n1, BTNode* n2)
{
	size_t k1 = BTreeDistance(root, n1), k2 = BTreeDistance(root, n2);
	if (k2 < k1)
	{
		BTNode* tmp = n1;
		k1 = k1 ^ k2;
		k2 = k1 ^ k2;
		k1 = k1 ^ k2;
		n1 = n2;
		n2 = tmp;
	}
	n1 = BTreeFindFather(root, n1->_data);
	k1--;
	while (k2 != k1)
	{
		n2 = BTreeFindFather(root, n2->_data);
		k2--;
	}
	while (n1 != n2)
	{
		n1 = BTreeFindFather(root, n1->_data);
		n2 = BTreeFindFather(root, n2->_data);
	}
	return n1;
}

void TestBinaryTree()
{
	int a[] = { 1, 2, 3, '#', '#', 4 , '#', '#', 5, 6, '#', '#', '#' };
	size_t index = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	printf("BTreePrevOrder:");
	BTreePrevOrder(tree);
	printf("\n");
	printf("BTreePrevOrderNonR:");
	BTreePrevOrderNonR(tree);
	printf("BTreeInOrder:");
	BTreeInOrder(tree);
	printf("\n");
	printf("BTreeInOrderNonR:");
	BTreeInOrderNonR(tree);
	printf("BTreePostOrder:");
	BTreePostOrder(tree);
	printf("\n");
	printf("BTreePostOrderNonR:");
	BTreePostOrderNonR(tree);

	printf("BTreeSize:%d\n", BTreeSize(tree));
	printf("BTreeLeafSize:%d\n", BTreeLeafSize(tree));
	printf("BTreeKLevelSize:%d\n", BTreeKLevelSize(tree, 2));
	printf("BTreeDepth:%d\n", BTreeDepth(tree));
	printf("Node 6:%#p\n", tree->_right->_left);
	printf("BTreeFind:%#p\n", BTreeFind(tree, 6));
	BTreeLevelOrder(tree);
	printf("IsCompleteBTree:%d\n", IsCompleteBTree(tree));
	printf("IsCompleteBTree:%d\n", IsCompleteBTree1(tree));

	BTreeMirror(tree);
	printf("BTreePrevOrder:");
	BTreePrevOrder(tree);
	printf("\n");
	BTreeMirrorNoR(tree);
	printf("BTreePrevOrderNor:");
	BTreePrevOrder(tree);
	printf("\n");

	printf("BTreeFindFather:%p  %p\n", BTreeFindFather(tree, 5), BTreeFind(tree, 1));
	printf("BTreeDistance:%d\n", BTreeDistance(tree, BTreeFind(tree, 4)));
	printf("BTreeDistance:%d\n", BTreeDistance(tree, BTreeFind(tree, 5)));
	printf("BTreeDistance:%d\n", BTreeDistance(tree, BTreeFind(tree, 4)));
	printf("BTreeDistance:%d\n", BTreeDistance(tree, BTreeFind(tree, 5)));
	printf("BTreeFindSameFather:%p %p\n", BTreeFindSameFather(tree, BTreeFind(tree, 4), BTreeFind(tree, 5)), tree);
}