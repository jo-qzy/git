#pragma once
#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef int BSTreeDataType;

typedef struct BinarySearchTree
{
	struct BinarySearchTree* _left;
	struct BinarySearchTree* _right;
	BSTreeDataType _data;
}BSTree;

bool BSTreeInsert(BSTree** root, BSTreeDataType data);
bool BSTreeRemove(BSTree* root, BSTreeDataType data);
BSTree* BSTreeFind(BSTree* root, BSTreeDataType data);

BSTree* CreateBSTreeNode(BSTreeDataType data)
{
	BSTree* new_node = (BSTree*)malloc(sizeof(BSTree));
	new_node->_data = data;
	new_node->_left = NULL;
	new_node->_right = NULL;
	return new_node;
}

bool BSTreeInsert(BSTree** root, BSTreeDataType data)
{
	if (*root == NULL)
	{
		*root = CreateBSTreeNode(data);
		return true;
	}
	if ((*root)->_data < data)
	{
		if ((*root)->_left != NULL)
		{
			return BSTreeInsert(&((*root)->_left), data);
		}
		else
		{
			(*root)->_left = CreateBSTreeNode(data);
			return true;
		}
	}
	else if ((*root)->_data > data)
	{
		if ((*root)->_right != NULL)
		{
			return BSTreeInsert(&((*root)->_right), data);
		}
		else
		{
			(*root)->_right = CreateBSTreeNode(data);
			return true;
		}
	}
	return false;
}

bool BSTreeInsertNoR(BSTree** root, BSTreeDataType data)
{
	BSTree* cur = *root;
	BSTree* prev = *root;
	if (*root == NULL)
	{
		*root = CreateBSTreeNode(data);
		return true;
	}
	while (cur)
	{
		prev = cur;
	
		if (cur->_data > data)
		{
			cur = cur->_left;
		}
		else if (cur->_data < data)
		{
			cur = cur->_right;
		}
		else if (cur->_data == data)
		{
			return false;
		}
	}
	if (prev->_data > data)
	{
		prev->_left = CreateBSTreeNode(data);
	}
	else
	{
		prev->_right = CreateBSTreeNode(data);
	}
	return true;
}

bool BSTreeRemove(BSTree* root, BSTreeDataType data);

BSTree* BSTreeFind(BSTree* root, BSTreeDataType data)
{
	return NULL;
}

BSTree* BSTreeFindNoR(BSTree* root, BSTreeDataType data)
{
	BSTree* cur = root;
	while (cur)
	{
		if (cur->_data < data)
		{
			cur = cur->_right;
		}
		else if (cur->_data > data)
		{
			cur = cur->_left;
		}
		else if (cur->_data == data)
		{
			return cur;
		}
	}
	return NULL;
}

void BSTreeTest()
{
	BSTree* tree = NULL;
	BSTreeInsert(&tree, 5);
	BSTreeInsert(&tree, 4);
	BSTreeInsert(&tree, 7);
	BSTreeInsert(&tree, 9);
	BSTreeInsert(&tree, 6);
	BSTreeInsert(&tree, 8);
	BSTreeInsert(&tree, 1);
	BSTreeInsert(&tree, 2);
}