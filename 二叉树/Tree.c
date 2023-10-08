#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	
	newNode->data = a[*pi];
	(*pi)++;
	newNode->left = BinaryTreeCreate(a, n, pi);
	newNode->right = BinaryTreeCreate(a, n, pi);
	return newNode;
}
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0:BinaryTreeSize(root->left)+BinaryTreeSize(root->right)+1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->left== NULL && root->right == NULL ? 1: BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* ret = NULL;
	ret = BinaryTreeFind(root->left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf(" %c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root) 
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf(" %c ", root->data);
	BinaryTreeInOrder(root->right);

}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf(" %c ", root->data);

}
void BinaryTreeLevelOrder(BTNode* root)
{

}
