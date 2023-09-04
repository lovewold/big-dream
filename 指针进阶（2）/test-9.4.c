#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//void Swap(char *p1, char *p2,int sz)
//{
//	int i = 0;
//	char tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		tmp = *p1;
//		*p1 = *p2;
//		*p2 = tmp;
//		p1++;
//		p2++;
//	}
//}
//void bubble_s(void* p, int num, int size, int (*cmp) (const void *,const void *))
//{
//	int i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < num-1-i; j++)
//		{
//			if ((cmp((char*)p + j * size,(char*)p + (j + 1) * size)>0))
//			{
//				Swap((char*)p + j * size, (char*)p + (j + 1) * size,size);
//			}
//		}
//	}
//
//
//
//}
//////比较函数
//
//int com_pare(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
////测试整形
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//}
//void test1()
//{
//	int arr1[10] = { 8,5,6,2,1,9,0,10,7,3 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	/*qsort(arr, sz, sizeof(arr[0]), com_pare);*/
//	bubble_s(arr1, sz, sizeof(arr1[0]), com_pare);
//	Print(arr1,sz);
//}
//struct stu
//{
//	char name[20];
//	int age;
//}arr;
//
//void com_pare_by_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct stu*)p1)->name, ((struct stu*)p2)->name);
//}
//
//void test2()
//{
//	struct stu arr[] = { {"zhangshang",20 },{"lishi",15},{"wangdefa",199} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//qsort(arr, sz, sizeof(arr[0]), com_pare_by_name);
//	bubble_s(arr, sz, sizeof(arr[0]), com_pare_by_name);
//	int i = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", arr[i].name);
//		printf("%d ", arr[i].age);
//
//	}
//
//}
//void com_pare_by_age(const void* p1, const void* p2)
//{
//	return ((struct stu*)p1)->age - ((struct stu*)p2)->age ;
//}
//
//void test3()
//{
//	struct stu arr[] = { {"zhangshang",20 },{"lishi",15},{"wangdefa",199} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//qsort(arr, sz, sizeof(arr[0]), com_pare_by_age);
//	bubble_s(arr, sz, sizeof(arr[0]), com_pare_by_age);
//	int i = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", arr[i].name);
//		printf("%d ", arr[i].age);
//
//	}
//
//}
//
//
//
//int main()
//{
//	test1();
//	printf("\n");
//	test2();
//	printf("\n");
//	test3();
//	return 0;
//}
//#include<stdio.h>
//int main() {
//    int n = 0;
//    int m = 0;
//    int i = 0;
//    int j = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[10][10] = { 0 };
//    int arr2[10][10] = { 0 };
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < m; j++) {
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < m; j++) {
//            scanf("%d", &arr2[i][j]);
//        }
//    }
//    for (i = 0; i <= n; i++) {
//        for (j = 0; j <= n; j++) {
//            if (arr1[i][j] != arr2[i][j]) {
//                printf("No\n");
//                goto feileishen;
//            }
//        }
//    }
//    printf("Yes\n");
//feileishen:
//
//    return 0;
//}
//字符串左旋
//作业内容
//实现一个函数，可以左旋字符串中的k个字符。
//

//#include<stdio.h>
//int main()
//{
//	char arr[20] = {0};
//	scanf("%s", &arr);
//	printf("\n%s\n", arr);
//	int k = 0;
//	printf(":>请输入左旋几个字符\n");
//	scanf("%d", &k);
//	char* p = arr;
//	printf("%s", arr + k);
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		printf("%c", p[i]);
//		
//	}
//	return 0;
//}
//例如：
//
//ABCD左旋一个字符得到BCDA2
//
//ABCD左旋两个字符得到CDAB
// 
// 
//例题
////有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
////请编写程序在这样的矩阵中查找某个数字是否存在。
//

//int Find(int arr[][4], int num, int x, int y)
//{
//	int row = 0;
//	int col = y - 1;
//	if (x == 0 || y == 0)
//	{
//		return 0;
//	}
//	 if (num >> arr[x -1][y - 1])
//	{
//		return 0;
//	}
//	 while (num >= arr[row][3])
//	 {
//		 row++;
//	 }
//	 
//	int i = 0;
//	for (i = 0; i <= col; i++)
//	{
//		if (num == arr[row][i])
//		{
//			return 1;
//		}
//			
//	}
//	return 0;
//	
//	
//	
//	
//}
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] = { {0,1,2,3},{1,2,3,4},{4,5,6,7},{6,7,8,9} };
//	int x = 4;
//	int y = 4;
//	int num = 0;
//	scanf("%d", &num);
//	if (Find(arr, num, x, y))
//	{
//		printf("存在这样的数字 %d 在矩阵中", num);
//	}
//	else 
//	{
//		printf("不存在这样的数字 %d 在矩阵中", num);
//	}
//	return 0;
////}
//#include<stdio.h>
//int main()
//{
//	int arr1[3] = { 1,2,3 };
//	int arr2[3] = { 2,3,4 };
//	int arr3[3] = { 3,4,5 };
//	int* p[3] = { &arr1,&arr2,&arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//		
//	}
//	return 0;
//}
#include <stdio.h>
#include <string.h>

