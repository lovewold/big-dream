#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
int main()
{
	BTDataType arr[] = "abd##e##cf##g##";
	int i = 0;
	BTNode* newnode = BinaryTreeCreate(arr,sizeof(arr)/sizeof(BTDataType)-1,&i);
	
	printf("节点 %d\n", BinaryTreeSize(newnode));
	printf("叶子节点 %d\n", BinaryTreeLeafSize(newnode));
	printf("第k层节点 %d\n", BinaryTreeLevelKSize(newnode,5)); 
	BTNode* tmp = BinaryTreeFind(newnode, 'f');
	printf("%c 字符",tmp->data);
	printf("\n前序遍历：");
	BinaryTreePrevOrder(newnode);
	printf("\n中序遍历：");
	BinaryTreeInOrder(newnode);
	printf("\n后序遍历：");
	BinaryTreePostOrder(newnode);
	
	printf("\n层次遍历：");
	BinaryTreeLevelOrder(newnode);
	printf("\n树的深度%d\n", TreeHeight(newnode));

	int ret = BinaryTreeComplete(newnode);
	printf("是否为完全二叉树%d", ret);


	BinaryTreeDestory(&newnode);

	return 0;
}
