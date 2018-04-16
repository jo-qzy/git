#pragma once 

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef int DataType;

//typedef struct TreeNode 
//{ 
//	DataType _data; 
//	struct TreeNode* _firstChild; 
//	struct TreeNode* _nextBrother; 
//}TreeNode; 

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	DataType _data;
}BTNode;

BTNode* BuyBTNode(DataType x);
// 创建二叉树 
BTNode* CreateBTree(DataType* a, size_t* pIndex, DataType invalid);
void BTreePrevOrder(BTNode* root);
void BTreeInOrder(BTNode* root);
void BTreePostOrder(BTNode* root);

size_t BTreeSize(BTNode* root);
size_t BTreeLeafSize(BTNode* root);
size_t BTreeKLevelSize(BTNode* root, size_t k);
size_t BTreeDepth(BTNode* root);
BTNode* BTreeFind(BTNode* root, DataType x);
void BTreeLevelOrder(BTNode* root);
// 判断完全二叉树 
int IsCompleteBTree(BTNode* root);
int IsCompleteBTree1(BTNode* root); // flag的方式判断 
								   // 非递归遍历 
void BTreePrevOrderNonR(BTNode* root);
void BTreeInOrderNonR(BTNode* root);
void BTreePostOrderNonR(BTNode* root);

BTNode* BuyBTNode(DataType x)
{
	BTNode* new_node = (BTNode*)malloc(sizeof(BTNode));
	new_node->_data = x;
	new_node->_left = NULL;
	new_node->_right = NULL;
	return new_node;
}

BTNode* CreateBTree(DataType* a, size_t* pIndex, DataType invalid)
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
	return 1 + BTreeSize(root->_left) + BTreeSize(root->_right);
}

size_t BTreeLeafSize(BTNode* root)
{
	static int count = 0;
	if (root == NULL)
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
	return 1 + (left < right ? right : left);
}

BTNode* BTreeFind(BTNode* root, DataType x)
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
	if (left != NULL)
	{
		return left;
	}
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}

void BTreeLevelOrder(BTNode* root);

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
	//BTreeLevelOrder(tree);
}