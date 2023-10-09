#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
int main()
{
	BTDataType arr[] = "abd##e##cf##g##";
	int i = 0;
	BTNode* newnode = BinaryTreeCreate(arr,sizeof(arr)/sizeof(BTDataType)-1,&i);
	
	printf("�ڵ� %d\n", BinaryTreeSize(newnode));
	printf("Ҷ�ӽڵ� %d\n", BinaryTreeLeafSize(newnode));
	printf("��k��ڵ� %d\n", BinaryTreeLevelKSize(newnode,5)); 
	BTNode* tmp = BinaryTreeFind(newnode, 'f');
	printf("%c �ַ�",tmp->data);
	printf("\nǰ�������");
	BinaryTreePrevOrder(newnode);
	printf("\n���������");
	BinaryTreeInOrder(newnode);
	printf("\n���������");
	BinaryTreePostOrder(newnode);
	
	printf("\n��α�����");
	BinaryTreeLevelOrder(newnode);
	printf("\n�������%d\n", TreeHeight(newnode));

	int ret = BinaryTreeComplete(newnode);
	printf("�Ƿ�Ϊ��ȫ������%d", ret);


	BinaryTreeDestory(&newnode);

	return 0;
}
