#define _CRT_SECURE_NO_WARNINGS 1

//输出所有100-999以内的3位水仙花数。
//所谓水仙花数是指所有位的数字的立方之和等于该数，例如：153 = 1^3 + 3^3 + 5^3
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	float j = 0;
//	double a, b, c;//pow()函数传double类型的值
//	for (i = 100; i <= 999; i++)//创建i循环测试每一个数
//	{
//		a = i % 10;//计算个位
//		b = (i % 100 - i % 10) / 10;//计算十位
//		c = (i % 1000 - i % 100) / 100;//计算百位
//		j = pow(a, 3) + pow(b, 3) + pow(c, 3);//计算每一位的立方和
//		if (j == i)//条件判定则输出
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//}
