#pragma once
#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef char* BSTreeKey;

typedef struct BinarySearchTree
{
	struct BinarySearchTree* _left;
	struct BinarySearchTree* _right;
	BSTreeKey _key;
	BSTreeKey _value;
}BSTree;

BSTree* CreateBSTreeNode(BSTreeKey key, BSTreeKey value);//Ϊ�½ڵ㿪�ٿռ�
bool BSTreeInsert(BSTree** root, BSTreeKey key);//�ݹ����
bool BSTreeInsertNoR(BSTree** root, BSTreeKey key, BSTreeKey value);//�ǵݹ����
bool BSTreeRemove(BSTree** root, BSTreeKey key);//�ݹ鷨ɾ���ڵ�
bool BSTreeRemoveNoR(BSTree** root, BSTreeKey key);//�ǵݹ�ɾ��
BSTree* BSTreeFind(BSTree* root, BSTreeKey key);//�ݹ���ҽڵ�
BSTree* BSTreeFindNoR(BSTree* root, BSTreeKey key);//�ǵݹ����
void BSTreeInOrder(BSTree* root);//�������
void BSTreeDestroy(BSTree* root);//������
void BSTreeTest();//��������
void TestDictionary();

BSTree* CreateBSTreeNode(BSTreeKey key, BSTreeKey value)
{
	BSTree* new_node = (BSTree*)malloc(sizeof(BSTree));
	new_node->_key = key;
	new_node->_value = value;
	new_node->_left = NULL;
	new_node->_right = NULL;
	return new_node;
}

//bool BSTreeInsert(BSTree** root, BSTreeKey key, BSTreeKey value)
//{
//	if (*root == NULL)
//	{
//		*root = CreateBSTreeNode(key, value);
//		return true;
//	}
//	if ((*root)->_key > key)
//	{
//		if ((*root)->_left != NULL)
//		{
//			return BSTreeInsert(&((*root)->_left), key);
//		}
//		else
//		{
//			(*root)->_left = CreateBSTreeNode(key, value);
//			return true;
//		}
//	}
//	else if ((*root)->_key < key)
//	{
//		if ((*root)->_right != NULL)
//		{
//			return BSTreeInsert(&((*root)->_right), key);
//		}
//		else
//		{
//			(*root)->_right = CreateBSTreeNode(key, value);
//			return true;
//		}
//	}
//	return false;
//}

bool BSTreeInsertNoR(BSTree** root, BSTreeKey key, BSTreeKey value)
{
	BSTree* cur = *root;
	BSTree* prev = *root;
	if (*root == NULL)
	{
		*root = CreateBSTreeNode(key, value);
		return true;
	}
	while (cur)//Ѱ�Һ��ʵĲ���λ��
	{
		prev = cur;
		if (strcmp(cur->_key, key))
		{
			cur = cur->_left;
		}
		else if (!strcmp(cur->_key, key))
		{
			cur = cur->_right;
		}
		else
		{
			return false;
		}
	}
	if (strcmp(prev->_key, key))
	{
		prev->_left = CreateBSTreeNode(key, value);
	}
	else
	{
		prev->_right = CreateBSTreeNode(key, value);
	}
	return true;
}

bool BSTreeRemove(BSTree** root, BSTreeKey key)
{
	if (*root == NULL)
	{
		return false;
	}
	else if ((*root)->_key < key)
	{
		return BSTreeRemove(&((*root)->_right), key);
	}
	else if ((*root)->_key > key)
	{
		return BSTreeRemove(&((*root)->_left), key);
	}
	if ((*root)->_left == NULL)//��Ϊ��
	{
		BSTree* tmp = *root;
		(*root) = (*root)->_right;
		free(tmp);
		return true;
	}
	else if ((*root)->_right == NULL)//��Ϊ��
	{
		BSTree* tmp = *root;
		(*root) = (*root)->_left;
		free(tmp);
		return true;
	}
	else//���Ҷ���Ϊ��
	{
		BSTree* instead = (*root)->_left;//Ѱ�����������Ľڵ㣬�������ݸ�Ҫɾ�Ľڵ�
		while (instead->_right != NULL)//������ת��Ϊɾ�����������Ľڵ�
		{
			instead = instead->_right;
		}
		(*root)->_key = instead->_key;
		return BSTreeRemove(&((*root)->_left), instead->_key);
	}
}

