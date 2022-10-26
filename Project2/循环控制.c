#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int j = 1;
//	while (i <= 3)
//	{
//		
//		while (j <= 3)
//		{
//			
//			if (i == 2 && j == 2)
//			{
//				j++;
//				continue;
//			}
//			printf("# ");
//			j++;
//			
//		}
//		j = 1;
//		printf("\n");
//		i++;
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//0~9
	//打印数组的内容
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			continue;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");







	return 0;
}
