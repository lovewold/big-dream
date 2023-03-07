#define _CRT_SECURE_NO_WARNINGS 1
//第 7 题（编程题）
//题目名称：
//猜凶手
//题目内容：
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:

//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//#include<stdio.h>
//int main()
//{
//	char n = 0;
//	for (n = 'a'; n <= 'd'; n++)
//	{
//		if (((n != 'a') + (n == 'c') + (n == 'd') + (n != 'd')) == 3)
//		{
//			printf("%c", n);
//		}
//	}
//
//	return 0;
//}

//在屏幕上打印杨辉三角。
//
//
//
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1
//
//……

#include<stdio.h>
int main()
{
	int arr[20][20] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;

	for (i = 0; i <= n; i++)
	{
		int count = n-i;
		for (j = 0; j < i; j++)
		{
			arr[i][0] = 1;
			arr[i][i - 1] = 1;//改变整体外壳使之为1
			
			//中间值变化
			if (i > 1&&j>0&&j<=i-1)
			{
				arr[i+1][j] = arr[i][j - 1] + arr[i][j];
			}
			while (count-- >0)
			{
				printf(" ");

			}
			printf("%2d ", arr[i][j]);

		}
		printf("\n");
	}
	return 0;
}