//加法函数
int Add(int x, int y)
{
	return x + y;
}
//减法函数
int Sub(int x, int y)
{
	return x - y;
}
//乘法函数
int Mul(int x, int y)
{
	return x * y;
}
//除法函数
int Div(int x, int y)
{
	return x / y;
}


int main()
{
	//int (*pf1)(int, int) = Add;
	//int (*pf2)(int, int) = Sub;
	//int (*pf3)(int, int) = Mul;
	//int (*pf4)(int, int) = Div;
	//函数指针数组
	//
	int (*pfArr[4])(int, int) = {Add, Sub, Mul, Div};
	//
	return 0;
}
//
//#include <stdio.h>
//#include <string.h>
////加法函数
//int Add(int x, int y)
//{
//	return x + y;
//}
////减法函数
//int Sub(int x, int y)
//{
//	return x - y;
//}
////乘法函数
//int Mul(int x, int y)
//{
//	return x * y;
//}
////除法函数
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("***************************\n");
//	printf("*****  1.add  2.sub  ******\n");
//	printf("*****  3.mul  4.div  ******\n");
//	printf("*****  0.exit        ******\n");
//	printf("***************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//函数指针数组的方式


int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

//...

void menu()
{
	printf("***************************\n");
	printf("*****  1.add  2.sub  ******\n");
	printf("*****  3.mul  4.div  ******\n");
	printf("*****  0.exit        ******\n");
	printf("***************************\n");
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	//函数指针数组的使用 - 转移表
	int (* pfArr[5])(int, int) = {NULL, Add, Sub, Mul, Div};
	//                            0     1    2    3    4
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:");
			scanf("%d %d", &x, &y);
			ret = pfArr[input](x, y);
			printf("ret = %d\n", ret);
		}
		else if(input == 0)
		{
			printf("退出计算器\n");
		}
		else
		{
			printf("选择错误，重新选择\n");
		}
	} while (input);

	return 0;
}


int main()
{
	int* p;
	int(*pf)(int, int);

	return 0;
}

void test(const char* str)
{
	printf("%s\n", str);
}

int main()
{
	void (*pf)(const char*) = test;//pf是函数指针变量
	void (*pfArr[10])(const char*);//pfArr是存放函数指针的数组
	void (* (*p) [10])(const char*) = &pfArr;//p指向函数指针数组的指针

	return 0;
}




int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("***************************\n");
	printf("*****  1.add  2.sub  ******\n");
	printf("*****  3.mul  4.div  ******\n");
	printf("*****  0.exit        ******\n");
	printf("***************************\n");
}

void Calc(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请输入两个操作数:");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("ret = %d\n", ret);
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);

	return 0;
}