bool BSTreeRemoveNoR(BSTree** root, BSTreeKey key)
{
	BSTree* cur = *root;
	BSTree* parent = cur;
	while (cur)
	{
		//Ѱ��ָ���ڵ�
		if (cur->_key != key)
		{
			parent = cur;
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		else
		{
			if (cur->_left == NULL)
			{
				if (cur == *root)
				{
					(*root) = cur->_right;
					free(cur);
				}
				else if (parent->_left == cur)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
				free(cur);
				return true;
			}
			else if (cur->_right == NULL)
			{
				if (cur == *root)
				{
					(*root) = cur->_left;
					free(cur);
				}
				else if (parent->_left == cur)
				{
					parent->_left = cur->_left;
				}
				else
				{
					parent->_right = cur->_left;
				}
				free(cur);
				return true;
			}
			else
			{
				BSTree* instead = cur->_right;
				if (instead->_left == NULL)
				{
					cur->_key = instead->_key;
					cur->_right = instead->_right;
				}
				else
				{
					while (instead->_left != NULL)
					{
						parent = instead;
						instead = instead->_left;
					}
					cur->_key = instead->_key;
					parent->_left = instead->_right;
				}
				free(instead);
				return true;
			}
		}
	}
	return false;
}

BSTree* BSTreeFind(BSTree* root, BSTreeKey key)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (strcmp(root->_key, key) == 0)
	{
		return root;
	}
	if (strcmp(root->_key, key) < 0)
	{
		return BSTreeFind(root->_right, key);
	}
	else
	{
		return BSTreeFind(root->_left, key);
	}
}

BSTree* BSTreeFindNoR(BSTree* root, BSTreeKey key)
{
	BSTree* cur = root;
	while (cur)
	{
		if (cur->_key < key)
		{
			cur = cur->_right;
		}
		else if (cur->_key > key)
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}

void BSTreeInOrder(BSTree* root)
{
	if(root == NULL)
	{
		return;
	}
	BSTreeInOrder(root->_left);
	printf("%s ", root->_key);
	BSTreeInOrder(root->_right);
}

void BSTreeDestroy(BSTree* root)
{
	if (root == NULL)
	{
		return;
	}
	BSTreeDestroy(root->_left);
	BSTreeDestroy(root->_right);
	free(root);
}

//void BSTreeTest()
//{
//	BSTree* tree = NULL;
//
//	BSTree* tree_noR = NULL;
//
//	BSTreeInsert(&tree, 5);
//	BSTreeInsert(&tree, 4);
//	BSTreeInsert(&tree, 7);
//	BSTreeInsert(&tree, 9);
//	BSTreeInsert(&tree, 6);
//	BSTreeInsert(&tree, 8);
//	BSTreeInsert(&tree, 1);
//	BSTreeInsert(&tree, 2);
//	printf("Find 2:%d\n", BSTreeFind(tree, 2)->_key);
//	printf("%#p\n", BSTreeFind(tree, 100));
//	BSTreeInOrder(tree);
//	printf("\n");
//	BSTreeRemove(&tree, 2);
//	BSTreeRemove(&tree, 4);
//	BSTreeRemove(&tree, 7);
//	BSTreeRemove(&tree, 8);
//	BSTreeRemove(&tree, 8);
//	BSTreeRemove(&tree, 5);
//	BSTreeInOrder(tree);
//	printf("\n");
//
//	printf("NoRTest:\n");
//	BSTreeInsertNoR(&tree_noR, 5);
//	BSTreeInsertNoR(&tree_noR, 4);
//	BSTreeInsertNoR(&tree_noR, 7);
//	BSTreeInsertNoR(&tree_noR, 9);
//	BSTreeInsertNoR(&tree_noR, 6);
//	BSTreeInsertNoR(&tree_noR, 8);
//	BSTreeInsertNoR(&tree_noR, 1);
//	BSTreeInsertNoR(&tree_noR, 2);
//	printf("Find 2:%d\n", BSTreeFindNoR(tree_noR, 2)->_key);
//	printf("%#p\n", BSTreeFindNoR(tree_noR, 100));
//	BSTreeInOrder(tree_noR);
//	printf("\n");
//	BSTreeRemoveNoR(&tree_noR, 2);
//	BSTreeRemoveNoR(&tree_noR, 4);
//	BSTreeRemoveNoR(&tree_noR, 7);
//	BSTreeRemoveNoR(&tree_noR, 8);
//	BSTreeRemoveNoR(&tree_noR, 8);
//	BSTreeRemoveNoR(&tree_noR, 5);
//	BSTreeInOrder(tree_noR);
//	printf("\n");
//
//	BSTreeDestroy(tree);
//	BSTreeDestroy(tree_noR);
//}

void TestDictionary()
{
	BSTree* tree = NULL;
	
	BSTree* tree_noR = NULL;
	
	char str[10] = { 0 };

	BSTreeInsertNoR(&tree, "insert", "����");
	BSTreeInsertNoR(&tree, "remove", "ɾ��");
	BSTreeInsertNoR(&tree, "interesting", "��Ȥ");
	scanf("%s", str);
	printf("%s", BSTreeFind(tree, str)->_value);
}