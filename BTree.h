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

BTNode* BuyBTNode(BTreeDataType x);//申请空间
BTNode* CreateBTree(BTreeDataType* a, size_t* pIndex, BTreeDataType invalid);//创建二叉树
void BTreePrevOrder(BTNode* root);//递归前序遍历
void BTreeInOrder(BTNode* root);//递归中序遍历
void BTreePostOrder(BTNode* root);//递归后序遍历

size_t BTreeSize(BTNode* root);//树节点个数
size_t BTreeLeafSize(BTNode* root);//树叶子节点个数
size_t BTreeKLevelSize(BTNode* root, size_t k);//第k层节点个数
size_t BTreeDepth(BTNode* root);//求树深度
BTNode* BTreeFind(BTNode* root, BTreeDataType x);//寻找指定节点
void BTreeLevelOrder(BTNode* root);//层序遍历
// 判断完全二叉树 
int IsCompleteBTree(BTNode* root);
int IsCompleteBTree1(BTNode* root); // flag的方式判断 
								   // 非递归遍历 
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
	//当前节点加左树和右树节点
	return 1 + BTreeSize(root->_left) + BTreeSize(root->_right);
}

size_t BTreeLeafSize(BTNode* root)
{
	static int count = 0;
	if (root == NULL)//不判空出错
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
	//求第k层节点相当于求
	//左树第k-1层节点加右树第k-1层节点
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
	return 1 + (left < right ? right : left);//返回左树右树中较大的深度加当前层
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
	//左右判空，若有一个不为空，说明找到，返回该地址至上层
	if (left != NULL)
	{
		return left;
	}
	if (right != NULL)
	{
		return right;
	}
	return NULL;//未找到返回空
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